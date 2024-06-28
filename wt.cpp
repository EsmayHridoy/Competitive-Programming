#include<iostream>
#include<cmath>
#include<cstring>
#include<vector>
#include<map>
#include<algorithm>
#include<queue>
#include<set>
#include<string>
using namespace std;


#define ll long long
#define pb push_back
#define ppb pop_back
#define ins insert


bool check_bit(ll mask,ll pos)
{
    if(mask & (1<<pos)) return true;
    else return false;
}


set<ll>adj[13];

int main()
{
    ll n,m,u,v;
    ll i,j;
    cin>>n>>m;
    for(i=0;i<m;i++){
        cin>>u>>v;
        u--;
        v--;
        adj[u].ins(v);
    }
    ll lim=1<<(n);
    vector<vector<ll>>ans;
    
    ll cnt=0;
    for(ll mask = 1;mask<lim;mask++){
        vector<ll>tans;
        for(ll pos=0;pos<n;pos++){
            if(check_bit(mask,pos))tans.pb(pos);
        }
        ll sz=tans.size();
        
        do{
            cnt++;
            bool fl=true;
           for(i=0;i<sz;i++){
             u=tans[i];
             v=tans[(i+1)%sz];

             if(adj[u].find(v) == adj[u].end()){
                fl=false;
                break;
             }
           }
           if(fl){
            ans.pb(tans);
            break;
           }
        }while(next_permutation(tans.begin(),tans.end()));
    }

    ll sum = 11*12;
    vector<ll>vc;
    vc.clear();
    for(auto v:ans){
        ll s=0;
        for(auto x:v)s+=x;
        if(s<sum){
            vc=v;
            sum=s;
        }
    }

    cout<<cnt<<endl;
    sort(vc.begin(),vc.end());
    for(auto x:vc){
        x++;
        cout<<x<<" ";
    }
    cout<<endl;
    

}