class Solution {
public:
    int ans = 0;
    bool isPalindrome(string s){
        int l = 0, h = s.size()-1;
        while(l<=h){
            if(s[l]!=s[h]) return false;
            l++;
            h--;
        }
        return true;
    }
    void solve(int idx,string& s,string& s1,string& s2){
        if(idx==s.size()){
            if(isPalindrome(s1) && isPalindrome(s2)){
               ans = max(ans,int(s1.length())*int(s2.length()));
            }
            return;
        }
        
        s1.push_back(s[idx]);
        solve(idx+1,s,s1,s2);
        s1.pop_back();

        s2.push_back(s[idx]);
        solve(idx+1,s,s1,s2);
        s2.pop_back();

        solve(idx+1,s,s1,s2);
    }
    int maxProduct(string s) {
        string s1="",s2="";
        solve(0,s,s1,s2);
        return ans;
    }
};
// generate two strings 
