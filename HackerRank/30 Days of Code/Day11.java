import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Solution {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int arr[][] = new int[6][6];
        for(int i=0; i < 6; i++){
            for(int j=0; j < 6; j++){
                arr[i][j] = in.nextInt();
            }
        }
        List<Integer> sum = new ArrayList<>();
        int ele = 0;
        for(int i=0; i<=3; i++){
            ele = arr[i][0] + arr[i][1] +arr[i][2] + arr[i+1][1] + arr[i+2][0] + arr[i+2][1] +arr[i+2][2];
            sum.add(ele);
        }
        for(int i=0; i<=3; i++){
            ele = arr[i][3] + arr[i][1] +arr[i][2] + arr[i+1][2] + arr[i+2][3] + arr[i+2][1] +arr[i+2][2];
            sum.add(ele);
        }
        for(int i=0; i<=3; i++){
            ele = arr[i][2] + arr[i][3] +arr[i][4] + arr[i+1][3] + arr[i+2][2] + arr[i+2][3] +arr[i+2][4];
            sum.add(ele);
        }
        for(int i=0; i<=3; i++){
            ele = arr[i][3] + arr[i][4] +arr[i][5] + arr[i+1][4] + arr[i+2][3] + arr[i+2][4] +arr[i+2][5];
            sum.add(ele);
        }
        System.out.println(Collections.max(sum));
    }
}
