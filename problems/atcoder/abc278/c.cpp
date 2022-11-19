#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
  int n, q;
  cin >> n >> q;
  map<int, set<int>> m;
  while (q--) {
    int t, a, b;
    cin >> t >> a >> b;
    if (t == 1) m[a].insert(b);
    else if (t == 2 && m[a].count(b)) m[a].erase(b);
    else if (t == 3) cout << (m[a].count(b) && m[b].count(a) ? "Yes\n": "No\n");
  }
}
