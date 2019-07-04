#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair <ll, ll> pll;

const int Max = 3e4 + 10;
const int Mod = 1e9 + 7;
const ll Inf = 1LL << 62;

vector <int> G[Max];
int ar[Max];
int inp[Max];
int seg[Max * 6];
int cur, chainNo, pos[Max];
int L[Max];
int P[Max][22];
int T[Max];
int sub[Max];
int chainInd[Max];
int chainHead[Max];

void build(int node, int l, int r) {
	if(l == r) {
		seg[node] = ar[l];
		return;
	}
	int mid = (l + r) >> 1;
	int lf = node * 2;
	int rt = lf + 1;
	build(lf, l, mid);
	build(rt, mid + 1, r);
	seg[node] = seg[lf] + seg[rt];
}

int update(int node, int l, int r, int idx, int val) {
	if(l == r) {
		seg[node] = val;
		return seg[node];
	}
	int mid = (l + r) >> 1, u = seg[node * 2], v = seg[node * 2 + 1];
	if(mid >= idx) {
		u = update(2 * node, l, mid, idx, val);
	}
	else {
		v = update(2 * node + 1, mid + 1, r, idx, val);
	}
	return seg[node] = u + v;
}

int query(int node, int l, int r, int L, int R) {
	if(R < l || L > r) {
		return 0;
	}
	if(L <= l && r <= R) {
		return seg[node];
	}
	int mid = (l + r) >> 1;
	int u = query(node * 2, l, mid, L, R);
	int v = query(node * 2 + 1, mid + 1, r, L, R);
	return u + v;
}

int query_up(int u, int v) {
	int uchain;
	int vchain = chainInd[v];
	int ans = 0;
	while(true) {
		uchain = chainInd[u];
		if(uchain == vchain) {
			ans += query(1, 0, cur - 1, pos[v], pos[u]);
			break;
		}
		ans += query(1, 0, cur - 1, pos[chainHead[uchain]], pos[u]);
		u = chainHead[uchain];
		u = P[u][0];
	}
	return ans;
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

int query(int u, int v) {
	int lca = lca_query(u, v);
	return query_up(u, lca) + query_up(v, lca) - ar[pos[lca]];
}

void update(int idx, int val) {
	ar[pos[idx]] = val;
	update(1, 0, cur - 1, pos[idx], val);
}

void HLD(int u, int prev) {
	if(chainHead[chainNo] == -1) {
		chainHead[chainNo] = u;
	}
	chainInd[u] = chainNo;
	pos[u] = cur;
	ar[cur++] = inp[u];
	int sc = -1, mx = -1;
	for(int i = 0; i < G[u].size(); i++) {
		int v = G[u][i];
		if(prev == v) {
			continue;
		}
		if(sub[v] > mx) {
			mx = sub[v];
			sc = v;
		}
	}
	if(sc != -1) {
		HLD(sc, u);
	}
	for(int i = 0; i < G[u].size(); i++) {
		int v = G[u][i];
		if(v != prev && v != sc) {
			chainNo++;
			HLD(v, u);
		}
	}
}

void dfs(int u, int par, int dep) {
	T[u] = par;
	L[u] = dep;
	sub[u] = 1;
	for(int i = 0; i < G[u].size(); i++) {
		int v = G[u][i];
		if(v == par) {
			continue;
		}
		dfs(v, u, dep + 1);
		sub[u] += sub[v];
	}
}

void Clear() {
	for(int i = 0; i < Max; i++) {
		G[i].clear();
	}
	cur = chainNo = 0;
	memset(chainHead, -1, sizeof chainHead);
}

int main() {
#ifdef Mr_Emrul
	freopen("inputf.in", "r", stdin);
#endif /// Mr_Emrul

	int t, n, q, u, v, ty, idx, val;
	scanf("%d", &t);
	for(int tc = 1; tc <= t; tc++) {
		Clear();
		scanf("%d", &n);
		for(int i = 0; i < n; i++) {
			scanf("%d", &inp[i]);
		}
		for(int i = 1; i < n; i++) {
			scanf("%d %d", &u, &v);
			G[u].push_back(v);
			G[v].push_back(u);
		}
		dfs(0, -1, 0);
		HLD(0, -1);
		lca_init(n);
		build(1, 0, cur - 1);
		printf("Case %d:\n", tc);
		scanf("%d", &q);
		while(q--) {
			scanf("%d", &ty);
			if(ty == 0) {
				scanf("%d %d", &u, &v);
				printf("%d\n", query(u, v));
			}
			else {
				scanf("%d %d", &idx, &val);
				update(idx, val);
			}
		}
	}
	return 0;
}
