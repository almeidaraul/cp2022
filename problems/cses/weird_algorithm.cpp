#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  ll n; cin >> n;
  while (n != 1) {
    cout << n << ' ';
    n = n%2 ? 3*n+1 : n/2;
  }
  cout << 1 << '\n';
}
