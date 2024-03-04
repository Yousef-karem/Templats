int n, q, anc[N][30], depth[N];
vector <int> child[N];
void dfs(int u,int p, int d) {
    if(p!=-1)
        anc[u][0]=p;
    depth[u] = d;
    for(int v : child[u]) {
        if(v!=p)
            dfs(v,u, d + 1);
    }
}
void build() {
    for(int k = 1; k < 30; k++) {
        for(int i = 1; i <= n; i++) {
            anc[i][k] = anc[anc[i][k - 1]][k - 1];
        }
    }
}
int lift(int x, int k) {
    for(int bit = 0; bit < 30; bit++) {
        if((1 << bit & k)) {
            x = anc[x][bit];
        }
    }
    return x;
}
int lca(int u, int v) {
    if(depth[u] < depth[v])
        swap(u, v);
    u = lift(u, depth[u] - depth[v]);
    if(u == v)
        return u;
    for(int bit = 29; bit >= 0; bit--) {
        if(anc[u][bit] != anc[v][bit]) {
            u = anc[u][bit];
            v = anc[v][bit];
        }
    }
    return anc[u][0];
}