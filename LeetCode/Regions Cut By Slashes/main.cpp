class DSU {
    vector<int> parent;
    vector<int> rank;

   public:
    DSU(int n) {
        parent.resize(n, -1);
        rank.resize(n, 1);
    }

    int find(int u) {
        if (parent[u] == -1) {
            return u;
        } else {
            return parent[u] = find(parent[u]);
        }
    }

    void merge(int u, int v) {
        int a = find(u);
        int b = find(v);
        if (a != b) {
            if (rank[a] < rank[b]) {
                parent[a] = b;
                rank[b] += rank[a];
            } else {
                parent[b] = a;
                rank[a] += rank[b];
            }
        }
    }

    int numberOfConnectedComponents() {
        unordered_set<int> ans;
        for (int i = 0; i < parent.size(); ++i) {
            ans.insert(find(i));
        }
        return ans.size();
    }
};

class Solution {
   private:
    int N;

    int getBoxNumber(int i, int j) {
        return (i * N) + j;
    }

    vector<int> getNodeNumbers(int box) {
        return vector<int>{4 * box, (4 * box) + 1, (4 * box) + 2, (4 * box) + 3};
    }

   public:
    int regionsBySlashes(vector<string> &grid) {
        N = grid.size();
        DSU *dsu = new DSU(4 * N * N);
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                int currBoxNumber = getBoxNumber(i, j);
                vector<int> currBoxNodeNumbers = getNodeNumbers(currBoxNumber);
                if (grid[i][j] == ' ') {
                    dsu->merge(currBoxNodeNumbers[0], currBoxNodeNumbers[1]);
                    dsu->merge(currBoxNodeNumbers[1], currBoxNodeNumbers[2]);
                    dsu->merge(currBoxNodeNumbers[2], currBoxNodeNumbers[3]);
                } else if (grid[i][j] == '\\') {
                    dsu->merge(currBoxNodeNumbers[0], currBoxNodeNumbers[1]);
                    dsu->merge(currBoxNodeNumbers[2], currBoxNodeNumbers[3]);
                } else {
                    dsu->merge(currBoxNodeNumbers[0], currBoxNodeNumbers[3]);
                    dsu->merge(currBoxNodeNumbers[1], currBoxNodeNumbers[2]);
                }
                if (i + 1 < N) {
                    int bottomBoxNumber = getBoxNumber(i + 1, j);
                    vector<int> bottomBoxNodeNumbers = getNodeNumbers(bottomBoxNumber);
                    dsu->merge(currBoxNodeNumbers[2], bottomBoxNodeNumbers[0]);
                }
                if (i - 1 >= 0) {
                    int topBoxNumber = getBoxNumber(i - 1, j);
                    vector<int> topBoxNodeNumbers = getNodeNumbers(topBoxNumber);
                    dsu->merge(currBoxNodeNumbers[0], topBoxNodeNumbers[2]);
                }
                if (j + 1 < N) {
                    int rightBoxNumber = getBoxNumber(i, j + 1);
                    vector<int> rightBoxNodeNumbers = getNodeNumbers(rightBoxNumber);
                    dsu->merge(currBoxNodeNumbers[1], rightBoxNodeNumbers[3]);
                }
                if (j - 1 >= 0) {
                    int leftBoxNumber = getBoxNumber(i, j - 1);
                    vector<int> leftBoxNodeNumbers = getNodeNumbers(leftBoxNumber);
                    dsu->merge(currBoxNodeNumbers[3], leftBoxNodeNumbers[1]);
                }
            }
        }
        return dsu->numberOfConnectedComponents();
    }
};