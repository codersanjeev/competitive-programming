int Solution::atoi(const string s) {
    int n = s.size(), i = 0, ans = 0, p = 1;
    while (i < n && s[i] == ' ') {
        i++;
    }
    bool positive = true;
    if (s[i] == '-') {
        positive = false;
        i++;
    } else if (s[i] == '+') {
        positive = true;
        i++;
    }
    for (int j = i; j < n; j++) {
        if (s[j] < '0' || s[j] > '9') {
            break;
        }
        if (ans > (INT_MAX / 10) || (ans == (INT_MAX / 10) && (s[j] - '0') > (INT_MAX % 10))) {
            return positive ? INT_MAX : INT_MIN;
        }
        ans = (ans * 10) + (s[j] - '0');
    }
    return positive ? ans : -ans;
}
