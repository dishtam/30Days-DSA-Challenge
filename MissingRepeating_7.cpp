class Solution{
public:
    vector<int> findTwoElement(vector<int> arr, int n) {
        // code here
        unordered_map<int,int> mp;
        int x=0,y=0;
        for(int i=0;i<n;i++){
            mp[arr[i]]++;
        }
        for(int i=1;i<=n;i++){
            if(mp[i]==2) y=i;
            if(!mp[i]) x=i;
        }
        return {y,x};
    }
};
