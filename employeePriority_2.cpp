class Solution {
public:
    vector<string> findHighAccessEmployees(vector<vector<string>>& access_times) {
        map<string,vector<int>> mp;
        for(auto it:access_times){
            mp[it[0]].push_back(stoi(it[1]));
        }
        vector<string> ans;

        for(auto it:mp){
            vector<int> v = it.second;
            sort(v.begin(),v.end());

            for(int i=0;i<v.size();i++){
                int cnt=1;
                for(int j=i+1;j<v.size();j++){
                    if((v[j]-v[i]+2400)%2400<100) cnt++;
                    else break;
                }
                if(cnt>=3) {
                    ans.push_back(it.first);
                    break;
                }
            }
        }
        return ans;
    }
};
