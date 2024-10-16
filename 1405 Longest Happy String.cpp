class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        string ret;
        ret.clear();        
        priority_queue<pair<int,char>>pq;
        pq.push({a,'a'});
        pq.push({b,'b'});
        pq.push({c,'c'});

        while (1) {
            auto p = pq.top();
            pq.pop();
            int use_p = min(2, p.first);
            for (int i = 0; i < use_p; i++) {
                ret.push_back(p.second);
            }
            p.first -= use_p;
            auto q = pq.top();
            pq.pop();
            auto r = pq.top();
            pq.pop();
            if(!r.first && !q.first)break;
            int sum = (q.first + r.first);
            int cnt = p.first / sum;
            if(p.first%sum)cnt++;
            if(cnt>1){
                q.first-=1;
                ret.push_back(q.second);
                pq.push(q);
                pq.push(r);
            }
            else{
                int use_q = min(2,q.first);
                q.first-=use_q;
                for(int i=0;i<use_q;i++){
                    ret.push_back(q.second);
                }
                pq.push(q);
                pq.push(r);
            }
            pq.push(p);
        }

        return ret;
    }
};
