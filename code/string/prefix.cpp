// Prefix Function (KMP)
// Status: not tested
// Source: CP-Algorithms

vector<int> prefix(string s) {
	int n = s.length();
	vector<int> pi(n, 0); // can be optimized if you know max prefix length
	for (int i = 1; i < n; ++i) {
		int j = pi[i-1];
		while (j > 0 && s[i] != s[j])
			j = pi[j-1];
		if (s[i] == s[j])
			j++;
		pi[i] = j;
	}
	return pi;
}
