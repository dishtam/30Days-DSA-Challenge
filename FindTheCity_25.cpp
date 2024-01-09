class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> dist(n,vector<int>(n,INT_MAX));
        for(auto edge:edges){
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            dist[u][v]=w;
            dist[v][u]=w;
        }   
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                dist[i][i]=0;
            }
        }

        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if((dist[i][k]!=INT_MAX  &&  dist[k][j]!=INT_MAX && dist[i][j]>dist[i][k]+dist[k][j])) 
                    {
                        dist[i][j] = dist[i][k]+dist[k][j];
                    }
                }
            }
        }
        int Min_cnt=INT_MAX,ans=-1;
        for(int i=0;i<n;i++){
            int cnt=0;
            for(int j=0;j<n;j++){
                if(dist[i][j]<=distanceThreshold) cnt++;
            }
            if(cnt<=Min_cnt){
                Min_cnt=cnt;
                ans = i;
            }
        }
        return ans;
    }
};
