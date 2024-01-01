class Solution {
public:
    using ll = long long;
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        vector<int> ans;
        int n = nums[0].size();
        for(auto q:queries){
            int k=q[0],t=q[1];
            priority_queue<pair<string,int>> pq;
            for(int i=0;i<nums.size();i++){
                string num = nums[i].substr(n-t,t); // starting from pos n-t to the end    
                if(pq.size()<k) pq.push({num,i}); // in cases of strings, it is stored in lexographically order
                else{
                    if(pq.top().first>num){
                        pq.pop();
                        pq.push({num,i});
                    }
                }
            }
            ans.push_back(pq.top().second);
        }
        return ans;
    }
};
