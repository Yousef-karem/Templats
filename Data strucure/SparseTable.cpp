int sp[N][LOG],BigPow[N],sz;
int arr[N];
void con()
{
    for (int j = 0; j < LOG; ++j) {
        for (int i = 0; i+(1<<j)-1 <= sz; ++i)
        {
            if(j==0)
                sp[i][j]=arr[i];
            else
                //sp[i][j]=do operation (sp[i][j-1],sp[i+(1<<(j-1))][j-1]);
        }
    }
    //101 -->10-->1-->0
    BigPow[1]=0;
    for (int i = 2; i <= sz; ++i) {
        BigPow[i]=BigPow[i/2]+1;
    }
}
int query(int l,int r)
{
    int len=r-l+1;
    //k=31-__builtin_clz(len);
    int k=BigPow[len];
    //return do operation (sp[l][k],sp[r-(1<<k)+1][k]);
}