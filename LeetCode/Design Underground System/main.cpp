class UndergroundSystem {
   public:
    UndergroundSystem() {
    }

    void checkIn(int id, string stationName, int t) {
        checkInMap[id] = {stationName, t};
    }

    void checkOut(int id, string stationName, int t) {
        auto &checkIn = checkInMap[id];
        string route = checkIn.first + "$" + stationName;
        checkOutMap[route].first += t - checkIn.second;
        checkOutMap[route].second += 1;
    }

    double getAverageTime(string startStation, string endStation) {
        string route = startStation + "$" + endStation;
        auto &checkout = checkOutMap[route];
        return (double)checkout.first / checkout.second;
    }

   private:
    unordered_map<string, pair<int, int>> checkOutMap;
    unordered_map<int, pair<string, int>> checkInMap;
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */