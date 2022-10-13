#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
  int n; cin >> n;
  vector<bool> seen(n+1);
  for (int i = 1; i < n; ++i) {
    int e; cin >> e; seen[e] = true;
  }
  for (int i = 1; i <= n; ++i)
    if (!seen[i])
      cout << i << '\n';
}
