// Coordinate Compression
// Status: not tested
// Source: GEMA ICMC (YouTube)
// O(N log N) time

vector<int> v, vals, cv; // all of the same size, cv = compressed v
vals = v;
sort(vals.begin(), vals.end());
vals.erase(unique(vals.begin(), vals.end()), vals.end());
for (int i = 0; i < n; ++i) {
	int idx = lower_bound(vals.begin(), vals.end(), v[i]) - vals.begin();
	cv[i] = idx;
}
