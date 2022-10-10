// Kosaraju SCC
// Usage: Tarjan(N, adj)
// not tested
// O(V+E) time & space (2 dfs calls)

int n; // number of vertices
vector<vector<int>> adj(n), adj_rev(n);
vector<bool> used(n);
vector<int> order, component;

void dfs1(int v) {
  used[v] = true;
  for (auto u: adj[v])
    if (!used[u])
      dfs1(u);
  order.push_back(v);
}

void dfs2(int v) {
  used[v] = true;
  component.push_back(v);
  for (auto u: adj_rev[v])
    if (!used[u])
      dfs2(u);
}

void kosaraju() {
  for (int i = 0; i < n; ++i)
    if (!used[i]) dfs1(i);

  used.assign(n, false);
  reverse(order.begin(), order.end());

  for (auto v: order)
    if (!used[v]) {
      dfs2(v);
      // ...process vertices in component
      component.clear();
    }
}
