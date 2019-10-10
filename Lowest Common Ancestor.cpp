#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair <ll, ll> pll;

const int Max = 2e5 + 10;
const int Mod = 1e9 + 7;
const ll Inf = 1LL << 62;

int L[Max];
int P[Max][22];
int T[Max];
vector <int> G[Max];

void dfs(int u, int par, int dep) {
        T[u] = par;
        L[u] = dep;
        for(int v : G[u]) {
                if(v == par) {
                        continue;
                }
                dfs(v, u, dep + 1);
        }
}

int lca_query(int p, int q) {
        if(L[p] < L[q]) {
                swap(p, q);
        }
        int lg = 1;
        while(1) {
                int nxt = lg + 1;
                if((1 << nxt) > L[p]) {
                        break;
                }
                lg++;
        }
        for(int i = lg; i >= 0; i--) {
                if(L[p] - (1 << i) >= L[q]) {
                        p = P[p][i];
                }
        }
        if(p == q) {
                return p;
        }
        for(int i = lg; i >= 0; i--) {
                if(P[p][i] != -1 && P[p][i] != P[q][i]) {
                        p = P[p][i], q = P[q][i];
                }
        }
        return T[p];
}

void lca_init(int n) {
        memset(P, -1, sizeof(P));
        for(int i = 0; i < n; i++) {
                P[i][0] = T[i];
        }
        for(int j = 1; 1 << j < n; j++) {
                for(int i = 0; i < n; i++) {
                        if(P[i][j - 1] != -1) {
                                P[i][j] = P[P[i][j - 1]][j - 1];
                        }
                }
        }
}

int main() {
        int n, u, v, q;
        scanf("%d", &n);
        for(int i = 1; i < n; i++) {
                scanf("%d %d", &u, &v);
                G[u].push_back(v);
                G[v].push_back(u);
        }
        dfs(0, 0, 0);
        lca_init(n);
        scanf("%d", &q);
        while(q--) {
                scanf("%d %d", &u, &v);
                printf("%d\n", lca_query(u, v));
        }
        return 0;
}
