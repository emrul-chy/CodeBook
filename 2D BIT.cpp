/*
        LOJ 1266
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair <ll, ll> pll;

const int Max = 1e3 + 10;
const int Mod = 1e9 + 7;
const ll Inf = 1LL << 62;

bool point[Max][Max];
int BIT[Max][Max];

void update(int x, int y) {
	for(int i = x; i < Max; i += i & -i) {
		for(int j = y; j < Max; j += j & -j) {
			BIT[i][j]++;
		}
	}
}

int query(int x, int y) {
	int ret = 0;
	for(int i = x; i > 0; i -= i & -i) {
		for(int j = y; j > 0; j -= j & -j) {
			ret += BIT[i][j];
		}
	}
	return ret;
}

int main() {
#ifdef Mr_Emrul
	freopen("inputf.in", "r", stdin);
#endif ///Mr_Emrul

	//ios_base::sync_with_stdio(false);
	//cin.tie(0);

	int t, type, q, x1, x2, y1, y2, x, y;
	scanf("%d", &t);
	char ch;
	for(int tc = 1; tc <= t; tc++) {
		scanf("%d", &q);
		memset(point, 0, sizeof point);
		memset(BIT, 0, sizeof BIT);
		printf("Case %d:\n", tc);
		while(q--) {
			scanf("%d", &type);
			if(type == 0) {
				scanf("%d %d", &x, &y);
				x++;
				y++;
				if(point[x][y]) {
					continue;
				}
				point[x][y] = 1;
				update(x, y);
			} else {
				scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
				x1++;
				y1++;
				x2++;
				y2++;
				printf("%d\n", query(x2, y2) - query(x1 - 1, y2) - query(x2, y1 - 1) + query(x1 - 1, y1 - 1));
			}
		}
	}
	return 0;
}
