#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
  string a, b;
  cin >> a >> b;
  char cmp = a == b ? '=' : a > b ? '>' : '<';
  cout << a << cmp << b << '\n';
}
