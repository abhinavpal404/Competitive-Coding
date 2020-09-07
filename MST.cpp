#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define eb emplace
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);
#define loop(i,a,n) for(int i=a;i<n;i++)
#define trav(a,x) for(auto &a:x)
#define pii pair<ll,int>
const int w=1e6+1;
vector<pii>g[w];
vector<int>v(w,0);
ll prim()
{
    ll ans=0;
    priority_queue<pii,vector<pii>,greater<pii>>q;
    q.push({0,1});
    pii p;
    while(!q.empty())
    {
        p=q.top();
        q.pop();
        int j=p.ss;
        if(v[j]==1)
        continue;
        ans+=p.ff;
        v[p.ss]=1;
        for(auto c:g[j])
        {
            if(!v[c.ss])
            {
                 q.push(c);
                 
            }
        }
    }
    return ans;
}
// map<string,int>h;
int main() {
	// your code goes here
	io;
	int t;
	cin>>t;
	while(t--)
	{   int p,n,m;
	    cin>>p>>n>>m;
	    loop(i,0,m)
	    {
	        int a,b,c;
	        cin>>a>>b>>c;
	        g[a].pb({c,b});
	        g[b].pb({c,a});
	    }
	    ll ans=prim();
	}
	return 0;
} 
