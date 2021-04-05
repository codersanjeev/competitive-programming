int getRev(int n) {
    int rev = 0;
    while (n != 0) {
        rev |= (n & 1);
        n >>= 1;
        rev <<= 1;
    }
    rev >>= 1;
    return rev;
}

int Solution::solve(int n) {
    int cnt = 1, len = 1;
    while (cnt < n) {
        len++;
        cnt += (1 << (len - 1) / 2);
    }
    cnt -= (1 << (len - 1) / 2);
    int offset = n - cnt - 1;
    int ans = (1 << (len - 1));
    ans |= (offset << (len / 2));
    int valFor = (ans >> (len / 2));
    int rev = getRev(valFor);
    ans |= rev;
    return ans;
}
