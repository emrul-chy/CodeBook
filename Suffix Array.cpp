const int Max = 1e5 + 10;

char str[Max];

int n, len;
int sa[Max], pos[Max], tmp[Max], lcp[Max];

bool sufCmp(int i, int j) {
	if(pos[i] != pos[j]) {
		return pos[i] < pos[j];
	}
	i += len;
	j += len;
	return (i < n && j < n) ? pos[i] < pos[j] : i > j;
}

void buildSA() {
	memset(sa, 0, sizeof sa);
	memset(pos, 0, sizeof pos);
	memset(lcp, 0, sizeof lcp);
	memset(tmp, 0, sizeof tmp);
	n = strlen(str);
	for(int i = 0; i < n; i++) {
		sa[i] = i, pos[i] = str[i];
	}
	for(len = 1;; len *= 2) {
		sort(sa, sa + n, sufCmp);
		for(int i = 0; i < n - 1; i++) {
			tmp[i + 1] = tmp[i] + sufCmp(sa[i], sa[i + 1]);
		}
		for(int i = 0; i < n; i++) {
			pos[sa[i]] = tmp[i];
		}
		if(tmp[n - 1] == n - 1) {
			break;
		}
	}
}

void buildLCP() {
	for(int i = 0, k = 0; i < n; i++) {
		if(pos[i] != n - 1) {
			for(int j = sa[pos[i] + 1]; str[i + k] == str[j + k];) {
				k++;
			}
			lcp[pos[i]] = k;
			if(k) {
				k--;
			}
		}
	}
}
