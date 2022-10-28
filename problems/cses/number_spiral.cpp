#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int nth(int n) { return 1+(n-1)*2; }

void solve() {
  int i, j;
  cin >> i >> j;
  ll lvl = max(i, j);
  // ans starts as sum of (lvl-1) first odds
  ll ans = (lvl-1)*(lvl-1);
  if ((lvl % 2 && j >= i) || (!(lvl % 2) && j <= i)) {
    ans += lvl; // how many numbers in this line come before the middle
    if (min(i, j) < lvl)
      ans += lvl - min(i, j); // distance from middle to point
  } else {
    ans += min(i, j);
  }
  cout << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
  int t;
  cin >> t;
  while (t--) solve();
}
