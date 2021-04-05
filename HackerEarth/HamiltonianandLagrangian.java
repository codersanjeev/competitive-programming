import java.util.ArrayList;
import java.util.Scanner;

public class HamiltonianandLagrangian {
    public static void main(String[] args){
        int n, ele;
        ArrayList<Integer> arr = new ArrayList<>();
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        for(int i=0; i<n; i++){
            ele = sc.nextInt();
            arr.add(ele);
        }
        for(int i=0; i<n-1; i++){
            boolean flag = false;
            ele = arr.get(i);
            for(int j=i+1; j<n; j++) {
                if (!(ele < arr.get(j))) {
                    flag = true;
                }
                else{
                    flag = false;
                    break;
                }
            }
            if(flag){
                System.out.print(ele + " ");
            }
        }
        System.out.println(arr.get(n-1));
    }
}
