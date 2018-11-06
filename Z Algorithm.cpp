#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair <ll, ll> pll;

const int Max = 2e6 + 10;
const int Mod = 1e9 + 7;
const ll Inf = 1LL << 62;

int Z[Max];
char ch[Max];

void compute_z_function(const char *S, int N) {
	int L = 0, R = 0;

	for(int i = 1; i < N; ++i) {
		if(i > R) {
			L = R = i;

			while(R < N && S[R - L] == S[R]) {
				++R;
			}

			Z[i] = R - L; --R;
		}
		else {
			int k = i - L;

			if(Z[k] < R - i + 1) {
				Z[i] = Z[k];
			}
			else {
				L = i;

				while(R < N && S[R - k] == S[R]) {
					++R;
				}

				Z[i] = R - L; --R;
			}
		}
	}
}

int main() {
#ifdef Mr_Emrul
	freopen("inputf.in", "r", stdin);
#endif /// Mr_Emrul

	scanf("%s", ch);
	compute_z_function(ch, strlen(ch));

	for(int i = 0; i < strlen(ch); i++) {
		printf("%d ", Z[i]);
	}

	return 0;
}
