#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool confusing(int h, int m) {
  int h1 = h/10, h2 = h%10, m1 = m/10, m2 = m%10;
  return h1*10 + m1 < 24 && h2*10 + m2 < 60;
}

pair<int, int> solve(int H, int M) {
  for (int m = M; m < 60; ++m)
    if (confusing(H, m))
      return make_pair(H, m);
  for (int h = H+1; h < H+25; ++h)
    for (int m = 0; m < 60; ++m)
      if (confusing(h%24, m))
        return make_pair(h%24, m);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
  int H, M;
  cin >> H >> M;
  auto ans = solve(H, M);
  cout << ans.first << ' ' << ans.second << '\n';
}
