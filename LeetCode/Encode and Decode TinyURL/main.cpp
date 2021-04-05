class Solution {
   public:
    string encode(const string &url) {
        string code = "";
        if (urlCode.count(url) == 0) {
            for (int i = 0; i < 6; i++) {
                code += CHARS[rand() % CHARS.size()];
            }
            urlCode[url] = code;
            codeUrl[code] = url;
        } else {
            code = urlCode[url];
        }
        return code;
    }

    string decode(const string &code) {
        return (codeUrl.count(code) == 0 ? "" : codeUrl[code]);
    }

   private:
    const string CHARS = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    unordered_map<string, string> urlCode, codeUrl;
};