import java.time.DayOfWeek;
import java.time.LocalDate;
public class Main {
	public static void main(String args[])
	{
		LocalDate start = LocalDate.of(1901, 1, 1);
		LocalDate end = LocalDate.of(2000, 12, 31);
		System.out.println(countSundays(start,end));
		
		
	}

	private static int countSundays(LocalDate start, LocalDate end) {
		var sundays = 0;
		while(start.compareTo(end)<=0)
		{
			if(start.getDayOfWeek().compareTo(DayOfWeek.SUNDAY)==0)
				sundays++;
			
			start = start.plusMonths(1);
		}
		return sundays;
	}
	
}
