#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
  int n;
  cin >> n;
  vector<ll> a(n), when(n, -1);
  for (auto &x : a) cin >> x;
  bool assigned = false;
  int assign, assigned_at;
  int Q;
  cin >> Q;
  for (int q = 0; q < Q; ++q) {
    int t; cin >> t;
    if (t == 1) {
      if (!assigned)
        for (auto &x : a) x = 0;
      assigned = true;
      cin >> assign;
      assigned_at = q;
    } else if (t == 2) {
      int i, x;
      cin >> i >> x;
      i--;
      if (!assigned) a[i] += x;
      else if (when[i] > assigned_at) a[i] += x;
      else { a[i] = x; when[i] = q; }
    } else if (t == 3) {
      int i; cin >> i;
      i--;
      if (!assigned) cout << a[i] << '\n';
      else cout << assign + (when[i] > assigned_at ? a[i] : 0) << '\n';
    }
  }
}
