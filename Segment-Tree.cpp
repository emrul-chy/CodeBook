/*
        Topic: Segment Tree
*/

const int Max = 1e5 + 10;

int ar[Max];
int seg[Max * 4];

void build(int node, int left, int right) {
        if(left == right) {
                seg[node] = ar[left];
                return;
        }
        int mid = (left + right) >> 1;
        int lf = node * 2;
        int rt = node * 2 + 1;
        build(lf, left, mid);
        build(rt, mid + 1, right);
        seg[node] = seg[lf] + seg[rt];
}

int update(int node, int left, int right, int idx, int val) {
        if(right == left) {
                seg[node] = val;
                return seg[node];
        }
        int mid = (left + right) >> 1, u = seg[node*2], v = seg[node*2 + 1];
        if(mid >= idx){
                u = update(2*node, left, mid, idx, val);
        }
        else{
                v = update(2*node+1, mid+1, right, idx, val);
        }
        return seg[node] = u + v;
}

int query(int node, int left, int right, int L, int R) {
        if(R < left || L > right) {
                return 0;
        }
        if(L <= left && right <= R) {
                return seg[node];
        }
        int mid = (left + right) >> 1;
        int u = query(node * 2, left, mid, L, R);
        int v = query(node * 2 + 1, mid + 1, right, L, R);
        return u + v;
}
