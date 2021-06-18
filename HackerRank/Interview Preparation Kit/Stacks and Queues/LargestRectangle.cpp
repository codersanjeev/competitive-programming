#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the largestRectangle function below.
long largestRectangle(vector<int> arr) {
    int n = arr.size();
    if (n == 0) {
        return 0;
    }
    vector<int> f(n), g(n);
    f[0] = -1;
    g[n - 1] = n;
    for (int i = 1; i < n; i++) {
        int j = i - 1;
        while (j >= 0 && arr[j] >= arr[i])
            j = f[j];
        f[i] = j;
    }
    for (int i = n - 2; i >= 0; i--) {
        int j = i + 1;
        while (j < n && arr[j] >= arr[i])
            j = g[j];
        g[i] = j;
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
        ans = max(ans, arr[i] * (g[i] - f[i] - 1));
    return ans;
}

int main() {
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string h_temp_temp;
    getline(cin, h_temp_temp);

    vector<string> h_temp = split_string(h_temp_temp);

    vector<int> h(n);

    for (int i = 0; i < n; i++) {
        int h_item = stoi(h_temp[i]);

        h[i] = h_item;
    }

    long result = largestRectangle(h);

    fout << result << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [](const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
