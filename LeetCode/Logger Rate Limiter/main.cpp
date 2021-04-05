class Logger {
   public:
    /** Initialize your data structure here. */
    Logger() {
        mp.clear();
    }

    /** Returns true if the message should be printed in the given timestamp, otherwise returns false.
        If this method returns false, the message will not be printed.
        The timestamp is in seconds granularity. */
    bool shouldPrintMessage(int timestamp, string message) {
        if (mp.find(message) == mp.end()) {
            mp[message] = timestamp;
            return true;
        }
        int previousTimestamp = mp[message];
        if (timestamp - previousTimestamp >= 10) {
            mp[message] = timestamp;
            return true;
        } else {
            return false;
        }
    }

   private:
    unordered_map<string, int> mp;
};

/**
 * Your Logger object will be instantiated and called as such:
 * Logger* obj = new Logger();
 * bool param_1 = obj->shouldPrintMessage(timestamp,message);
 */