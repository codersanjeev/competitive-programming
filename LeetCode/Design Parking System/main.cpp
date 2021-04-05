class ParkingSystem {
   public:
    ParkingSystem(int big, int medium, int small) {
        parking.resize(3);
        parking[0] = big;
        parking[1] = medium;
        parking[2] = small;
    }

    bool addCar(int carType) {
        carType--;
        if (parking[carType] == 0) {
            return false;
        } else {
            parking[carType]--;
            return true;
        }
    }

   private:
    vector<int> parking;
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */