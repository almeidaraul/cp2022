// Articulations and Bridges
// Articulation point v: if you remove vertex v, then the connected component to which it belongs becomes disconnected
// Bridge u,v: if you remove the edge u->v, then you can't reach v from u
//
// Usage: dfs(source, -1)
//
// Time: O(V + E)
// Space: O(V + E)
// Status: not tested

int tk = 0;
vector<int> tin(M, -1);
vector<vector<int>> adj(M);

void dfs(int v, int p) {
	tin[v] = low[v] = tk++;
	int children = 0;
	for (auto u: adj[v]) {
		if (u == p) continue;
		else if	(tin[u] == -1) {
			++children;
			dfs(u, v);
			if (low[u] >= tin[v] && p != v)
				; //articulation point
			if (low[u] > tin[v])
				; //bridge u-v
			low[v] = min(low[v], low[u]);
		} else {
			low[v] = min(low[v], tin[u]);
		}
	}
}
