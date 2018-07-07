/*
        String Hashing
*/
#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long int ull ;
const int base = 31 ;
const int Max = 1e5;

unordered_map < ull, ull > mp ;

ull pw[Max];
ull Hash[Max];

void pre_power() {
	pw[0] = 1 ;
	for(int i = 1; i < Max; i++) {
		pw[i] = pw[i - 1] * base ;
	}
}

ull Hashing(char str [], int len) {
	ull hash_val = 0;
	for(int i = 0; i < len; i++) {
		hash_val = hash_val * pw[i] + str[i];
		Hash[i] = hash_val;
	}
	return hash_val;
}

ull SubstringHash(int l, int r) {
	return Hash[r] - Hash[l - 1] * pw[r - l + 1];
}

