import java.util.*;

class Main
{
    public static void main(String args[])
    {
        Scanner sc = new Scanner(System.in);
        int t=sc.nextInt();
        for(int i=1;i<=t;i++)
        {
            int r=sc.nextInt();
            int g=sc.nextInt();
            if(r==0 || g==0)
                System.out.println("1.000000");
            else
            {
                float d=1.0f;
                float ans=0.0f, sub=1.0f;
                int c=0;
                while(r>0 && g>0)                     //
                {
                    if(c%2==0)
 		               ans+=(r*d)/((r+g)*d)*sub;
           
                    sub*=(g*d)/((r+g)*d);
                    g--;c++;
                }
            System.out.printf("%.6f\n",ans);
            }
        }
    }
}