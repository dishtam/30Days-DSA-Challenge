class Solution {
public:
    int findTheWinner(int n, int k) {
        queue<int> q;
        for(int i=1;i<=n;i++){
            q.push(i);
        }

// Shifting the queue for k times and removing the kth element each time till the queue left one element
        while(q.size()>1){
            int siz = k-1;
            while(siz--){
                int temp = q.front();
                q.pop();
                q.push(temp);
            }
            q.pop();
        }
        return q.front();
    }
};
