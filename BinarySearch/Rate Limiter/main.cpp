class RateLimiter {
  public:

	int expire;
	unordered_map<int, int> logs;

	RateLimiter(int expire) {
		this->expire = expire;
	}

	bool limit(int uid, int timestamp) {
		int prev = INT_MAX;
		if (logs.find(uid) != logs.end()) {
			prev = logs[uid];
		}
		if (prev != INT_MAX && timestamp - prev < expire) {
			return true;
		} else {
			logs[uid] = timestamp;
			return false;
		}
	}
};