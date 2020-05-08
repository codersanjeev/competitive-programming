import java.util.*;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigInteger;
public class Main {
	public static boolean isPrime(long value)
	{
		return (new BigInteger(String.valueOf(value))).isProbablePrime(1);
	}
	private static long quadraticValue(long n,long a,long b)
	{
		return (long)Math.pow(n,2) + (a * n) + b;
	}
	private static long consecutivePrimesCounter(long a,long b)
	{
		for(var n = 0; ;n++)
		{
			if(!isPrime(quadraticValue(n,a,b)))
				return n;
		}
	}
	private static List<Long> generateBPrimes(long limit)
	{
		var listPrimes = new ArrayList<Long>();
		
		for(var v = 1L;v < limit;v+=2)
		{
			if(isPrime(v))
				listPrimes.add(v);
		}
		return listPrimes;
	}
	private static long maxConsecutivePrimesSolution(long limit)
	{
		var listPrimes = generateBPrimes(limit);
		var maxProduct = 0L;
		var maxCounter = 0L;
		
		for(var a = -999;a<1000;a++)
		{
			for(var j =0;j<listPrimes.size();j++)
			{
				var b = listPrimes.get(j);
				var currCount = consecutivePrimesCounter(a,b);
				
				if(currCount > maxCounter)
				{
					maxCounter = currCount;
					maxProduct = a*b;
				}
			}
		}
		return maxProduct;
	}
	public static void main(String... args)
	{
		System.out.println(maxConsecutivePrimesSolution(1000));
	}
}
