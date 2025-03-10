class Solution {
    public:
        bool isVowel(char ch){
            return ch == 'a' || ch == 'e' 
            || ch == 'i' || ch == 'o' 
            || ch == 'u';
        }
        long long countOfSubstrings(string word, int k) {
            int i,n=word.size();
            long long ans=0;
            int freq[n][26];
            memset(freq,0,sizeof(freq));
            vector<int>conso(n,0);
            for(i=0;i<n;i++){
                if(isVowel(word[i])){
                    freq[i][word[i]-'a']++;
                }
                else{
                    conso[i]++;
                }
                if(i>0){
                    conso[i]+=conso[i-1];
                    freq[i]['a'-'a']+=freq[i-1]['a'-'a'];freq[i]['e'-'a']+=freq[i-1]['e'-'a'];
                    freq[i]['i'-'a']+=freq[i-1]['i'-'a'];freq[i]['o'-'a']+=freq[i-1]['o'-'a'];
                    freq[i]['u'-'a']+=freq[i-1]['u'-'a'];
                }
                int lo=0,hi=i,mid;
                int l=-1;
                while(lo<=hi){
                    mid=(lo+hi)/2;
                    int pre=0;
                    if(mid>0){
                        pre=conso[mid-1];
                    }
                    if(conso[i]-pre>k){
                        lo=mid+1;
                        
                    }
                    else{
                        hi=mid-1;
                        l=mid;
                    }
                }
                if(l == -1)continue;
                lo=l;hi=i;
                int r=-1;
                while(lo<=hi){
                    mid=(lo+hi)/2;
                    int preC = 0;
                    int preA = 0;
                    int preE = 0;
                    int preI = 0;
                    int preO = 0;
                    int preU = 0;
                    if(mid>0){
                        preC = conso[mid-1];
                        preA = freq[mid-1]['a'-'a'];
                        preE = freq[mid-1]['e'-'a'];
                        preI = freq[mid-1]['i'-'a'];
                        preO = freq[mid-1]['o'-'a'];
                        preU = freq[mid-1]['u'-'a'];
                    }
                    if(conso[i]-preC == k && 
                    freq[i]['a'-'a']-preA && freq[i]['e'-'a']-preE && freq[i]['i'-'a']-preI
                    && freq[i]['o'-'a'] - preO && freq[i]['u'-'a']-preU){
                        lo=mid+1;
                        r=mid;
                    }
                    else{
                        hi=mid-1;
                    }
                }
                if(r == -1)continue;
                ans+=(r-l+1);
            }
    
            return ans;
        }
    };