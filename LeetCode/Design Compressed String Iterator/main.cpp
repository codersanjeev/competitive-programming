class StringIterator {
   public:
    StringIterator(string compressedString) {
        this->compressedString = compressedString;
        this->index = this->count = 0;
        this->curr = ' ';
    }

    char next() {
        if (count == 0) {
            if (index >= compressedString.size()) {
                return ' ';
            }
            curr = compressedString[index++];
            while (index < compressedString.size() && compressedString[index] >= '0' && compressedString[index] <= '9') {
                count = (count * 10) + (compressedString[index++] - '0');
            }
        }
        count--;
        return curr;
    }

    bool hasNext() {
        return index < compressedString.size() || count != 0;
    }

   private:
    string compressedString;
    char curr;
    int count, index;
};

/**
 * Your StringIterator object will be instantiated and called as such:
 * StringIterator* obj = new StringIterator(compressedString);
 * char param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */