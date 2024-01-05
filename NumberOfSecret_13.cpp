class Solution {
public:
    const int mod = 1e9+7;
    int peopleAwareOfSecret(int n, int delay, int forget) {
        vector<int> numSecret(5000,0);
        numSecret[1]=1; // Day 1, a person only knew the secret;
        // Filled up the array to store the number of people knowing the secret 
        for(int i=1;i<=n;i++){
            for(int j=i+delay;j<i+forget;j++){
                numSecret[j]=(numSecret[j]+numSecret[i])%mod;
            }
        }

        long long ans=0;
        int i=0;
        while(forget--){
            ans = (ans+numSecret[n-i])%mod;
            i++;
        }
        return ans%mod;
    }
};
