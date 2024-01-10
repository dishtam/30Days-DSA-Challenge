class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        sort(nums.begin(),nums.end()); //sorting can be done in o(n) using counting sort
        int n = nums.size();
        vector<int> ans(n);
        int j=0;
        for(int i=1;i<n;i=i+2,j++){
            ans[i]=nums[n-j-1];
        }
        for(int i=0;i<n;i=i+2,j++){
            ans[i] = nums[n-j-1];
        }
        nums=ans;
    }
};
