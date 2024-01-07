class Solution {
public:
    bool isValid(int x,int y,int n,int m){
        return (x>=0 && y>=0 && x<n && y<m);
    }
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int n = img.size(),m=img[0].size();
        vector<vector<int>> ans(n,vector<int>(m,0));
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int sum = img[i][j],cnt=1;
                if(isValid(i,j+1,n,m)) {sum += img[i][j+1];cnt++;}
                if(isValid(i-1,j+1,n,m)) {sum += img[i-1][j+1];cnt++;}
                if(isValid(i-1,j,n,m)) {sum += img[i-1][j];cnt++;}
                if(isValid(i-1,j-1,n,m)) {sum += img[i-1][j-1];cnt++;}
                if(isValid(i,j-1,n,m)) {sum += img[i][j-1];cnt++;}
                if(isValid(i+1,j-1,n,m)) {sum += img[i+1][j-1];cnt++;}
                if(isValid(i+1,j,n,m)) {sum += img[i+1][j];cnt++;}
                if(isValid(i+1,j+1,n,m)) {sum += img[i+1][j+1];cnt++;}
                ans[i][j]=sum/cnt;
            }
        }
        return ans;
    }
};
