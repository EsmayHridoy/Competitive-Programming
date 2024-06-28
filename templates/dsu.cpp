///// for disjoint union set
ll parent[200005],tree_size[200005];
ll find_parent(ll xx){
    if(parent[xx]==xx)return xx;
    parent[xx]=find_parent(parent[xx]);
    return parent[xx];
}
 
void set_dsu(ll n)
{
    for(ll i=0;i<=n;i++){
        parent[i]=i;
        tree_size[i]=1;
    }
    num_comp=n;
    return;
}
void dsu(ll x,ll y)
{
    ll u=find_parent(x);
    ll v=find_parent(y);
    if(u==v)return;
    if(tree_size[u]<tree_size[v])swap(u,v);
    tree_size[u]+=tree_size[v];
    parent[v]=u;
    num_comp--;
    return;
}
pair<ll,pair<ll,ll>>pp;
/////// for disjoint union set****** 