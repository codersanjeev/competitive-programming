/**
 * This is the interface for the expression tree Node.
 * You should not remove it, and you can define some classes to implement it.
 */

class Node {
   public:
    virtual ~Node(){};
    virtual int evaluate() const = 0;

   protected:
    // define your fields here
};

class NumericNode : public Node {
   public:
    NumericNode(int val) : _val(val) {}
    int evaluate() const;

   private:
    int _val;
};

int NumericNode::evaluate() const {
    return _val;
}

class OperatorNode : public Node {
   public:
    OperatorNode(char op, Node* left, Node* right) : _op(op), _left(left), _right(right) {}
    int evaluate() const;
    ~OperatorNode();

   private:
    char _op;
    Node* const _left;
    Node* const _right;
};

OperatorNode::~OperatorNode() {
    delete _left;
    delete _right;
}

int OperatorNode::evaluate() const {
    int left = _left->evaluate();
    int right = _right->evaluate();
    int ans = 0;
    if (_op == '+') {
        ans = left + right;
    } else if (_op == '-') {
        ans = left - right;
    } else if (_op == '*') {
        ans = left * right;
    } else {
        ans = left / right;
    }
    return ans;
}

/**
 * This is the TreeBuilder class.
 * You can treat it as the driver code that takes the postinfix input 
 * and returns the expression tree represnting it as a Node.
 */

class TreeBuilder {
   public:
    Node* buildTree(vector<string>& postfix) {
        stack<Node*> st;
        for (const auto& token : postfix) {
            if (isdigit(token[0])) {
                st.push(new NumericNode(toInt(token)));
            } else {
                Node* right = st.top();
                st.pop();
                Node* left = st.top();
                st.pop();
                st.push(new OperatorNode(token[0], left, right));
            }
        }
        return st.top();
    }

   private:
    int toInt(const string& s) {
        int ans = 0;
        for (const auto& ele : s) {
            ans *= 10;
            ans += (ele - '0');
        }
        return ans;
    }
};

/**
 * Your TreeBuilder object will be instantiated and called as such:
 * TreeBuilder* obj = new TreeBuilder();
 * Node* expTree = obj->buildTree(postfix);
 * int ans = expTree->evaluate();
 */