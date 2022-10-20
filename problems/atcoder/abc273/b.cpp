#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
  ll x, k, p = 1;
  cin >> x >> k;
  for (int i = 0; i < k; ++i) {
    p *= 10;
    ll top = p*(x / p + bool(x % p));
    ll bot = p*(x / p);
    x = (top - x <= x - bot) ? top : bot;
  }
  cout << x << '\n';
}
