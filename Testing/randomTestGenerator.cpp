#include<bits/stdc++.h>

using namespace std;


int randomNumberBetwee(int a, int b){
    if(a>b)
        swap(a,b);
    return a + rand()%(b - a + 1);
}
int main(int argc, char* argv[]){
    srand(atoi(argv[1]));
    int t = randomNumberBetwee(1,10);
    t=1;
    cout<<1<<endl;
    while(t--){
        int n = randomNumberBetwee(2,25);
        cout<<n<<endl;

        
    }

    

}