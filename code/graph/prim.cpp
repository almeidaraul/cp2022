// Prim MST
// Status: tested (UVA10048)

vector<vector<pair<int, int>> adj(M), mst(M);
vector<bool> taken(M, false);
int cost = 0;
using iii = pair<int, pair<int, int>>;
priority_queue<iii, vector<iii, greater<iii> pq;

void process(int v) {
	taken[v] = true;
	for (auto &[w, u]: adj[v])
		if (!taken[u])
			pq.push({w, {v, u}});
}

void run(int n) {
	process(0);
	while (!pq.empty()) {
		int w = pq.top().first,
				v = pq.top().second.first,
				u = pq.top().second.second;
		pq.pop();
		if (!taken[u]) {
			mst_cost += w;
			mst[u].push_back({w, v});
			mst[v].push_back({v, w});
			process(u);
		}
	}
	for (int v = 1; v < n; ++v)
		if (!taken[v]) {
			process(v);
			run(n);
		}
}
