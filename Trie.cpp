struct Node {
	bool endmark;
	int cnt;
	Node *nxt[26 + 1];
	Node() {
		endmark = false;
		cnt = 0;
		for(int i = 0; i < 26; i++) {
			nxt[i] = NULL;
		}
	}
} *root;

void insert(char *str, int len) {
	Node *cur = root;
	for(int i = 0; i < len; i++) {
		int id = str[i] - 'a';
		if(cur->nxt[id] == NULL) {
			cur->nxt[id] = new Node();
		}
		cur = cur->nxt[id];
		cur->cnt++;
	}
	cur->endmark = true;
}

bool search(char *str, int len) {
	Node *cur = root;
	for(int i = 0; i < len; i++) {
		int id = str[i] - 'a';
		if(cur->nxt[id] == NULL) {
			return false;
		}
		cur = cur->nxt[id];
	}
	return cur->endmark;
}

int query(char *str, int len) {
	int ans = 0;
	Node *cur = root;
	for(int i = 0; i < len; i++) {
		int id = str[i] - 'a';
		if(cur->nxt[id] == NULL) {
			return false;
		}
		cur = cur->nxt[id];
		ans = max(ans, (i + 1) * cur->cnt);
	}
	return ans;
}

void del(Node *cur) {
    for(int i = 0; i < 2; i++) {
        if(cur->nxt[i]) {
            del(cur->nxt[i]);
        }
    }
    delete(cur);
}
