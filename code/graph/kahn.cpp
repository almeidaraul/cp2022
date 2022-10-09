// Kahn's topological sort
// particular order (alphabetical)
// Time: O(VE)
// Space: O(V+E)
// Status: tested (UVA11060)

vector<vector<int>> adj(M);
vector<int> sorted;

void kahn(int n) {
	vector<int> indeg(n, 0);
	vector<bool> valid(n, true);
	priority_queue<int> pq;
	
	for (int v = 0; v < n; ++v)
		for (auto u: adj[v])
			indeg[u]++;
	for (int v = 0; v < n; ++v)
		if (!indeg[v]) pq.push(v);

	while (!pq.empty()) {
		int v = pq.top(); pq.pop();
		sorted.push_back(v);
		valid[v] = false;
		for (auto u: adj[v])
			if (valid[u] && !(--indeg[u]))
				pq.push(u);
	}
}
