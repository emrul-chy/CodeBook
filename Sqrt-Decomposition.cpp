/*
        Topic: Sqrt Decomposition
        Problem: LOJ - 1112
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair <ll, ll> pll;

const int Max = 2e6 + 10;
const int Mod = 1e9 + 7;
const ll Inf = 1LL << 62;

ll BLOCK_SIZE;
ll BLOCK[1001];
ll ar[100001];

ll getID(ll idx) {
	ll id = idx / BLOCK_SIZE;
	return id;
}

ll calc() {
	for(int i = 1; i < 1000; i++) {
		BLOCK[i] = 0;
	}
}

void del(int idx) {
	int id = getID(idx);
	BLOCK[id] -= ar[idx];
	ar[idx] = 0;
}

void add(int idx, ll val) {
	int id = getID(idx);
	BLOCK[id] += val;
}

ll query(int l, int r) {
	int lf = getID(l);
	int rt = getID(r);

	ll ret = 0;

	if(lf == rt) {
		for(int i = l; i <= r; i++) {
			ret += ar[i];
		}
		return ret;
	}

	for(int i = l; i < (lf + 1) * BLOCK_SIZE; i++) {
		ret += ar[i];
	}

	for(int i = lf + 1; i < rt; i++) {
		ret += BLOCK[i];
	}

	for(int i = rt * BLOCK_SIZE; i <= r; i++) {
		ret += ar[i];
	}
	return ret;
}
