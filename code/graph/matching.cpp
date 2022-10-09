// Max Cardinality Bipartite Matching
// Jump from free to matched edges until you've used them all
//
// Time: O(VE)
// Status: not tested
// Source: CP3 (pg. 209)

vector<vector<int>> adj(M);
vector<int> match(M, -1);
vector<bool> visited(M);

bool augment(int left) { //match one on the left with one on the right
	if (visited[left]) return false;
	visited[left] = true;
	for (auto right: adj[left])
		if (match[right] == -1 || augment(match[right])) {
			match[right] = left;
			return true;
		}
	return false;
}

//usage
//(mcbm = V iff there's at least one way to completely match both sides)
int mcbm = 0; //number of matched vertices
match.assign(M, -1);
for (int v = 0; v < ls; ++v) {//ls = size of the left set
	visited.assign(ls, false);
	mcbm += augment(v);
}
