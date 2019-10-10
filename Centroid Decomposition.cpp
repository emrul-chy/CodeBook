struct CentriodDecomposition {
        bool vist[Max];
        int sub[Max];
        int path[Max];

        CentriodDecomposition() {
                memset(vist, 0, sizeof vist);
                memset(sub, 0, sizeof sub);
                memset(path, 0, sizeof path);
        }

        int centroid(int u, int par, int sz) {
                for(int v : G[u]) {
                        if(v == par) {
                                continue;
                        }
                        if(!vist[v]) {
                                if(sub[v] > sz) {
                                        return centroid(v, u, sz);
                                }
                        }
                }
                return u;
        }

        void calc(int u, int par) {
                sub[u] = 1;
                for(int v : G[u]) {
                        if(v == par) {
                                continue;
                        }
                        if(!vist[v]) {
                                calc(v, u);
                                sub[u] += sub[v];
                        }
                }
        }

        void decompose(int u, int par, char ch) {
                calc(u, par);
                int c = centroid(u, -1, sub[u] / 2);
                vist[c] = 1;
                ans[c] = ch;
                path[c] = par;
                for(int v : G[c]) {
                        if(!vist[v]) {
                                decompose(v, c, ch + 1);
                        }
                }
        }
} tree;
