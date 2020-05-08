import java.util.*;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigInteger;
public class Main {
	public static void main(String args[])
	{
		
		var zero = new BigInteger("0");
		var one = new BigInteger("1");
		var two = new BigInteger("2");
		var ten = new BigInteger("10");
		var base = two;
		var result = new BigInteger("100");
		var fact = one;
		
		while(result.intValue() > 0)
		{
			fact = fact.multiply(result);
			result = result.subtract(one);
		}
		
		
		var sum = zero;
		while(fact.compareTo(zero) > 0)
		{
			sum = sum.add(fact.mod(ten));
			fact = fact.divide(ten);
		}
		System.out.println(sum);
	}
	
}
