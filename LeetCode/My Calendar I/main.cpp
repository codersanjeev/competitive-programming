class MyCalendar {
   private:
    vector<pair<int, int>> bookings;

   public:
    MyCalendar() {
        bookings.clear();
    }

    bool book(int start, int end) {
        for (const auto &booking : bookings) {
            if (booking.first < end && start < booking.second) {
                return false;
            }
        }
        bookings.push_back(make_pair(start, end));
        return true;
    }
};