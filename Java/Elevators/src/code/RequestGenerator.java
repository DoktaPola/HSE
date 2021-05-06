package code;

import java.util.Random;

/**
 * Represents a request for an user to use the elevators
 */
public class RequestGenerator implements Runnable {
    private int floorsAmount; // amount of floors in building
    private ElevatorLogic elevatorLogic;

    public RequestGenerator(int floorsAmount, ElevatorLogic elevatorLogic) {
        setFloorsAmount(floorsAmount);
        setElevatorLogic(elevatorLogic);
    }

    /* setters */
    public void setFloorsAmount(int floorsAmount) {
        this.floorsAmount = floorsAmount;
    }

    public void setElevatorLogic(ElevatorLogic elevatorLogic) {
        this.elevatorLogic = elevatorLogic;
    }

    /* getters */
    public int getFloorsAmount() {
        return floorsAmount;
    }

    public ElevatorLogic getElevatorLogic() {
        return elevatorLogic;
    }

    @Override
    public void run() {
        while (true) {
            // generators for floors(to/from)
            Random random = new Random();
            // people on floor
            int minPeople = 1;
            int maxPeople = 10;
            int diff = maxPeople - minPeople;
            int peopleAmount = random.nextInt(diff + 1);
            // initial floor
            int floorFrom = random.nextInt(floorsAmount);
            for (int i = 0; i < peopleAmount; i++) {
                // target floor
                int floorTo = random.nextInt(floorsAmount);
                while (floorFrom == floorTo) {
                    floorTo = random.nextInt(floorsAmount);
                }
                Passenger passenger = new Passenger(i, floorFrom, floorTo);
                // add passenger to array
                getElevatorLogic().setPassengers(passenger);
            }
            try {
                Thread.sleep(2000); // Let people get off the elevator :P
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }
}
