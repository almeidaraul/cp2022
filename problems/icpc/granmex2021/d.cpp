#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define tin first
#define idx second

using order = pair<ll, ll>;

using pq_t = priority_queue<order, vector<order>, greater<order>>;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
  int n; cin >> n;
  // uma pqueue pra cada ingrediente / funcionario
  vector<pq_t> pq(4, pq_t());
  vector<vector<ll>> specs(n, vector<ll>(4));
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < 4; ++j)
      cin >> specs[i][j];
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < 4; ++j)
      if (specs[i][j]) {
        pq[j].push(order(0, i));
        break;
      }

  ll ans = 0;
  for (int i = 0; i < 4; ++i) {
    ll clk = 0;

    while (!pq[i].empty()) {
      order t = pq[i].top(); pq[i].pop();
      ll w = specs[t.idx][i];
      // nao tem esse ingrediente
      if (!w) {
        pq[(i+1)%4].push(order(t.tin, t.idx));
        ans = max(ans, clk);
        continue;
      }
      // momento que acaba
      clk = max(clk, t.tin) + w;
      ans = max(ans, clk);
      pq[(i+1)%4].push(order(clk, t.idx));
    }
  }
  cout << ans << '\n';
}
