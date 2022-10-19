#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int oo = 0x3f3f3f3f;

void solve() {
  int n; cin >> n;
  vector<int> a(n);
  string s; cin >> s;
  for (auto &x : a) cin >> x;
  s += '0';
  a.push_back(0);
  int i = 0, mn = oo, ans = 0;
  for (; s[i] == '1'; ++i) ans += a[i];
  for (; i <= n; ++i) {
    if (s[i] == '0') {
      // acabou de acabar uma sequencia ?
      if (mn != oo) {
        ans -= mn;
        mn = oo;
      }
      // vai começar uma sequencia ?
      if (s[i+1] == '1') {
        mn = a[i];
        ans += a[i];
      }
    } else {
      ans += a[i];
      // cerr << '+' << a[i] << '\n';
      mn = min(mn, a[i]);
    }
  }
  cout << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
  int t; cin >> t;
  while (t--) solve();
}
