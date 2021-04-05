import java.io.*;
import java.util.*;

public class Main
{
	public static void main(String[] args) throws IOException
	{
	    Scanner sc = new Scanner(System.in);
	    int t;
	    t = sc.nextInt();
	    for(int i=0; i<t; i++){
	        String x = sc.next();
	        StringBuilder builder = new StringBuilder();
	        char[] xArray = x.toCharArray();
	        for(int j=0; j<xArray.length; j++){
	            char c = xArray[j];
	            if(j == 0){
	            	builder.append(c);
	            }
	            else if(c != builder.toString().charAt(builder.toString().length()-1)){
	            	builder.append(c);
	            }
	        }
	        System.out.println(builder.toString());
	    }
		
	}
}
