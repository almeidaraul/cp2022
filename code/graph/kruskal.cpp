// Kruskal MST
// Usage: Kruskal(V, E, edges) (weighted edges)
// Status: tested (UVA1174)

using iii = pair<int, pair<int, int>>; //weight, two vertices
vector<iii> edges;
UnionFind muf;

int kruskal() {
	int cost = 0;
	sort(edges.begin(), edges.end());
	for (auto a: edges) {
		int w = a.first;
		pair<int, int> e = a.second;
		if (!muf.isSameSet(e.first, e.second)) {
			cost += w;
			muf.unionSet(e.first, e.second);
		}
	}
	return cost;
}
