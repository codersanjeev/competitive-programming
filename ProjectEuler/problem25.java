import java.util.*;
import java.math.BigInteger;

public class Main {
	public static void main(String args[])
	{
		BigInteger a = new BigInteger("1");
		BigInteger b = new BigInteger("2");
		BigInteger c = a.add(b);
		var i = 4L;
		
		while(c.toString().length() < 1000)
		{
			
			a = b;
			b = c;
			c = a.add(b);
			i++;
		}
		System.out.println(i);
	}
}

	

