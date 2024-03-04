struct item {
    ll sum = 0,lz = -1;
    item() {
    }
    item(ll x){
        sum = x;
    }
};
struct segTree {
    vector<item> seg;
    int sz = 1,n,NO_OP = -1;
    segTree(int nn){
        n = nn;
        while (sz < nn)
            sz *= 2;
        seg.assign(2 * sz , item());
    }

    item merge(item seg1, item seg2) {
        item ret;
        ret.sum = seg1.sum + seg2.sum;
        return ret;
    }

    void build(vector<int> &v,int x, int lx, int rx) {
        if (lx == rx) {
            seg[x] = item(v[lx]);
            return;
        }
        int mid = (lx + rx) / 2;
        int lf = 2 * x + 1, rt = 2 * x + 2;

        build(v,lf, lx, mid);
        build(v,rt, mid + 1, rx);
        seg[x] = merge(seg[lf], seg[rt]);
    }
    void build(vector<int> &v){
        build(v,0, 0, n-1);
    }

    void propagate(int x, int lx, int rx) {
        if (seg[x].lz != NO_OP) {
            seg[x].sum = seg[x].lz * (rx - lx + 1);
            int lf = 2*x+1,rt = 2*x+2;
            if (lx != rx) {
                seg[lf].lz += seg[x].lz;
                seg[rt].lz += seg[x].lz;
            }
            seg[x].lz = NO_OP;
        }
    }

    void update(int l,int r, ll val, int x, int lx, int rx) {
        propagate(x, lx, rx);
        if (l > rx || r < lx)
            return;
        if (l <= lx && r >= rx) {
            seg[x].lz += val;
            propagate(x, lx, rx);
            return;
        }
        int mid = (lx + rx) / 2,lf = 2*x+1,rt= 2*x+2;
        update(l, r, val, lf, lx, mid);
        update(l, r, val, rt, mid + 1, rx);
        seg[x] = merge(seg[lf] , seg[rt]);
    }

    void update(int l,int r, ll val) {
        update(l, r, val, 0, 0, n-1);
    }

    item query(int l, int r, int x, int lx, int rx) {
        propagate(x, lx, rx);
        if (l <= lx && r >= rx)
            return seg[x];
        if (l > rx || r < lx)
            return item();

        int mid = (lx + rx) / 2,lf = 2*x+1,rt = 2*x+2;

        return merge(query(l, r, lf, lx, mid) , query(l, r, rt, mid + 1, rx));
    }

    item query(int l, int r) {
        return query(l, r, 0, 0, n-1);
    }
};