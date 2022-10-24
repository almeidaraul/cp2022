#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  int i, j;
  cin >> i >> j;
  int lvl = max(i, j);
  int ans = //TODO sum of (lvl-1) first primes
  if ((lvl % 2 && j <= i) || (!(lvl % 2) && j > i))
    ans += lvl - 1; // how many numbers in this line come before the middle
  ans += min(i, j) - lvl + 1; // distance (incl.) from middle (diag.) to point
  cout << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
  int t;
  cin >> t;
  while (t--) solve();
}
