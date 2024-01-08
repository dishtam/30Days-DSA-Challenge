class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int n = s.size();
        int i = 0, j = 0;
        deque<char> dq;
        map<deque<char>, int> mp;
        while (j < n) {
            dq.push_back(s[j]);
            while (dq.size() > 10) {
                dq.pop_front();
                i++;
            }
            if (dq.size() == 10) {
                mp[dq]++;
            }
            j++;
        }

        vector<string> ans;
        for (auto str : mp) {
            if (str.second > 1) {
                string sequence(str.first.begin(), str.first.end());
                ans.push_back(sequence);
            }
        }
        return ans;
    }
};
