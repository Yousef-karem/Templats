struct item
{
    item (int x)
    {

    }
    int x;
};
item merge (item a,item b)
{

}
item sp[N][LOG];
int BigPow[N],n;
int arr[N];
void con()
{
    for (int j = 0; j < LOG; ++j) {
        for (int i = 0; i+(1<<j)-1 <= n; ++i)
        {
            if(j==0)
                sp[i][j]=item(arr[i]);
            else
                sp[i][j]=merge (sp[i][j-1],sp[i+(1<<(j-1))][j-1]);
        }
    }
    //101 -->10-->1-->0
    BigPow[1]=0;
    for (int i = 2; i <= n; ++i) {
        BigPow[i]=BigPow[i/2]+1;
    }
}
int query(int l,int r)
{
    int len=r-l+1;
    //k=31-__builtin_clz(len);
    int k=BigPow[len];
    return merge (sp[l][k],sp[r-(1<<k)+1][k]);
}