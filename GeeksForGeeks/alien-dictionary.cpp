/*
url: https://practice.geeksforgeeks.org/problems/alien-dictionary/1
*/

// { Driver Code Starts
// Initial Template for C++
/* script for test case http://code.geeksforgeeks.org/PetjYq */
#include <bits/stdc++.h>

using namespace std;

string findOrder(string[], int, int);
string order;
bool f(string a, string b) {
    int p1 = 0;
    int p2 = 0;
    for (int i = 0; i < min(a.size(), b.size()) and p1 == p2; i++) {
        p1 = order.find(a[i]);
        p2 = order.find(b[i]);
        //	cout<<p1<<" "<<p2<<endl;
    }

    if (p1 == p2 and a.size() != b.size()) return a.size() < b.size();

    return p1 < p2;
}

// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        string s[n];
        for (int i = 0; i < n; i++) cin >> s[i];

        string ss = findOrder(s, n, k);
        order = "";
        for (int i = 0; i < ss.size(); i++) order += ss[i];

        string temp[n];
        std::copy(s, s + n, temp);
        sort(temp, temp + n, f);

        bool f = true;
        for (int i = 0; i < n; i++)
            if (s[i] != temp[i]) f = false;

        cout << f;
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends


// User function Template for C++

/*
dict : array of strings denoting the words in alien langauge
N : Size of the dictionary
K : Number of characters
*/

class Graph {
	int v;
	list<int> *adj;
	void topologicalSortUtil(int node, bool visited[], vector<int> &result);
public:
	Graph(int n);
	void addEdge(int v, int w);
	vector<int> topologicalSort();
};

Graph::Graph(int n) {
	v = n;
	adj = new list<int>[n];
}

void Graph::addEdge(int v, int w) {
	adj[v].push_back(w);
}

void Graph::topologicalSortUtil(int node, bool visited[], vector<int> &result) {
	visited[node] = true;
	list<int>::iterator it;
	for (it=adj[node].begin(); it!=adj[node].end(); it++) {
		if (!visited[*it])
			topologicalSortUtil(*it, visited, result);
	}
	result.push_back(node);
}

vector<int> Graph::topologicalSort() {
	bool *visited = new bool[v];
	for (int i=0; i<v; i++)	visited[i] = false;

	vector<int> result;
	for (int i=0; i<v; i++) {
		if (!visited[i]) topologicalSortUtil(i, visited, result);
	}
	// return the topological sort sequence
    return result;
}

string findOrder(string dict[], int N, int K) {
    string ans = "";
    Graph g(K);
    
    for (int i=0; i<N-1; i++) {
        for (int k=0; k<dict[i].length() && k<dict[i+1].length(); k++) {
            // if not equal, then put in set
            char v = dict[i][k];
            char w = dict[i+1][k];
            if (v != w) {
                g.addEdge(v-'a', w-'a');
                // break and move to next pair
                break;
            }
        }
    }

    vector<int> topologicalSort = g.topologicalSort();
	for (int i=topologicalSort.size()-1; i>=0; i--) {
        string temp(1, (char)(topologicalSort[i]+'a'));
        ans += temp;
	}
    return ans;
}
