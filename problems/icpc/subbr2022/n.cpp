#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<int, int>;

struct maxmin {
  set<pair<ll, int>> values;
  vector<set<pair<ll, int>>::iterator> by_idx;
  vector<bool> has_idx;

  maxmin(int n) : by_idx(n), has_idx(n) {};

  void insert(ll value, int idx) {
    by_idx[idx] = values.insert({value, idx}).first;
    has_idx[idx] = true;
  }
  pair<ll, int> get(bool mx) { return mx ? *(--values.end()) : *values.begin(); }
  void rm(int idx) {
    values.erase(by_idx[idx]);
    has_idx[idx] = false;
  }
  bool has(int idx) { return has_idx[idx]; }
  bool size() { return values.size(); }
};

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
  int N; cin >> N;
  vector<int> _a(N), _b(N);
  for (int i = 0; i < N; ++i) { cin >> _a[i]; }
  for (int i = 0; i < N; ++i) { cin >> _b[i]; }
  int k, l;
  cin >> k >> l;
  int n = (N+k) - (N-k);
  vector<int> a(n), b(n);
  for (int i = N-k; i < N+k; ++i) {
    a[i-N+k] = _a[i%N];
    b[i-N+k] = _b[i%N];
  }

  maxmin vira(n), naovira(n);
  ll s = 0, ans = 0;
  for (int i = 0; i < l; ++i) {
    s += a[i] + b[i];
    vira.insert(b[i], i); 
  }
  for (int i = l; i < n; ++i) {
    s += a[i];
    int j = vira.get(false).second;
    ll s_vira = s;
    if (vira.size()) {
      s_vira += b[i] - b[j];
    }
    if (s_vira > s) {
      vira.rm(j);
      vira.insert(b[i], i);
      naovira.insert(b[j], j);
      s = s_vira;
    } else {
      naovira.insert(b[i], i);
    }

    int f = i-k; // cara da esquerda (sai da sw)
    if (f >= 0) {
      s -= a[f];
      if (vira.has(f)) {
        vira.rm(f);
        s -= b[f];
        j = naovira.get(true).second;
        s += b[j];
        naovira.rm(j);
        vira.insert(b[j], j);
      } else {
        naovira.rm(f);
      }
    }
    ans = max(ans, s);
  }
  ans = max(ans, s);

  cout << ans << '\n';
}
