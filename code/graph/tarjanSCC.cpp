// Tarjan Strongly Connected Component
// Usage: Tarjan(N, adj)
// Status: tested (UVA247, UVA11838)

vector<int> tin(M, -1), low(M, -1);
vector<vector<int> adj(M);
stack<int> S;
int tk = 0;

void dfs(int v) {
	low[v] = tin[v] = tk++;
	S.push(v);
	visited[v] = true;
	for (auto u: adj[v]) {
		if (tin[u] == -1)
			dfs(u);
		if (visited[u])
			low[v] = min(low[v], low[u]);
	}
	if (low[v] == tin[v])
		while (true) {
			int u = S.top(); S.pop(); visited[u] = false;
			if (u == v) break;
		}
}
