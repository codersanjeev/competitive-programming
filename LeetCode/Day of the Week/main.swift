class Solution {
    func dayOfTheWeek(_ day: Int, _ month: Int, _ year: Int) -> String {
    	if let date = Date.from(year: year, month: month, day: day) {
            let daysOfTheWeek = ["Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"]
    		let dayNumber = Calendar.current.component(.weekday, from: date)
         return daysOfTheWeek[dayNumber - 1]
    	} else {
    		return ""
    	}
    }
}

extension Date {

    static func from(year: Int, month: Int, day: Int) -> Date? {
        let calendar = Calendar(identifier: .gregorian)
        var dateComponents = DateComponents()
        dateComponents.year = year
        dateComponents.month = month
        dateComponents.day = day
        return calendar.date(from: dateComponents) ?? nil
    }
}
