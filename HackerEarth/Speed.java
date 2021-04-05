import java.util.*;

class TestClass {
    public static void main(String args[] ) throws Exception {
        Scanner input = new Scanner(System.in);
        int t=input.nextInt();
        for(int i=0;i<t;i++)
        {
            int c=input.nextInt();
            int arr[]=new int[100000];
            int count=0;
            for(int j=0;j<c;j++)
            {
                arr[j]=input.nextInt();
            }
            for(int j=1;j<c;j++)
            {
                if(arr[j-1]<=arr[j])
                    arr[j]=arr[j-1];
            }
            for(int j=1;j<c;j++)
            {
                if(arr[j-1]>arr[j])
                    count++;
            }
            System.out.println((count+1));
        }
    }
}