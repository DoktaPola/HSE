package code;

import java.util.ArrayList;

/**
 * This is the core component of the system. This class is responsible for
 * the complete orchestration of elevators and elevator requests.
 */

public class ElevatorLogic implements Runnable {
    private int floors;  // in building
    private int elevAmount;  // всего лифтов
    // STATIONARY elevators are part of UP and DOWN map both.
    private ArrayList<Elevator> elevators = new ArrayList<>();
    // people on one floor
    private ArrayList<Passenger> passengers = new ArrayList<>();
    // if there is a lack of space
    private ArrayList<Passenger> waitingList = new ArrayList<>();
    // if person higher then called elv
    private ArrayList<Passenger> upRequest = new ArrayList<>();
    // if person below then called elv
    private ArrayList<Passenger> downRequest = new ArrayList<>();

    private ArrayList<Passenger> upMoving = new ArrayList<>();
    private ArrayList<Passenger> downMoving = new ArrayList<>();

    public ElevatorLogic(int floors, int space, int elevators) {
        setFloors(floors);
        setElevAmount(elevators);
        for (int i = 0; i < elevators; i++) {
            Elevator elevator = new Elevator(i, space, 0, floors, ElevatorState.STATIONARY);
            setElevators(elevator);
        }
    }

    /* setters */
    public void setFloors(int floors) {
        this.floors = floors;
    }

    public void setElevators(Elevator elevator) {
        this.elevators.add(elevator);
    }

    public void setPassengers(Passenger passenger) {
        this.passengers.add(passenger);
    }

    public void setElevAmount(int elevAmount) {
        this.elevAmount = elevAmount;
    }

    public void setWaitingList(Passenger passenger) {
        this.waitingList.add(passenger);
    }

    /* getters */
    public int getFloors() {
        return floors;
    }

    public ArrayList<Passenger> getPassengers() {
        return passengers;
    }

    public ArrayList<Elevator> getElevators() {
        return elevators;
    }

    public int getElevAmount() {
        return elevAmount;
    }

    public ArrayList<Passenger> getWaitingList() {
        return waitingList;
    }

    public void sendPendingUsers(Elevator elv) {
        if (elv.getDirection() == ElevatorState.DOWN) {
            waitingList = upMoving;
        } else if (elv.getDirection() == ElevatorState.UP) {
            waitingList = downMoving;
        }
        while (waitingList.size() != 0 && elv.getPassengers().size() < elv.getAvailableSpace()) {
            elv.setPassengers(waitingList.get(0));
            getPassengers().remove(waitingList.get(0));
            waitingList.remove(0);
        }
    }

    public void fillInRequestedElevator(Elevator elv) {
        for (Passenger psngr : getPassengers()) {
            int floorFrom = psngr.getFloorFrom();
            int floorTo = floorFrom - psngr.getFloorTo();
            if (floorFrom > elv.getFloor())
                upRequest.add(psngr);
            else if (floorFrom < elv.getFloor())
                downRequest.add(psngr);

            if (floorFrom == elv.getFloor() && floorTo < 0) {
                upMoving.add(psngr);
            } else if (floorFrom == elv.getFloor() && floorTo > 0) {
                downMoving.add(psngr);
            }
        }
    }

    public void changeDirection(Elevator elv, int usedElvs) {
        if (elv.getPassengers().size() == 0 || elv.getFloor() == getFloors() - 1) {
            if (elv.getDirection() == ElevatorState.UP && (upRequest.size() < usedElvs * elv.getAvailableSpace()
                    || downRequest.size() < usedElvs * elv.getAvailableSpace())) {
                elv.setDirection(ElevatorState.STATIONARY);
            } else if (downRequest.size() > usedElvs * elv.getAvailableSpace()
                    || elv.getFloor() == getFloors() - 1) {
                elv.setDirection(ElevatorState.DOWN);
            }
        } else if (elv.getFloor() == 0) {
            if (upRequest.size() > usedElvs * elv.getAvailableSpace()) {
                elv.setDirection(ElevatorState.UP);
            } else {
                elv.setDirection(ElevatorState.STATIONARY);
            }
        } else {
            elv.setDirection(ElevatorState.UP);
        }

        if (elv.getDirection() == ElevatorState.STATIONARY) {
            if (upMoving.size() > downMoving.size() && upRequest.size() >
                    usedElvs * elv.getAvailableSpace()) {
                elv.setDirection(ElevatorState.UP);
            } else if (upMoving.size() <= downMoving.size()
                    && downRequest.size() > usedElvs * elv.getAvailableSpace()) {
                elv.setDirection(ElevatorState.DOWN);
            }
        }
        // if elv at roof
        if (elv.getFloor() == getFloors() - 1) {
            elv.setDirection(ElevatorState.DOWN);
        }
        // if elv on the 1st floor
        if (elv.getFloor() == 0) {
            elv.setDirection(ElevatorState.UP);
        }
    }

    public void printOutput(Elevator elv) {

        int passSizeInit = elv.getPassengers().size();
        System.out.println(">>> " + "ELV: " + elv.getElevatorNum() + " | " +
                "CURRENT FLOOR: " + elv.getFloor() + " | "
                + "PEOPLE IN ELV: " + passSizeInit + " | " + "DIRECTION: " + elv.getDirection());
    }

    @Override
    public synchronized void run() {
        int counter = 1;
        while (true) {
            System.out.println("\n\n>>> CALL: " + counter + " <<<");
            counter++;
            int usedElvs = 0;
            for (Elevator elv : getElevators()) {
                elv.move();
                // when people get destination -> go out of elv
                elv.delPassengers();
                int space = elv.getAvailableSpace() - elv.getPassengers().size();
                // if elv can accommodate passengers
                if (space > 0) {
                    // 'sort' & add requests from passengers
                    fillInRequestedElevator(elv);
                    ////////////////////////
                    changeDirection(elv, usedElvs);
                    sendPendingUsers(elv);
                } else {
                    // if elv at roof
                    if (elv.getFloor() == getFloors() - 1) {
                        elv.setDirection(ElevatorState.DOWN);
                    }
                    // if elv on the 1st floor
                    if (elv.getFloor() == 0) {
                        elv.setDirection(ElevatorState.UP);
                    }
                }

                usedElvs++;
                // print
                printOutput(elv);
            }
            try {
                Thread.sleep(2000);
            } catch (InterruptedException ex) {
                System.out.println(ex.getMessage());
            }
        }
    }
}
