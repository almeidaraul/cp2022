#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  int n; cin >> n;
  cout << "1 ";
  for (int i = n; i > 2; --i) cout << i << ' ';
  cout << "2\n";
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
  int t; cin >> t;
  while (t--) solve();
}
