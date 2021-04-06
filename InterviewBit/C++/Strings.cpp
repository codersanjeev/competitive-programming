/*
#include<iostream>
#include<string>
using namespace std;
*/

int main() {
    string A, B;
    cin >> A >> B;
    // YOUR CODE GOES HERE
    int N = A.size(), M = B.size();
    cout << N << " " << M << "\n";
    cout << A + B << "\n";
    swap(A[0], B[0]);
    cout << A << " " << B;
    return 0;
}