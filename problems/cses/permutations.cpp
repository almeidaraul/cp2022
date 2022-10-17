#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
  int n; cin >> n;
  if (n == 1) { cout << "1\n"; return 0; }
  if (n < 4) { cout << "NO SOLUTION\n"; return 0; }
  for (int i = 1; i <= n/2; ++i)
    cout << i + n/2 << ' ' << i << ' ';
  if (n%2)
    cout << n;
  cout << '\n';
}
