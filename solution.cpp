#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
#include <iterator>
#include <set>
#include<map>
#include<unordered_map>


using namespace std;



/*
Given below are the raw materials quantities and their respective selling price(if sold as raw).

D --> No of CPUs
E --> No of memory chips
F --> No of boards
d --> Selling price of CPU
e --> Selling price of Memory chips

We are given N Computer configurations like below : 
Di, Ei, Fi, SPi, which are the CPU, Chips, Boards and one unit selling price for ith computer respectively.
Our task is to maximize the final cost.
Constraints:
1. Can use at Max 3 different Configurations
2. We can use 1 configuration multiple times
3. Remaining Inventories can be sold on its selling price

Input:
T --> Number of test cases.
D E F d e --> Inventories
N --> Total Configuration Count
Di Ei Fi SPi
...
Dn En Fn SPn

1<=T<=10
1<= D, E, F <= 100
1<= d, e <=100000
1<=N<=8

Output:
First Line print the Case #testCaseNumber
Second Line Print Maximum Cost per test case in each line.

Sample Input:
1 --> Total Test Case
10 10 10 2 1 --> D E F d e
1 --> PC Configuration Count
1 2 2 3 --> D1 E1 F1 SP1

Sample Output:
Case #1
30
*/
int D,E,F,d,e;
int N;


int ans=0;
struct Config
{
    int D,E,F,SP;
};


vector<Config>vc;



void solve(int pos,int conf, int D, int E, int F, int rev)
{
    if(pos == N)
    {
        rev+=((D*d)+(E*e));
        ans=max(rev,ans);
        return;
    }

    if(conf == 3){
        rev+=((D*d)+(E*e));
        ans=max(rev,ans);
        return;
    }

    int cnt = 1;
    while(D>=cnt*vc[pos].D && E>=cnt*vc[pos].E && F>=cnt*vc[pos].F){
        solve(pos+1,conf+1,D-(cnt*vc[pos].D),E-(cnt*vc[pos].E),F-(cnt*vc[pos].F),rev+(cnt*vc[pos].SP));
        cnt++;
    }
    solve(pos+1,conf,D,E,F,rev);
    return;
}



int main()
{
    int T;
    cin>>T;

    int Case = 1;

    while(T--){
        
        cin>>D>>E>>F>>d>>e;
        
        cin>>N;
        vc.clear();
        Config var;
        for(int i=0;i<N;i++){
            cin>>var.D>>var.E>>var.F>>var.SP;
            vc.push_back(var);
        }
        ans=0;
        solve(0,0,D,E,F,0);

        cout<<"Case #"<<Case<<endl;
        cout<<ans<<endl;
        
    }
}
