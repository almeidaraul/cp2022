// Segment Tree
// Usage: SegTree(N)
// Complexity:
//  build: O(n)
//  query: O(n)
//  modify: O(n)

struct SegTree {
	int N;
	vi st, A;
	
	SegTree(int N): N(N), st(4*n), A(n) {
		init(); 
	}

	void init() { build(1, 0, n-1); }

	int left(int i) { return i*2; }
	int right(int i) { return i*2+1; }

	void build(int v, int tl, int tr) {
		if (tl == tr) st[v] = a[tl];
		else {
			int tm = (tl+tr)/2;
			build(left(v), tl, tm);
			build(right(v), tm+1, tr);
			st[v] = max(st[left(v)], st[right(v)]);
		}
	}

	int maxquery(int v, int tl, int tr, int l, int r) {
		if (l > r) return -1;
		if (l == tl && r == tr) return st[v];
		int tm = (tl+tr)/2;
		int q1 = maxquery(left(v), tl, tm, l, min(r, tm));
		int q2 = maxquery(right(v), tm+1, tr, max(l, tm+1), r);
		return max(q1, q2);
	}

	int maxquery(int l, int r) {
		return maxquery(1, 0, n-1, l-1, r-1);
	}

	void update(int v, int tl, int tr, int p, int new_val) {
		if (tl == tr) st[v] = new_val;
		else {
			int tm = (tl+tr)/2;
			if (p <= tm)
				update(left(v), tl, tm, p, new_val);
			else
				update(right(v), tm+1, tr, p, new_val);
			st[v] = max(st[left(v)], st[right(v)]);
		}
	}

	void update(int p, int new_val) {
		update(1, 0, n-1, p-1, new_val);
	}
};
