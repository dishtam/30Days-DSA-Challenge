class Solution {
public:
    using ll = long long;
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        if (source.size() != target.size()) return -1;
        vector<vector<ll>> dist(26,vector<ll>(26,INT_MAX));
        for(int i=0;i<26;i++){
            dist[i][i]=0;
        }

        for(int i=0;i<original.size();i++){
            int u = original[i]-'a';
            int v = changed[i]-'a';
            int w = cost[i];
            dist[u][v]=min<ll>(dist[u][v],w);
        }

        for(int k=0;k<26;k++){
            for(int i=0;i<26;i++){
                for(int j=0;j<26;j++){
                    dist[i][j] = min<ll>(dist[i][j],dist[i][k] + dist[k][j]);
                }
            }
        }

        ll ans = 0;

        for(int i=0;i<source.size();i++){
            int u = source[i]-'a';
            int v = target[i]-'a';
            if(u==v) continue;
            if(dist[u][v]>=INT_MAX ) return -1;
            ans += dist[u][v];
        }
        return ans;
    }
};
