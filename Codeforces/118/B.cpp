#include <iostream>
using namespace std;
int main() {
    int n, i, j, k;
    cin >> n;
    for (i = 1; i <= 2 * n + 1; i++) {
        if (i <= n + 1) {
            for (j = 1; j <= 2 * n - 2 * (i - 1); j++) {
                cout << " ";
            }
            k = 0;
            for (j = 1; j <= 2 * i - 1; j++) {
                if (j <= i) {
                    if ((i == 1 || i == 2 * n + 1) && j == 1) {
                        cout << "0";
                    } else
                        cout << k << " ";
                    if (j != i)
                        k++;
                } else {
                    k--;
                    if (j != 2 * i - 1)
                        cout << k << " ";
                    else
                        cout << k;
                }
            }
        } else {
            for (j = 1; j <= 2 * (i - n - 1); j++) {
                cout << " ";
            }
            k = 0;
            for (j = 1; j <= 2 * (2 * n + 2 - i) - 1; j++) {
                if (j <= 2 * n + 2 - i) {
                    if ((i == 1 || i == 2 * n + 1) && j == 1) {
                        cout << "0";
                    } else
                        cout << k << " ";
                    if (j != 2 * n + 2 - i)
                        k++;
                } else {
                    k--;
                    if (j != 2 * (2 * n + 2 - i) - 1)
                        cout << k << " ";
                    else
                        cout << k;
                }
            }
        }
        cout << endl;
    }
    return 0;
}