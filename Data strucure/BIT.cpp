struct BIT
{
    vector<ll>tree;
    BIT(int n)
    {
        tree.resize(n+1);
    }
    ll get(int k)
    {
        ll sum=0;
        while(k>=1)
        {
            sum+=tree[k];
            //LSB(k)=k&-k
            k-= (k&-k);
        }
        return sum;
    }
    void update(int k,int val)
    {
        while(k<tree.size())
        {
            tree[k]+=val;
            //LSB(k)=k&-k
            k+= (k&-k);
        }
    }
    ll query(int a,int b)
    {
        if(a>b)
            swap(a,b);
        return get(b)-get(a-1);
    }
    //get first index with sum >=val
    int BS(ll val)
    {
        int ind=0;
        for (int jump = (1<<(__lg(tree.size()))); jump;jump>>=1) {
            if(ind+jump<tree.size()&&tree[ind+jump]<val)
            {
                val-=tree[ind+jump];
                ind+=jump;
            }
        }
        return ind +1;
    }
};