bool solve(string s) {
    int score = 0;
    for (const auto &ch : s) {
        if (ch == '(')
            score += 1;
        else {
            if (score <= 0)
                return false;
            else
                score -= 1;
        }
    }
    return score == 0;
}