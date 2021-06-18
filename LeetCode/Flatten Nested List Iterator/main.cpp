class NestedIterator {
   private:
    stack<NestedInteger*> nodes;

   public:
    NestedIterator(vector<NestedInteger>& nestedList) {
        for (int i = nestedList.size() - 1; i >= 0; --i) {
            nodes.push(&nestedList[i]);
        }
    }

    int next() {
        int result = nodes.top()->getInteger();
        nodes.pop();
        return result;
    }

    // only flatten the Current Level until we find an integer.
    bool hasNext() {
        while (!nodes.empty()) {
            NestedInteger* curr = nodes.top();
            // ensure the top most element is an integer not an integer list
            if (curr->isInteger()) {
                return true;
            }

            nodes.pop();

            // decouple the integer list and add the decoupled element back to stack
            vector<NestedInteger>& adjs = curr->getList();
            for (int i = adjs.size() - 1; i >= 0; --i) {
                nodes.push(&adjs[i]);
            }
        }

        return false;
    }
};