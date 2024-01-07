class Solution {
public:
    int solve(vector<int>& nums,int mid){
        int cnt = 0;
        for(int i=0;i<nums.size();i++){
            cnt += abs(mid-nums[i]);
        }
        return cnt;
    }
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        if(n<=1) return 0;
        if(n%2==0)
            return min(solve(nums,nums[n/2]),solve(nums,nums[(n/2)-1]));
        else 
            return solve(nums,nums[n/2]);
    }
};
