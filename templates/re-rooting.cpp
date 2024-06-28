void reroot(int x , int y) {
    children[x] -= children[y];
    children[y] += children[x];
}
 
void dfs1(ll node,ll pr)
{   // debug() , dbg(children) , dbg(node);
    ll add=0,mi=0;
    for(auto child:graph[node]){
        add+=children[child];
        x=children[child];
        x*=children[child];
        x%=mod;
        mi+=x;
        mi%=mod;
    }
    add*=add;
    add%=mod;
 
    ll ret=(mod+add-mi)%mod;
    ret*=ModInv(2LL,mod);
    ret%=mod;
    ans+=ret;
    ans%=mod;
    ans+=(n-1);
    ans%=mod;
    
    for(auto child:graph[node]){
        if(child == pr)continue;
        reroot(node , child);
        dfs1(child,node);
        reroot(child , node);   
    }
 
 
}