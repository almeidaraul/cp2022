// Floyd Warshall APSP
// Usage: FloydWarshall(n, edges)
// Status: tested (UVA821, UVA1056)
// O(V^3 + E) time, O(V^2 + E) space

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
