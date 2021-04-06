/*
#include<iostream>
#include<sstream>
using namespace std;
*/

int main() {
    string A, x;
    cin >> A;
    istringstream ss(A);
    while (getline(ss, x, ',')) {
        cout << x << "\n";
    }
    return 0;
}