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

vector<vector<int>> adj(50101, vector<int>()), adj_rev(50101, vector<int>());
vector<bool> used(50101);
vector<int> order, component;
vector<int> rep(50101);
vector<vector<int>> sccs;
vector<set<int>> adj_sccs(50101, set<int>());
vector<int> ans (50101);
int tik = 0;

void dfs1(int v) { // kosaraju 1 (no grafo normal)
  used[v] = true;
  for (auto u: adj[v])
    if (!used[u])
      dfs1(u);
  order.push_back(v);
}

void dfs2(int v) { // kosaraju 2 (no grafo transposto)
  used[v] = true;
  component.push_back(v);
  for (auto u: adj_rev[v])
    if (!used[u])
      dfs2(u);
}

void dfs(int c) { // dfs pra computar a resposta (em cima dos sccs)
  used[c] = true;
  ans[c] = sccs[rep[c]].size();
  for (auto u: adj_sccs[c]) {
    if (!used[u])
      dfs(u);
    ans[c] += sccs[rep[u]].size();
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
      prev = nxt;
    }
  }
  for (int i = 0; i < n; ++i)
    if (!used[i]) dfs1(i);

  used.assign(n, false);
  reverse(order.begin(), order.end());

  for (auto v: order)
    if (!used[v]) {
      dfs2(v);
      tik++;
      for (auto u: component) {
        rep[u] = sccs.size();
      }
      sccs.push_back(component);
      component.clear();
    }
  
  for (int s = 0; s < sccs.size(); ++s) {
    for (auto v: sccs[s])
      for (auto u: adj[v])
        adj_sccs[s].insert(rep[u]);
  }

  used.assign(sccs.size(), false);
  for (int i = 0; i < sccs.size(); ++i)
    if (!used[i]) dfs(i);

  for (int i = 0; i < n; ++i) {
    cout << ans[i]-1 << ' ';
  }
  cout << '\n';
}
