// Floyd Warshall APSP
// Also works for SSSP (V <= 400)
//		
// Printing path: p[i][j] set to i (last node that appears before j on the path), then p[i][j] = p[k][j] on update.
//
// Transitive Closure: weight is boolean (init as 1 if there's an edge), update with bitwise OR
//
// Minimax/Maximin: w[i][j] = min(w[i][j], max(w[i][k], w[k][j]))
//
// Finding negative/cheapest cycle: init w[i][i] = inf; run(); any w[i][i] != inf is a cycle and the smallest is the cheapest; any w[i][i] < 0 is negative
//
// This can also be used for finding SCCs (check with transitive closure)
//
// Usage: FloydWarshall(n, edges)
// Time: O(V^3+E)
// Space: O(V^2+E)
// Status: tested (UVA821, UVA1056)

struct edge { int v, u, w; };
const int inf = 0x3f3f3f3f;
vector<vector<int>> weight(M, vector<int>(M, inf));
vector<edge> edges;

void floydWarshall(int n) {
	for (auto e: edges)
		weight[e.v][e.u] = e.w;
	for (int k = 0; k < n; ++k)
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				if (max(weight[i][k], weight[k][j]) < inf)
					weight[i][j] = min(weight[i][j], weight[i][k]+weight[k][j]);
}
