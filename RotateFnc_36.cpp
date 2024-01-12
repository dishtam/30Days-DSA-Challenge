class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int ans = 0;
        int n =  nums.size();
        int sum = 0, F=0;

        for(int i=0;i<n;i++){
            sum += nums[i];
            F += i*nums[i]; // calculating F(0)
        }
        ans = F;
        for(int i=1;i<n;i++){
            int temp = F + sum - n*nums[(n-i)%n]; // F[1] = F[0] + sum - n*Bk[0]
            F = temp;
            ans = max(ans,temp);
        }
        return ans;
    }
};
