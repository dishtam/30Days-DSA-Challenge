class Solution {
public:
    bool isValid(vector<vector<bool>>& vis,int row,int col){
        if(row<0 || row>=vis.size() || col<0 || col>=vis[0].size() || vis[row][col]==1) return false;
        return true;
    }
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        queue<pair<pair<int,int>,int>> q;
        int n = isWater.size(), m = isWater[0].size();
        vector<vector<int>> ans(n,vector<int>(m,0));
        vector<vector<bool>> vis(n,vector<bool>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(isWater[i][j]==1){
                    q.push({{i,j},0}); // (x,y)--> weight
                    vis[i][j]=1;
                }
            }
        }
        vector<int> nRow = {0,-1,0,1};
        vector<int> nCol = {1,0,-1,0};

        while(!q.empty()){
            int siz = q.size();

            for(int i=0;i<siz;i++){
                auto it = q.front();
                q.pop();
                int row = it.first.first, col = it.first.second, weight = it.second;

                for(int j=0;j<4;j++){
                    int nr = row + nRow[j];
                    int nc = col + nCol[j];

                    if(isValid(vis,nr,nc)){
                        q.push({{nr,nc},weight+1});
                        ans[nr][nc]=weight+1;
                        vis[nr][nc]=1;
                    }
                }
            }
        }
        return ans;
    }
};
