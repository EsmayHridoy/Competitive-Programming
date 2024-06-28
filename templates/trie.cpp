const int N = 1e6+100;

int to[N][26];
int tot_nodes = 1;
int Cnt[N+3];


void add_string(string &str)
{
    int cur = 1;
    Cnt[cur]++;
    for(auto c:str){
        int ch = c-'a';
        if(!to[cur][ch]){
            to[cur][ch] = ++tot_nodes;
        }
        cur = to[cur][ch];
        Cnt[cur]++;
    }

}

int query(string &str){
    int cur = 1;
    for(auto c:str){
        int ch=c-'a';
        if(!to[cur][ch])return 0;
        cur = to[cur][ch]; 
    }

    return Cnt[cur];
}
