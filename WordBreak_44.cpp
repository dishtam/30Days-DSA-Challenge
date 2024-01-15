class Solution {
    unordered_set<string> st;
    vector<int> dp;
public:
    bool solve(int idx,string s){
        if(idx==s.size()) {
            return 1;
        }
        if(dp[idx]!=-1) return dp[idx];
        string temp="";

        for(int i=idx;i<s.size();i++){
            temp+=s[i];
            if(st.find(temp)!=st.end()){
                if(solve(i+1,s)) return dp[idx]=1;
            }
        }
        return dp[idx]=0;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> st(wordDict.begin(),wordDict.end());
        this->st = st;   
        dp.resize(s.size(),-1); 
        return solve(0,s);
    }
};
