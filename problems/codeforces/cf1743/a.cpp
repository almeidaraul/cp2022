#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
  vector<int> f(11);
  f[0] = 1;
  for (int i = 1; i < 10; ++i) f[i] = i*f[i-1];

  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    for (int i = 0; i < n; ++i) cin >> f[10];
    n = 10-n;
    cout << (6 * f[n]) / (2 * f[n-2]) << '\n';
  }
}
