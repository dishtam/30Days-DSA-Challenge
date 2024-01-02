class Solution {
public:
    int mx,row,col;
    unordered_set<int> st;
    Solution(int m, int n) {
        mx = m*n;
        row = m;
        col = n;
    }
    
    vector<int> flip() {
        if(st.size()==mx) return {};
        int random = rand()%mx;

        // if my random number exits in the set that means i need to choose another number that is in the range [0,m*n)
        while(st.count(random)){
            random = (random+1)%mx;
        }
        st.insert(random);
        // mapping the random number in range [0,m*n) in the 2d vector;
        return {random/col , random%col};
    }
    
    void reset() {
        st.clear();
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(m, n);
 * vector<int> param_1 = obj->flip();
 * obj->reset();
 */
