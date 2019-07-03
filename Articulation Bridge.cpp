void ArticulationBridge(int u) {
	low[u] = dist[u] = ++cur;
	vist[u] = 1;
	for(int i = 0; i < G[u].size(); i++) {
		int v = G[u][i];
		if(vist[v]) {
			if(v != par[u]) {
				low[u] = min(low[u], dist[v]);
			}
		}
		else {
			par[v] = u;
			ArticulationBridge(v);
			low[u] = min(low[u], low[v]);
			if(low[v] > dist[u]) {
				ans += 1;
			}
		}
	}
}
