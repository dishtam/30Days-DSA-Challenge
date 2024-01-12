class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        unordered_map<int,int> mp;
        int ans = 0,n=nums.size();
        if(k!=0){
            mp[nums[0]]++;
            for(int i=1;i<n;i++){
                if(nums[i]==nums[i-1]){
                    continue;
                }
                if(mp.find(nums[i]-k)!=mp.end()) ans ++;
                mp[nums[i]]++;
            }
        }
        else{
            for(auto num:nums){
                mp[num]++;
            }
            for(auto x:mp){
                if(x.second>1) ans++;
            }
        }
        return ans;
    }
};
