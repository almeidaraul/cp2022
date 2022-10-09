// Kruskal MST
// order edges by increasing weight, then use a MUF to know if each edge is useful (if it connects two previously disconnected vertices)
// 
// Min Span Subgraph: previously process fixed edges
//
// Min Span Forest: count number of sets on the MUF
// 
// 2nd Best MST: run kruskal; for each chosen edge, flag it as unavailable and run it without using that edge ($O(VE)$)
//
// Minimax: max edge weight on the MST (maximin: min)
//
// Usage: Kruskal(V, E, edges) (weighted edges)
//
// Time: O(E log V)
// Space: O(V + E)
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
