package code;

import java.util.ArrayList;

public class Elevator {
    private int elevatorNum;
    private int availableSpace;
    private int floor;
    private int floorsAmount; // in building
    private ElevatorState direction;
    private ArrayList<Passenger> passengers = new ArrayList<Passenger>();

    Elevator(int elevatorNum, int availableSpace,
             int floor, int floorsAmount,
             ElevatorState direction) {
        setElevatorNum(elevatorNum);
        setAvailableSpace(availableSpace);
        setFloor(floor);
        setFloorsAmount(floorsAmount);
        setDirection(direction);
    }

    /* setters */
    public void setElevatorNum(int elevatorNum) {
        this.elevatorNum = elevatorNum;
    }

    public void setAvailableSpace(int availableSpace) {
        this.availableSpace = availableSpace;
    }

    public void setFloor(int floor) {
        this.floor = floor;
    }

    public void setFloorsAmount(int floorsAmount) {
        this.floorsAmount = floorsAmount;
    }

    public void setDirection(ElevatorState direction) {
        this.direction = direction;
    }

    public void setPassengers(Passenger passenger) {
        this.passengers.add(passenger);
    }

    /* getters */
    public int getElevatorNum() {
        return elevatorNum;
    }

    public int getAvailableSpace() {
        return availableSpace;
    }

    public int getFloor() {
        return floor;
    }

    public ElevatorState getDirection() {
        return direction;
    }

    public ArrayList<Passenger> getPassengers() {
        return passengers;
    }

    public int getFloorsAmount() {
        return floorsAmount;
    }

    /* funcs */
    public void move() {
        if (getDirection() == ElevatorState.UP) {
            setFloor(getFloor() + 1);
        } else if (getDirection() == ElevatorState.DOWN) {
            setFloor(getFloor() - 1);
        } else {
            setFloor(getFloor());
        }
    }

    public void delPassengers() {
        getPassengers().removeIf(passenger -> (passenger.getFloorTo() == getFloor()));
    }
}
