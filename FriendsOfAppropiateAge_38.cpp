class Solution {
public:
    int numFriendRequests(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int ans=0;

        for(int i=0;i<n;i++){
            int low_bound = nums[i]/2 + 8;
           auto low_idx = lower_bound(nums.begin(),nums.end(),low_bound);
           auto high_idx = upper_bound(nums.begin(),nums.end(),nums[i]);
           int req = distance(low_idx,high_idx)-1;
           ans += max(req,0);
        }
        return ans;
    }
};
