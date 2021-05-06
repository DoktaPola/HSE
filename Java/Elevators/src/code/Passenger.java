package code;

public class Passenger {
    private int passId;  // 'name'
    private int floorFrom; // откуда
    private int floorTo; // куда

    Passenger(int passId, int currentFloor, int destinationFloor) {
        setPassId(passId);
        setCurrentFloor(currentFloor);
        setDestinationFloor(destinationFloor);
    }

    /* setters */
    public void setPassId(int passId) {
        this.passId = passId;
    }

    public void setCurrentFloor(int floorFrom) {
        this.floorFrom = floorFrom;
    }

    public void setDestinationFloor(int floorTo) {
        this.floorTo = floorTo;
    }

    /* getters */
    public int getPassId() {
        return passId;
    }

    public int getFloorFrom() {
        return floorFrom;
    }

    public int getFloorTo() {
        return floorTo;
    }
}
