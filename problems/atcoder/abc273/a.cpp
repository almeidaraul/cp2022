#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
  vector<int> f(11);
  f[0] = 1;
  for (int i = 1; i < 11; ++i) f[i] = i*f[i-1];
  int n; cin >> n;
  cout << f[n] << '\n';
}
