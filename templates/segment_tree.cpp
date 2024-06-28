ll seg_tree[800005];


void update(ll at,ll tl,ll tr,ll pos,ll val)
{
    if(tl == tr){
        seg_tree[at]=val;
    }
    else{
        ll tm=(tl+tr)/2;
        
        if(pos<=tm){
            update(2*at,tl,tm,pos,val);
        }
        else{
            update((2*at)+1,tm+1,tr,pos,val);
        }
        seg_tree[at]=max(seg_tree[2*at],seg_tree[2*at+1]);
    }
}

ll query(ll at,ll tl,ll tr,ll l,ll r)
{
    if(l>r)return 0;
    if(tl == l && tr == r){
        return seg_tree[at];
    }
    ll tm=(tl+tr)/2;
    
    return max(query(2*at,tl,tm,l,min(r,tm)),query(2*at+1,tm+1,tr,max(l,tm+1),r));
}