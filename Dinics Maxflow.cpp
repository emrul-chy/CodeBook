///V^2*E Complexity
///number of augment path * (V+E)
///Base doesn't matter

const int INF = 2000000000;
const int MAXN = 100;///total nodes
const int MAXM = 10000;///total edges

int N, edges;
int last[MAXN], Prev[MAXM], head[MAXM];
int Cap[MAXM], Flow[MAXM];
int dist[MAXN];
int nextEdge[MAXN];///used for keeping track of next edge of ith node

queue<int> Q;

void init(int N) {
	edges = 0;
	memset(last, -1, sizeof(int)*N);
}

//cap=capacity of edges , flow = initial flow
inline void addEdge(int u, int v, int cap, int flow) {
	head[edges] = v;
	Prev[edges] = last[u];
	Cap[edges] = cap;
	Flow[edges] = flow;
	last[u] = edges++;

	head[edges] = u;
	Prev[edges] = last[v];
	Cap[edges] = 0;
	Flow[edges] = 0;
	last[v] = edges++;
}

inline bool dinicBfs(int S, int E, int N) {
	int from = S, to, cap, flow;
	memset(dist, 0, sizeof(int)*N);
	dist[from] = 1;

	while(!Q.empty()) {
		Q.pop();
	}

	Q.push(from);

	while(!Q.empty()) {
		from = Q.front(); Q.pop();

		for(int e = last[from]; e >= 0; e = Prev[e]) {
			to = head[e];
			cap = Cap[e];
			flow = Flow[e];

			if(!dist[to] && cap > flow) {
				dist[to] = dist[from] + 1;
				Q.push(to);
			}
		}
	}

	return (dist[E] != 0);
}

inline int dfs(int from, int minEdge, int E) {
	if(!minEdge) {
		return 0;
	}

	if(from == E) {
		return minEdge;
	}

	int to, e, cap, flow, ret;

	for(; nextEdge[from] >= 0; nextEdge[from] = Prev[e]) {
		e = nextEdge[from];
		to = head[e];
		cap = Cap[e];
		flow = Flow[e];

		if(dist[to] != dist[from] + 1) {
			continue;
		}

		ret = dfs(to, min(minEdge, cap - flow), E);

		if(ret) {
			Flow[e] += ret;
			Flow[e ^ 1] -= ret;
			return ret;
		}
	}

	return 0;
}

int dinicUpdate(int S, int E) {
	int flow = 0;

	while(int minEdge = dfs(S, INF, E)) {
		if(minEdge == 0) {
			break;
		}

		flow += minEdge;
	}

	return flow;
}

int maxFlow(int S, int E, int N) {
	int totFlow = 0;

	while(dinicBfs(S, E, N)) {
		for(int i = 0; i <= N; i++) {
			nextEdge[i] = last[i];    /// update last edge of ith node
		}

		totFlow += dinicUpdate(S, E);
	}

	return totFlow;
}

int main() {
	return 0;
}
