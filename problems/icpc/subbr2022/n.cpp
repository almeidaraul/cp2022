#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<int, int>;

int viradas = 0;
ll s = 0;
vector<bool> virado;
vector<int> a, b;
set<ii> virados, desvirados;

void limpa(int i) {
  int peso = b[i];
  auto it = virados.find({peso, i});
  if (it != virados.end())
    virados.erase(it);
  it = desvirados.find({-peso, i});
  if (it != desvirados.end())
    desvirados.erase(it);
}

void vira(int i) {
  virado[i] = true;
  int peso = b[i];
  auto it = desvirados.find({-peso, i});
  if (it != desvirados.end())
    desvirados.erase(it);
  virados.insert({peso, i});
}

void desvira(int i) {
  virado[i] = false;
  int peso = b[i];
  auto it = virados.find({peso, i});
  if (it != virados.end())
    virados.erase(it);
  desvirados.insert({-peso, i});
}

int melhor_pra_virar() {
  return desvirados.begin()->second; // maior b
}

int melhor_pra_desvirar() {
  return virados.begin()->second; // menor b
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
  int n; cin >> n;
  virado.resize(2*n+1); a.resize(2*n+1); b.resize(2*n+1);
  for (int i = 0; i < n; ++i) { cin >> a[i]; }
  for (int i = 0; i < n; ++i) { cin >> b[i]; }
  for (int i = 0; i < n; ++i) { a[i+n] = a[i]; b[i+n] = b[i]; }
  int k, l;
  cin >> k >> l;
  
  ll ans = 0;
  for (int i = n-k; i < n-k+l; ++i) { // os primeiros l vc pega
    cout << i << ' ';
    vira(i);
    s += a[i] + b[i];
  }
  if (l == k) ans = max(ans, s);
  // [n-k+l, n-k+2*k)
  // n-k+l --> n+k
  if (n > l)
  for (int i = n-k+l; i < n+k; ++i) {
    int f = i-k; // vai sair da sliding window agora
    cout << i%n << " (f = " << f%n << ") ";
    s += a[i] - a[f];
    limpa(f);
    if (virado[f]) {
      virado[f] = false;
      // vai sair um virado da sliding window
      s -= b[f];
      int j = melhor_pra_virar();
      vira(j);
      s = s + b[j];
    } else {
      // pode tanto pegar esse e tirar um quanto não pegar esse
      int j = melhor_pra_desvirar();
      ll s_pick = s + b[i] - b[j];
      if (s_pick > s) {
        vira(i);
        desvira(j);
      } else {
        desvira(i);
      }
      s = max(s_pick, s);
    }
    ans = max(ans, s);
  }
  cout << '\n';
  cout << ans << '\n';
}
