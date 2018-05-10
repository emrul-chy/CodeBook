ll ar[Max]; 
struct Node {
	ll prop, sum;
} seg[Max * 4]; 

void build(ll node, ll l, ll r) {
	if (l == r) {
		seg[node].sum = ar[l];
		return;
	}
	ll lf = node * 2;
	ll rt = node * 2 + 1;
	ll mid = (l + r) / 2;
	build(lf, l, mid);
	build(rt, mid + 1, r);
	seg[node].sum = seg[lf].sum + seg[rt].sum;
	seg[node].prop = 0;
}

ll query(ll node, ll l, ll r, ll L, ll R, ll cary = 0) {
	if (L > r || R < l) {
		return 0;
	}

	if (l >= L and r <= R) {
		return seg[node].sum + cary * (r - l + 1);
	}

	ll lf = node << 1;
	ll rt = (node << 1) + 1;
	ll mid = (l + r) >> 1;

	ll u = query(lf, l, mid, L, R, cary + seg[node].prop);
	ll v = query(rt, mid + 1, r, L, R, cary + seg[node].prop);

	return u + v;
}

void update(ll node, ll l, ll r, ll L, ll R, ll val) {
	if (L > r || R < l) {
		return;
	}
	if (l >= L && r <= R) {
		seg[node].sum += ((r - l + 1) * val);
		seg[node].prop += val;
		return;
	}
	ll lf = node * 2;
	ll rt = (node * 2) + 1;
	ll mid = (l + r) / 2;
	update(lf, l, mid, L, R, val);
	update(rt, mid + 1, r, L, R, val);
	seg[node].sum = seg[lf].sum + seg[rt].sum + (r - l + 1) * seg[node].prop;
}
