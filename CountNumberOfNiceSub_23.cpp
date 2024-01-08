class Solution {
public:
    int solve(vector<int>& nums,int k){
        int n = nums.size();
        int j=0,i=0,odd_cnt=0,cnt=0;

        while(j<n){
            if(nums[j]&1) odd_cnt++;
            while(i<=j && odd_cnt>k){
                if(nums[i]&1) odd_cnt--;
                i++;
            }
            cnt += j-i+1;
            j++;
        }
        return cnt;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return solve(nums,k)-solve(nums,k-1);
    }
};
