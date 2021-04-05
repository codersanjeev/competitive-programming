/**
 * The read4 API is defined in the parent class Reader4.
 *     int read4(char *buf4);
 */

class Solution {
   public:
    /**
     * @param buf Destination buffer
     * @param n   Number of characters to read
     * @return    The number of actual characters read
     */
    int read(char *buf, int n) {
        int x = 0, y = 4;
        while (x < n && y == 4) {
            y = read4(buf + x);
            x += y;
        }
        return min(n, x);
    }
};