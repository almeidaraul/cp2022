#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
  string chars = "ACGT";
  int ans = 0, cnt;
  string s; cin >> s;
  s += '_'; // so we update ans in the end
  for (auto c: chars) {
    cnt = 0;
    for (int i = 0; i < s.size(); ++i)
      if (s[i] == c)
        cnt++;
      else {
        ans = max(ans, cnt);
        cnt = 0;
      }
  }
  cout << ans << '\n';
}
