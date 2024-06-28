#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

// Define constants
#define pie 3.14159265358979323846
#define int long long
#define pb push_back
#define pf push_front
#define ins insert
#define ppb pop_back
#define ppf pop_front
#define sf(x) double x;cin >> x;
#define sc(x) int x;cin >> x;
#define sn(x) cin >> x;
#define prt printf
#define scf scanf
#define SORT(a) sort(a.begin(),a.end());
#define SORTg(a) sort(a.begin(),a.end(),greater<int>());
#define REV(a) reverse(a.begin(),a.end());
#define FOR(it,vc) for(auto it = vc.begin();it != vc.end();it++)
#define ff first
#define ss second
#define fastio {ios_base::sync_with_stdio(false);cin.tie(NULL);}
#define f_inout freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
int num_comp = 0,n,m,q,x,y,w,u,v;
pair<int, int> p;

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

vector<int> adj[100000];
map<int, int> parent, tree_size, vis, tvis;

// Function to find the parent of a set
int find_parent(int xx) {
    if(parent[xx] == xx) return xx;
    parent[xx] = find_parent(parent[xx]);
    return parent[xx];
}

// Function to initialize disjoint set data structure
void set_dsu(int n) {
    for(int i = 0; i <= n; i++) {
        parent[i] = i;
        tree_size[i] = 1;
    }
    num_comp = n;
    return;
}

// Function to perform union operation in disjoint set
void dsu(int x, int y) {
    int u = find_parent(x);
    int v = find_parent(y);
    if(u == v) return;
    if(tree_size[u] < tree_size[v]) swap(u, v);
    tree_size[u] += tree_size[v];
    parent[v] = u;
    num_comp--;
    return;
}

pair<int, pair<int, int>> pp;

int32_t main() {
    fastio;
    // Input the number of nodes, edges, and queries
    cin >> n >> m >> q;
    
    // Initialize disjoint set data structure
    set_dsu(n);
    
    // Vector to store edges and queries
    vector<pair<int, pair<int, int>>> vc, tm;
    
    // Input edges
    for(int i = 0; i < m; i++) {
        cin >> x >> y >> w;
        if(x > y) swap(x, y);
        p = make_pair(x, y);
        pp = make_pair(w, p);
        vc.pb(pp);
    }
    
    // Map to store the count of queries for each edge
    map<pair<int, pair<int, int>>, int> mp;
    
    // Input queries
    for(int i = 0; i < q; i++) {
        cin >> x >> y >> w;
        if(x > y) swap(x, y);
        p = make_pair(x, y);
        pp = make_pair(w, p);
        vc.pb(pp);
        tm.pb(pp);
        mp[pp]++;
    }

    // Sort edges and queries based on weights
    SORT(vc);
    
    // Process edges and update disjoint set
    for(int i = 0; i < m + q; i++) {
        u = find_parent(vc[i].ss.ff);
        v = find_parent(vc[i].ss.ss);
        if(u == v) {
            mp[vc[i]] = 0;
            continue;
        }
        if(mp[vc[i]]) {
            mp[vc[i]]++;
            continue;
        }
        dsu(vc[i].ss.ff, vc[i].ss.ss);
    }
    
    // Output the result for each query
    for(int i = 0; i < q; i++) {
        if(mp[tm[i]]) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }
    
    return 0;
}
