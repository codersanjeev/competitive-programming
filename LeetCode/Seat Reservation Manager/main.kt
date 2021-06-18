class SeatManager(n: Int) {

    private val seats = sortedSetOf<Int>()

    init {
        for (i in 1 until n + 1) {
            seats.add(i)
        }
    }

    fun reserve(): Int {
        val seat = seats.first()
        seats.remove(seat)
        return seat
    }

    fun unreserve(seatNumber: Int) {
        seats.add(seatNumber)
    }

}