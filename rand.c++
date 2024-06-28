#include<bits/stdc++.h>
using namespace std;
#define pie acos(-1)
#define ll long long
#define pb push_back
#define pf push_front
#define ins insert
#define ppb pop_back
#define ppf pop_front
#define sf(x) double x;scanf("%lf",&x);
#define sc(x) ll x;scanf("%lld",&x);
#define sn(x) scanf("%lld",&x);
#define prt printf
#define scf scanf
#define SORT(a) sort(a.begin(),a.end());
#define REV(a) reverse(a.begin(),a.end());
#define FOR(it,vc) for(auto it = vc.begin();it= vc.end();it++;)
ll fac(ll n){ll m=1;for(ll i=1;i<=n;i++){m=m*i;}return m;}
ll gcd(ll x,ll y){if(x>y)swap(x,y);ll md;while(1){md=y%x;if(md==0)break;y=x;x=md;}return x;}
ll nCr(ll n,ll r){ll rs=(fac(n))/(fac(r)*fac(n-r));return rs;}
ll nPr(ll n,ll r){ll rs=fac(n)/fac(n-r);return rs;}
int64_t big  = 1000000007;
int64_t bigmod(int64_t a,int64_t b,int64_t c){if(b==0){return 1;}if(b%2==0){int64_t vl=bigmod(a,b/2,c);return (vl*vl)%c;}else if(b%2==1){int64_t x=a%c;int64_t y=bigmod(a,b-1,c);return (x*y)%c;}}
#define IO ios_base::sync_with_stdio(false);cin.tie(NULL);
char ar[30][30];
int gx[]={1,-1,0,0};
int gy[]={0,0,1,-1};
map<ll,ll>vis,lvl,sub;
vector<ll>adj[200005];
vector<ll>dpt;
ll n;
ll cnt=0;



void bfs(ll x){
    queue<ll>q;
    ll u;
    q.push(x);
    while(!q.empty()){
        u=q.front();
        q.pop();
        ll sz=adj[u].size();
        vis[u]++;
        if(cnt==lvl[u]){
            cnt++;
        }

        for(ll i=0;i<sz;i++){
            ll v=adj[u][i];
            if(vis[v])continue;
            q.push(v);
            vis[v]++;
            lvl[v]+=cnt;
        }
    }
}
void dfs(ll nd, ll f){

    //sub[nd]+=adj[nd].size();
    //if(nd!=1)sub[nd]--;
    for(ll i=0;i<adj[nd].size();i++){
        ll v=adj[nd][i];
        if(v==f)continue;
        dfs(v,nd);
        sub[nd]+=sub[v];
    }
    dpt.pb(lvl[nd]-sub[nd]);
    sub[nd]++;
}

int main()
{
    cin>>n;sc(in);
    for(ll i=0;i<n-1;i++){
        sc(a)sc(b);
        adj[a].pb(b);
        adj[b].pb(a);
    }

    bfs(1);
    dfs(1,0);
    SORT(dpt);
    REV(dpt);



    ll sum=0;
    for(ll i=0;i<in;i++){
        sum+=dpt[i];
    }

    printf("%lld\n",sum);
    return 0;
}