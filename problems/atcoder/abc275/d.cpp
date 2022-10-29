#include <bits/stdc++.h>
using namespace std;
using ll = long long;

map<ll, ll> memo;

ll f(ll k) {
  if (!k) return 1;
  if (memo[k]) return memo[k];
  return memo[k] = f(k/2) + f(k/3);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
  ll n; cin >> n;
  cout << f(n) << '\n';
}
