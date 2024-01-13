class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int n = s.size();
        vector<int> diff(n,0);
        for(int i=0;i<n;i++){
            diff[i]=abs(s[i]-t[i]);
        }
        int cost=0,i=0,j=0,len=0;

        while(i<n){
            cost += diff[i];
            while(cost>maxCost){
                cost -= diff[j];
                j++;
            }
            len = max(len,i-j+1);
            i++;
        }
        return len;
    }
};
