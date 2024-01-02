class Solution{   
public:
    void reverse(string& s,int i,int j){
        while(i<j){
            swap(s[i++],s[j--]);
        }
    }
    string printMinNumberForPattern(string S){
        // code here 
        int n = S.size();
        string ans="";
        for(int i=1;i<=n+1;i++) ans += i+'0';
        for(int i=0;i<n;i++){
            int j=i;
            while(S[j]=='D') j++;
            reverse(ans,i,j);
            i=j;
        }
        return ans;
    }
};
