const int e = 100005;
const ll M = 1e9+7;

vector<ll>fact;
vector<ll>invfact;

template<typename T>void mod(T& a , T b)
{
    a = (a%b+b)%b;
}

template<typename T> T mpow(T a , T b)
{
    T ans = 1;
    while(b)
    {
        if(b&1)
        ans = ans*a;
        mod(ans,(T)M);
        a = a*a;
        mod(a,(T)M);
        b>>=1;
    }
    mod(ans,(T)M);
    return ans;
}


template<typename T> T modinv(T a)
{
    return mpow(a,(T)M-2);
}


void factorial()
{
    fact.resize(e);
    invfact.resize(e);
    fact[0] = 1;
    invfact[0] = 1;
    loop(i,1,e)
    {
        fact[i] = fact[i-1]*i;
        mod(fact[i],M);
    }
    loop(i,1,e)
    {
        invfact[i] = modinv(fact[i]);
        mod(invfact[i],M);
    }
}


ll ncr(ll n , ll r)
{
    ll ans ;
    ans = fact[n]*invfact[n-r];
    mod(ans,M);
    ans = ans*invfact[r];
    mod(ans,M);
    return ans;
}
