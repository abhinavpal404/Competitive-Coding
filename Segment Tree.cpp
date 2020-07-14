struct data
{
    ll m,c;
};
struct SegTree
{
    int N;
    vector<data>val;
    
    data neutral = {INF,0};
    data merge(data a, data b)
    {
        if(a.m<b.m) return {a.m,a.c};
        if(a.m>b.m) return {b.m,b.c};
        return {a.m,a.c+b.c};
    }
    
    data single(int v)
    {
        return {v,1};
    }
    
    void init(int n)
    { 
        N = 1;
        while(N<n)
        N*=2;
        val.resize(2*N);
    }
    
    
    void build(vector<ll> &a , int x , int lx , int rx)
    {
        if(rx - lx == 1)
        {
            if(lx < (int)a.size())
            {
                val[x] = single(a[lx]);
            }
            return;
        }
        int m = (lx + rx)/2;
        build(a , 2*x+1 , lx , m);
        build(a , 2*x+2 , m , rx);
        val[x] = merge(val[2*x+1] , val[2*x+2]);
    }



    void update(int i , int v , int x , int lx , int rx)
    {
        if (rx-lx == 1)
        {
            val[x] = single(v);
            return;
        }
        int m = (rx+lx)/2;
        if(i<m)
        {
            update(i, v, 2*x+1 , lx , m);
        }
        else
        {
            update(i , v , 2*x+2 , m ,rx);
        }
        val[x] = merge(val[2*x+1] , val[2*x+2]);
    }



    data query(int l ,int r , int x , int lx ,int rx)
    {
        if(lx >= r || rx <= l)
        return neutral;
        
        if(lx >= l && rx <= r)
        return val[x];

        int m = (lx+rx)/2;
        
        data left = query(l, r, 2*x+1, lx, m);
        data right = query(l, r, 2*x+2, m, rx);
        
        data cur = merge(left , right);
        return cur;
    }

    
    data query(int l ,int r)
    {
        return query(l,r,0,0,N);
    }
    void update(int i ,int v)
    {
        update(i,v,0,0,N);
    }
    void build(vector<ll>& a)
    {
        build(a,0,0,N);
    }
};
