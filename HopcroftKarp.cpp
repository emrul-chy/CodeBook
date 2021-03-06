//Esqrt(V) Complexity
//0 Based
//Edge from set a to set b
const int MAXN1 = 50010; //nodes in set a
const int MAXN2 = 50010; //nodes in set b
const int MAXM = 150010; //number of edges

int n1, n2, edges, last[MAXN1], prev[MAXM], head[MAXM];
int matching[MAXN2], dist[MAXN1], Q[MAXN1];
bool used[MAXN1], vis[MAXN1]; //vis is cleared in each dfs

// n1 = number of nodes in set a, n2 = number of nodes in set b
void init(int _n1, int _n2) {
	n1 = _n1;
	n2 = _n2;
	edges = 0;
	fill(last, last + n1, -1);
}

void addEdge(int u, int v) {
	head[edges] = v;
	prev[edges] = last[u];
	last[u] = edges++;
}

void bfs() {
	fill(dist, dist + n1, -1);
	int sizeQ = 0;

	for(int u = 0; u < n1; ++u) {
		if(!used[u]) {
			Q[sizeQ++] = u;
			dist[u] = 0;
		}
	}

	for(int i = 0; i < sizeQ; i++) {
		int u1 = Q[i];

		for(int e = last[u1]; e >= 0; e = prev[e]) {
			int u2 = matching[head[e]];

			if(u2 >= 0 && dist[u2] < 0) {
				dist[u2] = dist[u1] + 1;
				Q[sizeQ++] = u2;
			}
		}
	}
}

bool dfs(int u1) {
	vis[u1] = true;

	for(int e = last[u1]; e >= 0; e = prev[e]) {
		int v = head[e];
		int u2 = matching[v];

		if(u2 < 0 || (!vis[u2] && dist[u2] == dist[u1] + 1 && dfs(u2))) {
			matching[v] = u1;
			used[u1] = true;
			return true;
		}
	}

	return false;
}

int augmentPath() {
	bfs();
	fill(vis, vis + n1, false);
	int f = 0;

	for(int u = 0; u < n1; ++u)
		if(!used[u] && dfs(u)) {
			++f;
		}

	return f;
}

int maxMatching() {
	fill(used, used + n1, false);
	fill(matching, matching + n2, -1);

	for(int res = 0;;) {
		int f = augmentPath();

		if(!f) {
			return res;
		}

		res += f;
	}
}

int main() {
	return 0;
}
