struct Node {
	int at, cost;
	Node(int _at, int _cost) {
		at = _at;
		cost = _cost;
	}
};

bool operator<(Node a, Node b) {
	return a.cost > b.cost;
}

struct Edge {
	int v, w;
	Edge(int _v, int _w) {
		v = _v;
		w = _w;
	}
};

vector <Edge> G[10001];
priority_queue <Node> pq;
int dist[10001];

int n, m, s;

void dijsktra(int src) {
	for(int i = 1; i <= n; i++) {
		dist[i] = 1e9;
	}

	dist[src] = 0;
	pq.push(Node(src, 0));

	while(!pq.empty()) {
		Node u = pq.top();
		pq.pop();

		if(u.cost != dist[u.at]) {
			continue;
		}

		for(int i = 0; i < G[u.at].size(); i++) {
			Edge e = G[u.at][i];

			if(dist[e.v] > u.cost + e.w) {
				dist[e.v] = u.cost + e.w;
				pq.push(Node(e.v, dist[e.v]));
			}
		}
	}
}
