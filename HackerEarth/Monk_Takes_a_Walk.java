import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

class Monk_Takes_a_Walk {
    public static void main(String args[] ) throws Exception {
        Scanner s = new Scanner(System.in);
        int t = s.nextInt();
	    for(int i=0; i<t; i++){
	        String st = s.nextLine();
	        int length = st.length();
	        int count = 0;
	        for(int j=0; j<length; j++){
	            char c = st.charAt(j);
	            if(c == 'a' || c=='e' || c=='i' || c=='o' || c=='u' || c == 'A' || c=='E' || c=='I' || c=='O' || c=='U'){
	                count += 1;
	            }
	        }
	        System.out.println(count);
	    }
    }
}
