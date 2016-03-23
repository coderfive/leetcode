class Solution {
public:
    vector<int> findOrder(int n, vector<pair<int, int>>& preq) {
	vector<int> state (n, 0), res;
	vector<vector<int>> graph (n, vector<int>());
	for (auto& p : preq)
	    graph[p.first].push_back(p.second);
	for (int i = 0; i < n; i++)
	    if (state[i] == 0 && !visit_node(i, state, graph, res)) return vector<int>();

	return res;
    }

    bool visit_node (int n, vector<int>& state, vector<vector<int>>& graph, vector<int>& res) {
	if (state[n] == 2) return true;
	if (state[n] == 1) return false;
	state[n] = 1;
	for (int i = 0; i < graph[n].size(); i++)
	    if (!visit_node(graph[n][i], state, graph, res)) return false;
	res.push_back(n);
	state[n] = 2;
	return true;
    }
};
