class Solution {
public:
    string frequencySort(string s) {
        map<char,int> mp;
        priority_queue<pair<int,char>> maxH;
        for(auto it:s){
            mp[it]++;
        }
        for(auto it:mp){
            maxH.push({it.second,it.first});
        }
        string ans="";
        while(!maxH.empty()){
            auto i=maxH.top();
            int cnt=i.first;
            char ch = i.second;
            while(cnt--){
                ans += ch;
            }
            maxH.pop();
        }
        return ans;
    }
};
