// Euler Tour
// Usage: tour(cyc.begin(), start\_vertex)
// Status: not tested
// Source: CP3 (pg. 205)
// O(E^2) time

list<int> cyc;
vector<vector<int>> adj(M);
vector<vector<bool>> traversed(M, vector<bool>(M, false));

//euler tour (list for fast insertion)
void tour(list<int>::iterator i, int v) {
	for (auto u: adj[v]) {
		if (!traversed[v][u]) {
			traversed[v][u] = true;
			for (auto t: adj[u])
				if (t == v && !traversed[u][t]) {
					traversed[u][t] = true;
					break;
				}
			tour(cyc.insert(i, v), u);
		}
	}
}
