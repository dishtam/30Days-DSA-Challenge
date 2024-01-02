class Solution {
public:
    void solve(int start,int k,int n,vector<int> temp,vector<vector<int>>& ans,vector<int>& vis){
        if(n<0) return;
        if(temp.size()==k && n==0){
            ans.push_back(temp);
            return;
        }
        
        for(int i=start;i<=9;i++){
            if(vis[i]==0){
                vis[i]=1;
                temp.push_back(i);
                solve(i+1,k,n-i,temp,ans,vis);
                temp.pop_back();
                vis[i]=0;
            }
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> temp,vis(10,0);
        vector<vector<int>> ans;
        solve(1,k,n,temp,ans,vis);
        return ans;
    }
};
