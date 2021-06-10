class MyCalendar() {

    private var bookings = ArrayList<Pair<Int, Int>>()

    fun book(start: Int, end: Int): Boolean {
        for (booking in bookings) {
            if (booking.first < end && start < booking.second) {
                return false
            }
        }
        bookings.add(Pair(start, end))
        return true
    }

}
