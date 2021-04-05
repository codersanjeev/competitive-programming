class Codec {
   public:
    string serialize(Node *root) {
        ostringstream ss;
        encode(root, ss);
        return ss.str();
    }

    Node *deserialize(string data) {
        istringstream ss(data);
        return decode(ss);
    }

   private:
    void encode(Node *root, ostringstream &ss) {
        if (root == nullptr) {
            return;
        }
        ss << " " << root->val << " " << root->children.size();
        for (const auto &v : root->children) {
            encode(v, ss);
        }
    }

    Node *decode(istringstream &ss) {
        ss.peek();
        if (ss.eof()) {
            return nullptr;
        }
        Node *root = new Node();
        int children;
        ss >> root->val >> children;
        while (children--) {
            root->children.push_back(decode(ss));
        }
        return root;
    }
};