#include <bits/stdc++.h>
using namespace std;
using ll = long long;

using ld = long double;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
  int n, a, b;
  cin >> n >> a >> b;
  ld l = b-a+1;
  vector<ld> sw(n+1, 0);
  ld s = 0;
  for (int i = 1; i <= n; ++i) {
    if (i-b-1 >= 0)
      s -= sw[i-b-1];
    sw[i] = 1;
    if (i >= a) {
      if (a)
        s += sw[i-a];
      sw[i] += s/l;
      if (!a) {
        sw[i] *= (l/(l-1));
        s += sw[i];
      }
    }
  }
  cout << sw[n] << '\n';
}
