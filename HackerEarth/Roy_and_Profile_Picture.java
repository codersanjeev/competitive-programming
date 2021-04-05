import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

class Roy_and_Profile_Picture {
    public static void main(String args[] ) throws Exception {

        Scanner s = new Scanner(System.in);
        int l, n, w, h;
        l = s.nextInt();
        n = s.nextInt();
        while(n != 0){
            w = s.nextInt();
            h = s.nextInt();
            if (w < l || h < l)
                System.out.println("UPLOAD ANOTHER");
            else if(w == h)
                System.out.println("ACCEPTED");
            else 
                System.out.println("CROP IT");
            n--;
        }
    }
}
