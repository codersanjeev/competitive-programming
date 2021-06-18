#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

vector<long> riddle(vector<long> arr) {
    stack<pair<long, long>> s;
    map<long, long> m;

    arr.push_back(-1L);

    for (auto a : arr) {
        long ws = 0;
        while (!s.empty() && s.top().first > a) {
            ws += s.top().second;
            if (m.find(ws + 1) != m.end()) {
                m[ws + 1] = max(m[ws + 1], s.top().first);
            } else {
                m[ws + 1] = s.top().first;
            }
            s.pop();
            ws++;
        }

        s.push(make_pair(a, ws));
    }

    vector<long> ans;

    for (int i = 1; i < arr.size(); i++) {
        if (m.find(i) != m.end()) {
            if (!ans.empty()) {
                for (int k = 0; k <= i - 2 && m[i] > ans[i - 2 - k]; k++) {
                    ans[i - 2 - k] = m[i];
                }
            }
            ans.push_back(m[i]);
        } else {
            ans.push_back(-1L);
        }
    }
    return ans;
}

int main() {
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split_string(arr_temp_temp);

    vector<long> arr(n);

    for (int i = 0; i < n; i++) {
        long arr_item = stol(arr_temp[i]);

        arr[i] = arr_item;
    }

    vector<long> res = riddle(arr);

    for (int i = 0; i < res.size(); i++) {
        fout << res[i];

        if (i != res.size() - 1) {
            fout << " ";
        }
    }

    fout << "\n";

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
