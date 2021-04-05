int Solution::solve(string A) {
    unsigned int mask = 0;
    for (int i = 0, pos = 0; i < 4; i++) {
        int p = A.find('.', pos);
        int d = atoi(A.substr(pos, p - pos).c_str());
        pos = p + 1;
        mask = (mask << 8) | d;
    }

    int hosts = 1;
    while (!(mask & 1)) {
        hosts *= 2;
        mask >>= 1;
    }

    return hosts - 2;
}
