#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
  int h, w, rs, cs, n;
  cin >> h >> w >> rs >> cs >> n;
  map<int, set<int>> rows, cols;
  for (int i = 0; i < n; ++i) {
    int ri, ci;
    cin >> ri >> ci;
    rows[ri].insert(ci);
    cols[ci].insert(ri);
  }
  int q; cin >> q;
  while (q--) {
    char d; int l;
    cin >> d >> l;
    int mxl, mxr, mxu, mxd;
    if (!rows.count(rs)) {
      mxl = 1;
      mxr = w;
    } else {
      auto up = rows[rs].upper_bound(cs);
      mxr = up == rows[rs].end() ? w : (*up)-1;
      mxl = up == rows[rs].begin() ? 1 : (*(--up))+1;
    }
    if (!cols.count(cs)) {
      mxu = 1;
      mxd = h;
    } else {
      auto up = cols[cs].upper_bound(rs);
      mxd = up == cols[cs].end() ? h : (*up)-1;
      mxu = up == cols[cs].begin() ? 1 : (*(--up))+1;
    }
    if (d == 'L')
      cs = max(cs-l, mxl);
    else if (d == 'R')
      cs = min(cs+l, mxr);
    else if (d == 'U')
      rs = max(rs-l, mxu);
    else if (d == 'D')
      rs = min(rs+l, mxd);
    cout << rs << ' ' << cs << '\n';
  }
}
