// 1106. Parsing A Boolean Expression
// Cpp Solution


class Solution {
public:
    bool parseBoolExpr(string expression) {
        vector<char>Oper,Val;
        for(auto &ch:expression){
            if(ch == ',')continue;
            else if(ch == '!' || ch == '|' || ch == '&'){
                Oper.push_back(ch);
            }
            else if(ch == 't' || ch == 'f' || ch == '('){
                Val.push_back(ch);
            }
            else{
                bool fl=false;
                if(Oper.back() == '|'){
                    fl=false;
                    while(Val.back() != '('){
                        if(Val.back() == 't')fl|=true;
                        else if(Val.back() == 'f')fl|=false;
                        Val.pop_back();
                    }
                    Val.pop_back();
                    if(fl)Val.push_back('t');
                    else Val.push_back('f');
                }
                else if(Oper.back() == '&'){
                    fl=true;
                    while(Val.back() != '('){
                        if(Val.back() == 't')fl&=true;
                        else if(Val.back() == 'f')fl&=false;
                        Val.pop_back();
                    }
                    Val.pop_back();
                    if(fl)Val.push_back('t');
                    else Val.push_back('f');
                }
                else{
                    while(Val.back() != '('){
                        if(Val.back() == 'f')fl=true;
                        else if(Val.back() == 't')fl=false;
                        Val.pop_back();
                    }
                    Val.pop_back();
                    if(fl)Val.push_back('t');
                    else Val.push_back('f');
                }
                Oper.pop_back();
            }
        }

        if(Val.back() == 'f')return false;

        return true;
    }
};