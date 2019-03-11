#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair <ll, ll> pll;

const int Max = 2e6 + 10;
const int Mod = 1e9 + 7;
const ll Inf = 1LL << 62;

#define MX 15000

struct Node {
	int u, v, w;
} g[MX];

bool less(Node a, Node b) {
	return a.w < b.w;
}

bool more(Node a, Node b) {
	return a.w > b.w;
}

int node, edge, parent[MX];

int Find_parent(int n) {
	//cout << ": " << n << " " << parent[n] << endl;
	if(parent[n] == n) {
		return n;
	}

	return Find_parent(parent[n]);
}

void graph() {
	for(int i = 1; ; i++) {
		cin >> g[i].u >> g[i].v >> g[i].w;

		edge++;
	}
}

int kruskal() {
	int sum = 0;

	for(int i = 0; i <= node; i++) {
		parent[i] = i;
	}

	for(int i = 1; i <= edge; i++) {
		int u = Find_parent(g[i].u), v = Find_parent(g[i].v);

		//cout << u << " " << v << endl;
		if(u != v) {
			//printf("The cost from %d to %d is : %d\n", s1[i], s2[i], w[i]);
			parent[u] = v;
			sum += g[i].w;
		}
	}

	return sum;
}

int main() {
#ifdef Mr_Emrul
	freopen("inputf.in", "r", stdin);
#endif ///Mr_Emrul

	//ios_base::sync_with_stdio(false);
	//cin.tie(0);

	int t; cin >> t;

	for(int tc = 1; tc <= t; tc++) {
		cin >> node;
		edge = 0;
		graph();
		//cout << node << " " << edge << endl;

		// Minimum
		sort(g + 1, g + edge + 1, less);
		cout << kruskal() << endl;

		// Maximum
		sort(g + 1, g + edge + 1, more);
		cout << kruskal() << endl;
	}
	return 0;
}
