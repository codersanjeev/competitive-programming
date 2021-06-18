#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int nq;
    cin >> nq;

    // first will contain <element, frequency> pairs
    map<int, int> first;
    // second will contain <frequency, frequencyCount> pairs
    map<int, int> second;

    for (int i = 0; i < nq; i++) {
        int a, b;

        cin >> a >> b;

        if (a == 1) {
            // Insert b into first map.
            // Update the frequencies in second map.
            int elem = first[b];  // ele = current frequency of element b.

            if (elem > 0) {
                // b was already present.
                second[elem]--;
            }

            // Add b
            // increase frequency of b
            first[b]++;

            // Update the count of new frequency in second map
            second[first[b]]++;
        }

        else if (a == 2) {
            // Remove b
            int temp = first[b];  // temp = current frequency of element b
            if (temp > 0) {
                // b is present
                second[temp]--;      // Update frequency count
                first[b]--;          // decrease element frequency
                second[first[b]]++;  // Update frequency count
            }
        } else {
            // check for the b frequency of any element
            int res = second[b];
            if (res > 0) {
                cout << 1 << endl;
            } else {
                cout << 0 << endl;
            }
        }
    }
    return 0;
}
