/*
        Topic: Merge Sort Tree
        Problem: Codeforces 961E
*/

vector <int> tree[4 * Max];
int ar[Max];
int inp[Max];

void build(int node, int l, int r) {
	if(l == r) {
		tree[node].push_back(ar[l]);
		return;
	}
	int mid = (l + r) >> 1;
	int lf = node * 2;
	int rt = node * 2 + 1;
	build(lf, l, mid);
	build(rt, mid + 1, r);
	merge(tree[lf].begin(), tree[lf].end(), tree[rt].begin(), tree[rt].end(), back_inserter(tree[node]));
}

int query(int node, int l, int r, int L, int R, int val) {
	if(L > r || l > R) {
		return 0;
	}
	if(L <= l && r <= R) {
		return lower_bound(tree[node].begin(), tree[node].end(), val) - tree[node].begin();
	}
	int mid = (l + r) >> 1;
	int lf = node * 2;
	int rt = node * 2 + 1;
	int u = query(lf, l, mid, L, R, val);
	int v = query(rt, mid + 1, r, L, R, val);
	return u + v;
}
