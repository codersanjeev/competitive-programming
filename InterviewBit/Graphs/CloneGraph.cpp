/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
UndirectedGraphNode *Solution::cloneGraph(UndirectedGraphNode *node) {
	map<UndirectedGraphNode *, UndirectedGraphNode *> mp;
	queue<UndirectedGraphNode *> q;
	q.push(node);
	mp[node] = new UndirectedGraphNode(node->label);
	while (!q.empty()) {
		UndirectedGraphNode *temp = q.front();
		q.pop();
		vector<UndirectedGraphNode *> v(temp->neighbors);
		for (int i = 0; i < v.size(); i++) {
			if (mp.find(v[i]) == mp.end()) {
				UndirectedGraphNode *copy = new UndirectedGraphNode(v[i]->label);
				mp[v[i]] = copy;
				q.push(v[i]);
			}
			mp[temp]->neighbors.push_back(mp[v[i]]);
		}
	}
	return mp[node];
}
