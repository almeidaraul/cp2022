// Edmond Karp MaxFlow
// Ford-Fulkerson's method with BFS = O(VE) BFS calls, O(E) per BFS
//
// Vertex weights: if vertex V has a weight, create Vin (receives all in-edges of V and has an edge to Vout) and Vout(receives an edge from Vin and has all out-edges of V); Vin-Vout has the weight from V
//
// MinCut: run EdmondKarp, S-T sets are: all V that you can reach from the source with edges of positive residual capacity and all other V
//
// MultiSource/MultiSink: create a super source with infinite capacity pointing to all sources, analogous for sinks
//
// Max Cardinality Bipartite Matching: use capacity 1 on all edges and apply the multi-source and multi-sink strategies
// 
// Time: O(VE^2)
// Space: O(V + E)
// Status: tested (CSES1694, CSES1695)

vector<vector<int>> capacity(M, vector<int>(M, 0)), adj(M);
vector<pair<int, int>> mc; //mincut edges

int bfs(int s, int t, vi &par) {
	fill(all(par), -1);
	par[s] = -2;
	queue<pair<int, int>> q; q.push({s, inf});
	while (!q.empty()) {
		int v = q.front().first,
				flow = q.front().second;
		q.pop();
		for (auto u: adj[v])
			if (par[u] == -1 && capacity[v][u]) {
				par[u] = v;
				int new_flow = min(flow, capacity[v][u]);
				if (u == t) return new_flow;
				q.push({u, new_flow});
			}
	}
	return 0;
}

int maxflow(int s, int t) {
	int flow = 0;
	vi par(M);
	int new_flow;
	while ((new_flow = bfs(s, t, par))) {
		flow += new_flow;
		int v = t;
		while (v != s) {
			int p = par[v];
			capacity[p][v] -= new_flow;
			capacity[v][p] += new_flow;
			v = p;
		}
	}
	return flow;
}

void mincut(int s, int t) {
	maxflow(s, t);
	stack<int> st;
	vector<bool> visited(n, false);
	vector<pair<int, int>> ans;
	st.push(0);
	while (!st.empty()) {
		int v = st.top(); st.pop();
		if (visited[v]) continue;
		visited[v] = true;
		for (auto u: adj[v])
			if (capacity[v][u] > 0)
				st.push(u);
			else
				ans.push_back({v, u});
	}
	mc.clear();
	for (auto &[v, u] : ans)
		if (!visited[u])
			mc.push_back({v, u});
}
