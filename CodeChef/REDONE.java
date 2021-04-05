import java.util.*;
import java.lang.*;
import java.io.*;

class Codechef
{
	public static void main (String[] args) throws java.lang.Exception,IOException
	{
		try {
		    Scanner in = new Scanner(System.in);
		    int t=in.nextInt();
		    long  dp[]=new long[1000001];
		    dp[0]=0;
		    dp[2]=5;
		    dp[1]=1;
	    
	    for(int i=3;i<1000001;i++)
	    {
	        long a=dp[i-1]%1000000007;
	        long x=(a*i)%1000000007;
	        long y=(((a+i)%1000000007)+x)%(1000000007);
	        dp[i]=y%1000000007;
	        
	    }
	    
		    while(t-->0){
		        int n=in.nextInt();
		        System.out.println(String.valueOf(dp[n]));
		    }
		} catch(Exception e) {
		}
	}
}