#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        long mn = 1000000-1;
        long ans = 0;
        vector <long> A,B;
        for(int i=0;i<2*1000000;i++)
        {
            A.push_back(0);
            B.push_back(0);
        }
        long n,a,b;
        cin >> n;
        for(int i=0;i<n;i++)
        {
            cin >> a >> b;
            A[mn+b-a]++;
            B[a+b-2]++;
        }
 
        for(int i=0;i<2*1000000;i++)
            ans = ans + (A[i]*(A[i]-1))/2 + (B[i]*(B[i]-1))/2;
 
        cout << ans << endl;;
    }
    return 0;
}