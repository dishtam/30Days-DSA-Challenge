class Solution {
    unordered_set<string> st;
    int N;
    vector<int> dp;
public:
    int solve(int idx,string s){
        if(idx>=N) return 0;
        if(dp[idx]!=-1) return dp[idx];
        string temp="";
        int minEx=N;
        for(int i=idx;i<N;i++){
            temp+=s[i];
            int currEx = (st.find(temp)==st.end())?temp.length():0;
            int nextEx = solve(i+1,s);
            int totalEx = currEx + nextEx;
            minEx = min(minEx,totalEx);
        }

        return dp[idx]=minEx;
    }
    int minExtraChar(string s, vector<string>& dict) {
        unordered_set<string> st(dict.begin(),dict.end());
        this->st = st;
        this->N =  s.size();
        dp.resize(51,-1);
        int len = solve(0,s);
        return len;
    }
};
