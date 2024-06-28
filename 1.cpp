/*In (or with) the name of Allah, the Beneficent, the Merciful.*/

// #pragma GCC optimize("Ofast,unroll-loops")
// #pragma GCC target("avx,avx2,fma")

#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;


#define ull unsigned long long
#define koyta_choto order_of_key
#define kothay_ache find_by_order
#define eb emplace_back
#define umap unordered_map
#define pi acos(-1)
//#define ll long long
#define SQR(a) (a)*(a)
#define ll int
#define pb push_back
#define pf push_front
#define ins insert
#define ppb pop_back
#define ppf pop_front
#define SORT(a) sort(a.begin(),a.end());
#define SORTg(a) sort(a.begin(),a.end(),greater<ll>());
#define REV(a) reverse(a.begin(),a.end());
#define FOR(it,vc) for(auto it = vc.begin();it= vc.end();it++;)
#define ff first
#define ss second
#define fastio {ios_base::sync_with_stdio(false);cin.tie(NULL);}
#define f_inout freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#define endl "\n"
#define SQR(a) (a)*(a)

bool flag,fl;
ll tot,a,b,c,d,e,g,h,i,j,f,k,l,m,n,o,q,p,r,ind,t,u,num,v,w,s,x,y,z,cnt,ans,sum,sz,num_comp,bp,dif,cas=1;
string str,s1,s2,s3;
#define Case cout<<"Case "<<cas<<": ";cas++;
ll lo,hi,mid;


#define Gene template< class
#define Rics printer& operator,
Gene c > struct rge {c b, e;};
Gene c > rge<c> range(c i, c j) { return {i, j};}
struct printer {
    ~printer() {cerr << endl;}
    Gene c > Rics(c x) { cerr << boolalpha << x; return *this;}
    Rics(string x) {cerr << x; return *this;}
    Gene c, class d > Rics(pair<c, d> x) { return *this, "(", x.first, ", ", x.second, ")";}
    Gene ... d, Gene ... > class c > Rics(c<d...> x) { return *this, range(begin(x), end(x));}
    Gene c > Rics(rge<c> x) {*this, "["; for (auto it = x.b; it != x.e; ++it)*this, (it == x.b ? "" : ", "), *it; return *this, "]";
    }
};
#define debug() cerr<<"LINE "<<__LINE__<<" >> ", printer()
#define dbg(x) "[",#x,": ",(x),"] "
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int my_rand(int l, int r) {
    return uniform_int_distribution<int>(l, r) (rng);
}
bool checkbit(int mask,int bit){return mask & (1<<bit);}
int setbit(int mask,int bit){ return mask | (1<<bit) ; }
int clearbit(int mask,int bit){return mask & ~(1<<bit);}
int togglebit(int mask,int bit){return mask ^ (1<<bit);}
int bitno(int mask) {return (int)__builtin_popcount(mask);}

inline ll Floor(ll p, ll q) {return p > 0 ? p / q : p / q - !!(p % q);}
inline ll Ceil(ll p, ll q)  {return p < 0 ? p / q : p / q + !!(p % q);}

template <typename T> T BigMod (T b, T p, T m) {if (p == 0) return 1; if (p % 2 == 0) {T s = BigMod(b, p / 2, m); return ((s % m) * (s % m)) % m;} return ((b % m) * (BigMod(b, p - 1, m) % m)) % m;}
template <typename T> T ModInv (T b, T m) {return BigMod(b, m - 2, m);}
template <typename T> T POW(T B, T P) { if (P == 0) return 1; if (P & 1) return B * POW(B, P - 1);  else return SQR(POW(B, P / 2));}
template <typename T> T Dis(T x1, T y1, T x2, T y2) {return sqrt( SQR(x1 - x2) + SQR(y1 - y2) );}
template <typename T> T Angle(T x1, T y1, T x2, T y2) { return atan( double(y1 - y2) / double(x1 - x2));}
template <typename T> T gcd(T a, T b) {if (a < 0)return gcd(-a, b); if (b < 0)return gcd(a, -b); return (b == 0) ? a : gcd(b, a % b);}
template <typename T> T lcm(T a, T b) {if (a < 0)return lcm(-a, b); if (b < 0)return lcm(a, -b); return a * (b / gcd(a, b));}
template <typename T> T euclide(T a, T b, T &x, T &y) {if (a < 0) {T d = euclide(-a, b, x, y); x = -x; return d;}   if (b < 0) {T d = euclide(a, -b, x, y); y = -y; return d;}   if (b == 0) {x = 1; y = 0; return a;} else {T d = euclide(b, a % b, x, y); T t = x; x = y; y = t - (a / b) * y; return d;}}
template <typename T> void ia (T a[], int n) {for (int i = 0; i < n; i++) cin >> a[i];}
template <typename T> void pa (T a[], int n) {for (int i = 0; i < n - 1; i++) cout << a[i] << " "; cout << a[n - 1] << endl;}
template <typename T> ll isLeft(T a, T b, T c) { return (a.x - b.x) * (b.y - c.y) - (b.x - c.x) * (a.y - b.y);}

template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

///********************************MY CODE STARTS HERE********************************///




int main()
{
    fastio;
    
#ifndef ONLINE_JUDGE
     freopen("input.cpp", "r", stdin);
     //freopen("output.cpp" , "w" , stdout);
#endif
    

    ll T=1;
    cin>>T;
    while(T--){    
        ll cost;
        cin>>n>>cost;
        vector<pair<ll,ll>>vc;
        ans = n;
        for(i=0;i<n;i++){
            cin>>x;
            vc.pb({x,i});
        }
        sum = 0;
        for(i=1;i<n;i++){
            sum+=vc[i].ff*vc[0].ff;
        }
        if(sum<=cost){
            cout<<1<<endl;
            continue;
        }
        SORT(vc);
        
        unordered_map<ll,bool>mark;

        for(i=0;i<n;i++){
            
            for(j=0;j<n;j++){
                if(mark[vc[j].ss]){
                    cost+=(vc[j].ff * vc[i].ff);
                    continue;
                }
                if(vc[i].ss == vc[j].ss)continue;

                ll tcost = vc[i].ff*vc[j].ff;
                cost-=tcost;
            }

            if(cost>=0){
                if(vc[i].ss == 0){
                    ans = 1;
                    break;
                }
                mark[vc[i].ss]=true;
                ans--;
            }
            else{
                break;
            }
        }
        

        cout<<ans<<endl;


    }
    return 0;
}