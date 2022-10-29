#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<int, int>;

#define xx first
#define yy second

ll dist(ii a, ii b) {
  ll x = a.xx - b.xx;
  ll y = a.yy - b.yy;
  return x*x + y*y;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
  vector<ii> pawns;
  for (int i = 0; i < 9; ++i) {
    string s; cin >> s;
    for (int j = 0; j < 9; ++j)
      if (s[j] == '#')
        pawns.push_back({i+1, j+1});
  }
  int sz = (int)pawns.size();
  int ans = 0;
  for (int i = 0; i < sz; ++i)
  for (int j = i+1; j < sz; ++j)
  for (int k = j+1; k < sz; ++k)
  for (int l = k+1; l < sz; ++l) {
    int d1, d2, d3, d4;
    d1 = dist(pawns[i], pawns[j]);
    d2 = dist(pawns[i], pawns[k]);
    d3 = dist(pawns[j], pawns[l]);
    d4 = dist(pawns[k], pawns[l]);
    if ((d1 == d2) && (d1 == d3) && (d1 == d4)
        && (d2 == d3) && (d2 == d4)
        && (d3 == d4))
      ans++;
  }
  cout << ans << '\n';
}
