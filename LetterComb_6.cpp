class Solution {
private:
    vector<string> keyboard={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
public:
    void solve(int idx,string digits,string temp,vector<string>& ans){
        if(idx==digits.size()){
            ans.push_back(temp);
            return;
        }
        for(int i=0;i<keyboard[digits[idx]-'0'].size();i++){
            temp.push_back(keyboard[digits[idx]-'0'][i]);
            solve(idx+1,digits,temp,ans);
            temp.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if(digits.size()==0) return ans;
        solve(0,digits,"",ans);
        return ans;
    }
};
