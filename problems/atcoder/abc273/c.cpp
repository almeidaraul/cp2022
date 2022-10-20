#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
  int n; cin >> n;
  vector<int> v(n), ans(n), cv(n), vals;

  for (int i = 0; i < n; ++i)
    cin >> v[i];

  vals = v;
  sort(vals.begin(), vals.end());
  vals.erase(unique(vals.begin(), vals.end()), vals.end());
  for (int i = 0; i < n; ++i) {
    int idx = lower_bound(vals.begin(), vals.end(), v[i]) - vals.begin();
    cv[i] = idx;
  }

  for (int i = 0; i < n; ++i)
    ans[vals.size() - cv[i] - 1]++;
  for (int i = 0; i < n; ++i)
    cout << ans[i] << '\n';
}
