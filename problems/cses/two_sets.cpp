#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
  // soma de 1 a n tem que ser par, aí vc faz essa soma / 2 sempre pegando o maior
  vector<int> a, b;
  int n; cin >> n;
  ll s = ((1+n)*n)/2;
  if (s % 2) return cout << "NO\n", 0;
  else cout << "YES\n";
  ll sh = 0;
  for (int i = n; i > 0; --i)
    if (sh + i <= s/2) {
      a.push_back(i);
      sh += i;
    }
    else
      b.push_back(i);
  cout << a.size() << '\n';
  for (auto i: a)
    cout << i << ' ';
  cout << '\n';
  cout << b.size() << '\n';
  for (auto i: b)
    cout << i << ' ';
  cout << '\n';
}
