class MyCalendar {
	
	private var bookings: [[Int]]
	
	init() {
		bookings = [[Int]]()
	}
	
	func book(_ start: Int, _ end: Int) -> Bool {
		for booking in bookings {
			if booking[0] < end && start < booking[1] {
				return false
			}
		}
		bookings.append([start, end])
		return true
	}
}