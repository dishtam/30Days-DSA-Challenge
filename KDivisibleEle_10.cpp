class Solution {
public:
    int countDistinct(vector<int>& nums, int k, int p) {
        int ans=0,n=nums.size();
        set<string> st;
        for(int i=0;i<n;i++){
            string sub="";
            int cnt=0;
            for(int j=i;j<n;j++){
                sub+=nums[j];
                if(nums[j]%p==0) cnt++;
                if(cnt>k)break;
                st.insert(sub);
            }    
        }   
        return st.size();
    }
};
