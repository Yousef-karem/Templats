bool prime[N+1];
vector<ll> primes;
void sieve(){
    memset(prime, true, sizeof(prime));
    prime[2] = true;
    for(int p = 2; p <= N; p++){
        if(prime[p]){
            primes.push_back(p);
            for (int i = p * 2; i <= N; i += p){
                prime[i] = false;
            }
        }
    }
}

int spf[N];
void sieveSPF(){
    fr(N)
        spf[i] = i;

    for(int p = 2; p < N; p++){
        if(spf[p] == p){
            for(int i = p * 2; i <= N; i+= p)
                if(spf[i] == i)
                    spf[i] = p;
        }
    }
}
map<ll, int> factorization;
void factorize(ll x){
    for(auto p : primes){
        if(p * p > x)
            break;

        while(x%p == 0){
            factorization[p]++;
            x/=p;
        }
    }
    if(x != 1)
        factorization[x]++;
}
vector<ll>divisors;
vector<pair<ll,int>>factors;
void getDivisors(int ind, ll div){
    if(ind == factors.size()){
        divisors.push_back(div);
        return;
    }
    for(int i = 0; i <= factors[ind].second; i++){
        getDivisors(ind+1, div);
        div*= factors[ind].first;
    }
}
bool is_prime(int x)
{
    for(int i=2;i*i<=x;i++)
    {
        if(x%i==0)
            return false;
    }
    return true;
}
ll fastpow(ll n, ll m) {
    ll ret = 1;
    while (m) {
        if (m & 1)
            (ret *= n) %= mod;
        (n *= n) %= mod;
        m /= 2;
    }
    return ret;
}
int modInverse(ll A)
{
    return fastpow(A,mod-2)%mod;
}