#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
  int n, k;
  cin >> n >> k;
  if (k > n) k = n;
  vector<int> a(n);
  for (auto &x: a) cin >> x;
  for (int i = 0; i < n-k; ++i)
    cout << a[i+k] << ' ';
  while (k--) cout << 0 << ' ';
  cout << '\n';
}
