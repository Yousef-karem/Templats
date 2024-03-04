struct DSU
{
    vector<int>parent,sz;
    DSU(int n)
    {
        parent=sz=vector<int>(n);
        fr(n)
        {
            parent[i]=i;
            sz[i]=1;
        }
    }
    int find(int x)
    {
        if(parent[x] == x)
            return x;

        return parent[x] = find(parent[x]);
    }
    void uni(int x,int y)
    {
        x=find(x);
        y=find(y);
        if(x==y)
            return;
        if(sz[y]>sz[x])
            swap(x,y);
        parent[y]=x;
        sz[x]+=sz[y];
    }
};