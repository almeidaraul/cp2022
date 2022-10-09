// Prime Factors w/ Optimized Trial Divisions
// Time: O(Pi(sqrt(n)))
// Space: O(n)
// Status: not tested
// Source: CP3 (pg. 238)

vector<int> primes;
vector<pair<int, int>> factors;

void pf(int n) {
	for (auto p: primes) {
		if (p*p > n) break;
		int i = 0;
		while (!(n%p)) {
			n /= p;
			i++;
		}
		factors.push_back({p, i});
	}
	if (n != 1) factors.push_back({n, 1});
}
