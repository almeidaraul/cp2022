// Euler Tour
// Find the closest neighbor that has a path back to the current vertex to build an euler tour
//
// Euler path: visits each edge once
// Tour/cycle/circuit: euler path that starts and ends at same node
//
// Undirected and has path: every vertex has even degree or two have odd degree
// Undirected and has circuit: every vertex has even degree
// Directed and has path: indeg[i]-outdeg[i] == 1 for at most one i, -1 for at most one i, 0 for all other i
// Directed and has circuit: indeg[i] == outdeg[i] for every i
//
// Usage: tour(cyc.begin(), start\_vertex)
// Time: O(E^2)
// Status: not tested
// Source: CP3 (pg. 205)

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
