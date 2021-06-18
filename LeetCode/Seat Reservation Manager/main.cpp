class SeatManager {
   public:
    SeatManager(int n) {
        seats.clear();
        for (int i = 1; i <= n; i++) seats.insert(i);
    }

    int reserve() {
        auto it = seats.begin();
        int ans = *it;
        seats.erase(it);
        return ans;
    }

    void unreserve(int seatNumber) {
        seats.insert(seatNumber);
    }

   private:
    set<int> seats;
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */