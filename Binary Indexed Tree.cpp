/*
        Topic: Binary Indexed Tree
*/

const int Max = 1e5 + 10;
const int Mod = 1e9 + 7;
const ll Inf = 1LL << 62;

int ar[Max], n;
ll BIT[Max];

void update( int idx, int val ) {
	while( idx <= n ) {
		BIT[idx] += val;
		idx += idx & -idx;
	}
}

ll query( int idx ) {
	ll ret = 0;
	while( idx > 0 ) {
		ret += BIT[idx];
		idx -= idx & -idx;
	} return ret;
}

ll query( int l, int r ) {
	return query( r ) - query( l - 1 );
}

void build() {
	for( int i=1; i<=n; i++ ) {
		update( i, ar[i] );
	}
}

int main() {
#ifdef Mr_Emrul
	freopen("inputf.in", "r", stdin);
#endif ///Mr_Emrul

	//ios_base::sync_with_stdio(false);
	//cin.tie(0);
	int q, l, r;
	scanf("%d %d", &n, &q);
	for( int i=1; i<=n; i++ ) {
		scanf("%d", &ar[i]);
	}
	build();
	while( q-- ) {
		scanf("%d %d", &l, &r);
		printf("%lld\n", query( l, r ));
	}
	return 0;
}
