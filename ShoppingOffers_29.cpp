class Solution {
public:
    int solve(int idx,vector<int>& prices,vector<vector<int>>& special,vector<int> needs){
        if(idx==special.size()){
            int res=0;
            for(int i=0;i<needs.size();i++){
                res += needs[i]*prices[i];
            }
            return res;
        }
        // reject offer
        int reject = solve(idx+1,prices,special,needs);
        // apply offer
        for(int i=0;i<needs.size();i++){
            needs[i]=needs[i]-special[idx][i];
            if(needs[i]<0) return reject;
        }
        int accept = special[idx][needs.size()]  + solve(idx,prices,special,needs);
        return min(accept,reject);
    }
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        return solve(0,price,special,needs);
    }
};
