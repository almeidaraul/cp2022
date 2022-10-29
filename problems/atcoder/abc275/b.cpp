#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll P = 998244353;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
  ll a, b, c, d, e, f;
  cin >> a >> b >> c >> d >> e >> f;
  a %= P; b %= P; c %= P; d %= P; e %= P; f %= P;
  a = (((a * b) % P) * c) % P;
  d = (((d * e) % P) * f) % P;
  cout << ((a - d + P) % P) << '\n';
}
