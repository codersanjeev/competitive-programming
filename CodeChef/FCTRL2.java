import java.math.*;
import java.lang.*;
import java.util.*;

public class main{

	static BigInteger func(int n){
		BigInteger b = new BigInteger("1");
		for(int i = 2; i <= n; i++)
			b = b.multiply(BigInteger.valueOf(i));
		return b;
	}

	public static void main(String[] args){

		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		for(int i = 0; i < t; i++){
			int n = sc.nextInt();
			System.out.println(func(n));
		}

	}

}