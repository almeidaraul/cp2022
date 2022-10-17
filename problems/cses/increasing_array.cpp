#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
  int n; cin >> n;
  vector<int> v(n);
  for (auto &x: v) cin >> x;
  ll ans = 0;
  for (int i = 1; i < n; ++i)
    if (v[i] < v[i-1]) {
      ans += v[i-1]-v[i];
      v[i] = v[i-1];
    }
  cout << ans << '\n';
}
