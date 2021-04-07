/*
#include<iostream>
using namespace std;
*/

void solve(int *A, int *B) {
    int x = *A + *B;
    int y = *A - *B;
    if (y < 0) y = -y;
    *A = x;
    *B = y;
}

/*
int main()  {
    int A, B;
    int *pA = &A, *pB = &B;
    cin>>A>>B;
    solve(pA, pB);
    cout<<A<<endl;
    cout<<B<<endl;
    return 0;
}
*/