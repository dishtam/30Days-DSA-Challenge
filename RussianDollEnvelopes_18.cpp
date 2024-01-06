class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(),envelopes.end(),[](vector<int>& a,vector<int>& b){
            if(a[0]==b[0]) return a[1]>b[1];
            return a[0]<b[0];
        });
        vector<int> LIS;
        LIS.push_back(envelopes[0][1]);
        int len=1;
        for(int i=1;i<envelopes.size();i++){
            if(envelopes[i][1]>LIS.back()){
                LIS.push_back(envelopes[i][1]);
                len++;
            }
            else{
                int idx = lower_bound(LIS.begin(),LIS.end(),envelopes[i][1])-LIS.begin();
                LIS[idx] = envelopes[i][1];
            }
        }
        return len;
    }
};
