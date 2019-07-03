void ArticulationPoint(int u) {
    low[u] = dist[u] = ++cur;
    vist[u] = 1;
    int tot = 0;
    for(int i = 0; i < G[u].size(); i++) {
        int v = G[u][i];
        tot++;
        if(vist[v]) {
            if(v != par[u]) {
                low[u] = min(low[u], dist[v]);
            }
        }
        else {
            par[v] = u;
            ArticulationPoint(v);
            low[u] = min(low[u], low[v]);
            if(tot > 1 and par[u] == -1) {
                st.insert(u);
            }
            if(par[u] != -1 and low[v] >= dist[u]) {
                st.insert(u);
            }
        }
    }
}
