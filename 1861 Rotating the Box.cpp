// 1861. Rotating the Box
// Runtime Beats 96.25%
// Memory Beats 85.37%

class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int n=box.size();
        int m=box[0].size();
        int i,j;
        vector<vector<char>>ret(m,vector<char>(n,'.'));
        int k=m-1;
        for(i=0;i<n;i++){
            k=m-1;
            for(j=m-1;j>=0;j--){
                if(box[i][j] == '#'){
                    box[i][j]='.';
                    box[i][k]='#';
                    k--;
                    continue;
                }
                else if(box[i][j] == '*'){
                    k=j-1;
                    continue;
                }
            }
        }
        for(i=0;i<m;i++){
            for(j=0;j<n;j++){
                ret[i][j]=box[n-j-1][i];
            }
        }
        return ret;
    }
};