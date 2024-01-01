class Solution {
public:
    using ll = long long;
    bool check(ll maxN,ll div1,ll div2,ll cnt1,ll cnt2){
        ll n1 = maxN - maxN/div1;
        ll n2 = maxN - maxN/div2;
        // ll lcm = (div1*div2*1LL)/__gcd(div1,div2);
        ll n3 = maxN - maxN/lcm(div1,div2);
        return n3>=cnt1+cnt2 && n2>=cnt2 && n1>=cnt1;
    }
    int minimizeSet(int div1, int div2, int cnt1, int cnt2) {
        int low = 1,hi=INT_MAX,ans=-1;

        while(low<=hi){
            int mid = low + (hi-low)/2;
            if(check(mid,div1,div2,cnt1,cnt2)){
                ans = mid;
                hi = mid-1;
            }
            else low=mid+1;
        }
        return ans;
    }
};
