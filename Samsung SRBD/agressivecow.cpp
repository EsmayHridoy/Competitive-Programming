/*
https://paste.ubuntu.com/p/ZtGjSfVwTV/
https://ide.codingblocks.com/s/16346
https://www.youtube.com/watch?v=TC6snf6KPdE
*/

/*
You are given an array of integers which represents positions available and an integer c(cows).
Now you have to choose c positions such that minimum difference between cows is maximized.
For example,
5 3
1 3 5 8 10
c=3

Output: 4
1 5 10
*/


#include<iostream>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<unordered_map>



using namespace std;


int main()
{
    int n;
    int c;
    cin>>n>>c;
    vector<int>vc;

    for(int i = 0;i<n;i++){
        int x;
        cin>>x;
        vc.push_back(x);
    }
    int lo = 0, hi = 1e9+9;
    int mid;
    int ans = 0;
    sort(vc.begin(),vc.end());
    while(lo<=hi){
        mid = (lo+hi)/2;

        int i=0;
        int j=1;
        int cnt = 1;
        while(j<n){
            int dis = abs(vc[i]-vc[j]);

            if(dis>=mid){
                cnt++;
                i=j;
                j++;
            }
            else j++;

            if(cnt == c)break;
        }

        if(cnt == c){
            lo=mid+1;
            ans=max(ans,mid);
        }
        else{
            hi=mid-1;
        }

    }


    cout<<ans<<endl;
}