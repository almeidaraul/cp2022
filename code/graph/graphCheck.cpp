// Graph Check
// Usage: graphCheck(firstVertex, -1) (p stands for parent)

int UNVISITED = -1, EXPLORED = 0, VISITED = 1;
vector<vector<int>> adj(M);
vector<int> tin;

void graphCheck(int v, int p) { //vertex, parent
	tin[v] = EXPLORED;
	for (auto u: adj[v]) {
		if (tin[u] == UNVISITED) { //tree edge
			graphCheck(u, v);
		} else if (tin[u] == EXPLORED) {
			if (u == p)
				; //two way edge u <-> v
			else
				; //back edge v -> u
		} else if (tin[u] == VISITED) {
			; //forward/cross edge u-v
		}
	}
	tin[v] = VISITED;
}
