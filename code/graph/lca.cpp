// Lowest Common Ancestor
// Status: not tested

//--- binary lifting
int n, l = ceil(log2(n));
vector<vector<int>> adj;
int tk = 0;
vector<int> tin(n), tout(n);
vector<vector<int>> up(n, vector<int>(l+1)); // ancestor

void dfs(int v, int p) { // run dfs(root, root) to initialize
	tin[v] = ++tk;
	up[v][0] = p;
	for (int i = 1; i <= l; ++i)
		up[v][i] = up[up[v][i-1]][i-1];
	for (int u : adj[v])
		if (u != p)
			dfs(u, v);
	tout[v] = ++tk;
}

bool ancestor(int v, int u) { // v is ancestor of u
	return tin[v] <= tin[u] && tout[v] >= tout[u];
}

int lca(int v, int u) {
	if (ancestor(v, u)) return v;
	if (ancestor(u, v)) return u;
	for (int i = l; i >= 0; --i)
		if (!ancestor(up[v][i], u))
			v = up[v][i];
	return up[v][0];
}

//--- euler path
using ii = pair<int, int>;
vector<ii> t;
vector<int> idx(n);
int tk = 1;

void dfs(int v, int d) { // call with dfs(root, 0);
	for (auto u : adj[v]) {
		st.update(tk, {d, v});
		tk++;
		dfs(u, d+1);
	}
	idx[v] = tk;
	st.update(tk, {d, v});
	tk++;
}

int lca(int v, int u) {
	int l = idx[v], r = idx[u];
	return st.minquery(l, r).second; // .first is depth
}
