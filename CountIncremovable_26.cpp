class Solution {
public:
    long long incremovableSubarrayCount(vector<int>& nums) {
        int n = nums.size();
        long long cnt = 0;

        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                bool isIncL = true, isIncR = true;

                for (int k = 1; k < i; k++) {
                    if (nums[k] <= nums[k - 1]) {
                        isIncL = false;
                        break;
                    }
                }

                for (int k = j + 1; k < n - 1; k++) {
                    if (nums[k] >= nums[k + 1]) {
                        isIncR = false;
                        break;
                    }
                }

                if (isIncL && isIncR && (i == 0 || j == n - 1 || nums[i - 1] < nums[j + 1])) {
                    cnt++;
                }
            }
        }
        return cnt;
    }
};
