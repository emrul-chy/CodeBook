/*
        Topic: Merge Sort Tree
        Problem: Codeforces 91E
*/

vector <int> tree[4 * Max];
int ar[Max];

void build( int node, int l, int r ) {
	if( l == r ) {
		tree[node].push_back( ar[l] );
		return;
	}
	int mid = (l + r) >> 1;
	int left = node * 2;
	int right = node * 2 + 1;
	build( left, l, mid );
	build( right, mid + 1, r);
	merge( tree[left].begin(), tree[left].end(), tree[right].begin(), tree[right].end(), back_inserter( tree[node] ) );
}

int query( int node, int l, int r, int L, int R, int val ) {
	if( L > r || l > R ) {
		return 0;
	}
	if( L <= l && r <= R ) {
		return lower_bound( tree[node].begin(), tree[node].end(), val ) - tree[node].begin();
	}
	int mid = (l + r) >> 1;
	int left = node * 2;
	int right = node * 2 + 1;
	int u = query( left, l, mid, L, R, val );
	int v = query( right, mid+1, r, L, R, val );
	return u + v;
}
