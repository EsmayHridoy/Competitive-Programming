#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
#include<map>
#include<unordered_map>
#include<set>
#include<string>
#include<queue>
#include<stack>
#include<iterator>

using namespace std;

int i,j;
/*


You want to cut a piece of paper by a certain fixed rule to make some pieces of white or 
blue colored square paper with various sizes.  
 
If the size of the entire paper is N×N (N = 2^K; 1 <= K <= 7; K = natural number), the cutting rules
are as below.
 
‘If the entire piece of paper is not colored the same, cut the middle part horizontally and vertically 
to divide it into the same sized four pieces of paper, 
(N/2)×(N/2), as with I, II, III, IV in < FIG. 2 >. 

For each I, II, III and IV, cut and divide again in the same way if one entire piece of paper 
is not colored the same, and make them into the same sized four pieces of paper. Continue until each and 
every piece of paper has only one color of white or blue.’
 
When you finish, < FIG. 3 > shows the first division of < FIG. 1 > and < FIG. 4 > 
shows the final version of 9 pieces of white paper and 7 pieces of blue paper of various sizes.
 
If the length of an edge of the first given piece of paper, N, and 
the color information (white or blue) inside each square are given, create a calculation program
 that assesses how many white/blue pieces of paper are.
 
Time limit: 1 second (java: 2 seconds) 
 
[Input]
 
Input may include many test cases. The number of test cases, T, is given on the first line of input and then the amount of T of test cases is given in a line. (T <= 30)
The length of an edge of the first given piece of paper, N, is given for the first line of each test case.
From the next line through to the amount of N lines, the color information is given separately as blanks. 0 indicates white and 1 indicates blue.
 
[Output]
 
For each test case, you should print "Case #T" in the first line where T means the case number. 
 
For each test case, you should output the number of white pieces of paper and blue pieces of paper separately as blanks on the first line of each test case.
 
[I/O Example]
Input 
2

8
1 1 0 0 0 0 1 1
1 1 0 0 0 0 1 1
0 0 0 0 1 1 0 0
0 0 0 0 1 1 0 0
1 0 0 0 1 1 1 1
0 1 0 0 1 1 1 1 
0 0 1 1 1 1 1 1
0 0 1 1 1 1 1 1
 
 
16
1 0 0 1 0 0 0 0 0 0 1 1 0 1 1 1
1 1 0 1 0 1 1 0 0 0 0 0 0 0 0 0
0 0 0 0 1 0 1 1 1 1 0 0 1 0 0 1
1 1 0 0 1 0 0 1 0 0 1 0 1 1 1 0
0 1 1 1 0 0 1 1 0 0 1 0 0 1 1 1
1 0 1 1 0 0 0 1 0 1 0 1 0 0 1 1
1 1 1 1 1 1 0 0 1 1 1 1 1 0 0 0
1 1 0 1 0 1 0 0 1 0 1 1 1 0 0 1
1 1 1 1 1 1 0 0 1 0 1 1 0 1 1 0
1 0 0 1 1 1 0 0 0 0 1 1 1 1 0 0
1 0 0 1 1 1 1 0 0 0 1 1 0 1 0 1
1 1 1 0 1 1 0 0 1 1 1 1 1 1 0 1
1 1 1 1 1 1 0 0 0 0 1 1 1 1 0 0
1 1 1 1 1 1 0 1 1 1 1 1 1 1 0 0
1 1 0 0 0 0 0 0 1 1 0 1 1 0 0 0
1 1 0 0 1 1 0 0 0 1 1 1 1 0 0 0
 
 
 
Output
 
Case #1
9 7
 
Case #2
88 99
*/
#include <thread> // Include the thread library
#include <chrono> // Include the chrono library for time functions

void rest(int seconds) {
    std::this_thread::sleep_for(std::chrono::seconds(seconds));
}


struct paper
{
    int x1,y1,sz;
};


int main()
{
    int T;
    cin>>T;
    int cas=1;
    while(T--){
        int n;
        cin>>n;
        int grid[n+2][n+2];
        memset(grid,0,sizeof(grid));
        for(int i = 1; i<=n ; i++){
            for(int j = 1; j<=n; j++){
                int a;
                cin>>a;
                grid[i][j] = a + grid[i - 1][j] + grid[i][j - 1] - grid[i - 1][j - 1];
            }
        }

        
        queue<paper>q;
        paper var;

        

        
        var.x1=1;var.y1=1;var.sz=n;

        q.push(var);


        int w=0,b=0;
        while(!q.empty()){
            var = q.front();
            q.pop();
            int x=var.x1;
            int y=var.y1;
            int sz=var.sz;

            int sum = grid[x+sz-1][y+sz-1];

            sum =sum-grid[x-1][y+sz-1]-grid[x+sz-1][y-1]+grid[x-1][y-1];

            if(sum == 0){
                w++;
                continue;
            }
            if(sum == sz*sz){
                b++;
                continue;
            }

            paper v;
            sz=sz/2;
            v.x1=x;v.y1=y;v.sz=sz;
            q.push(v);

            v.x1=x+sz;v.y1=y;v.sz=sz;
            q.push(v);

            v.x1=x;v.y1=y+sz;v.sz=sz;
            q.push(v);


            v.x1=x+sz;v.y1=y+sz;v.sz=sz;
            q.push(v);
        }


        cout << "Case #" << cas << endl;


        cout<<w<<" "<<b<<endl;


        
    }
}