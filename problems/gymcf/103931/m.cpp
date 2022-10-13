#include <bits/stdc++.h>
using namespace std;
using ll = long long;

/*
 * faz a mesma coisa sóq ue com grafo condensado, aí n tem ciclo.
 * cada vértice do grafo condensado tem um "peso" (número de vértices nele)
 * aí a resposta pra cada vértice vai ser:
 * (somatorio de todo vertice denso acessivel * o numero de vertices nele) - 1
 * (incluindo o vertice denso ao qual ele pertence)
 */

// cada valor é copiado logn vezes pelo trick do swap: O(nlogn)
// + dfs: O(n + m)
// O(nlogn + n + m)

vector<vector<size_t>> adj(500001, vector<size_t>()), adj_rev(500001, vector<size_t>());
vector<bool> used(500001);
vector<size_t> order, component;
vector<size_t> rep(500001);
vector<vector<size_t>> sccs;
vector<set<size_t>> adj_sccs(500001, set<size_t>());
vector<size_t> ans (500001);

void dfs1(size_t v) { // kosaraju 1 (no grafo normal)
  used[v] = true;
  for (auto u: adj[v])
    if (!used[u])
      dfs1(u);
  order.push_back(v);
}

void dfs2(size_t v) { // kosaraju 2 (no grafo transposto)
  used[v] = true;
  component.push_back(v);
  for (auto u: adj_rev[v])
    if (!used[u])
      dfs2(u);
}

void dfs(size_t c) { // dfs pra computar a resposta (em cima dos sccs)
  used[c] = true;
  ans[c] = sccs[c].size();
  for (auto u: adj_sccs[c]) {
    if (!used[u])
      dfs(u);
    ans[c] += ans[u];
  }
}

int main() {
	ios_base::sync_with_stdio(0);
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; ++i) {
    int prev; cin >> prev;
    prev--;
    for (int j = 1; j < n; ++j) {
      int nxt; cin >> nxt;
      nxt--;
      adj[prev].push_back(nxt);
      adj_rev[nxt].push_back(prev);
      prev = nxt;
    }
  }
  for (int i = 0; i < n; ++i)
    if (!used[i]) dfs1(i);

  used.assign(n, false);
  for (auto vit = order.rbegin(); vit < order.rend(); ++vit) {
    size_t v = *vit;
    if (!used[v]) {
      dfs2(v);
      for (auto u: component) {
        rep[u] = sccs.size();
      }
      sccs.push_back(component);
      component.clear();
    }
  }
  
  for (size_t s = 0; s < sccs.size(); ++s)
    for (auto v: sccs[s])
      for (auto u: adj[v])
        if (rep[u] != s)
          adj_sccs[s].insert(rep[u]);

  used.assign(n, false);
  for (size_t i = 0; i < sccs.size(); ++i)
    if (!used[i]) dfs(i);

  for (int i = 0; i < n; ++i) {
    cout << ans[rep[i]]-1 << ' ';
  }
  cout << '\n';
}
