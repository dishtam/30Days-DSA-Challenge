class Solution {
public:
    string getHint(string secret, string guess) {
        int bulls = 0, cows = 0;
        unordered_map<char, int> freq;
        
        for (int i = 0; i < secret.size(); ++i) {
            if (secret[i] == guess[i]) {
                bulls++;
            } else {
                freq[secret[i]]++;
            }
        }
        
        for (int i = 0; i < guess.size(); ++i) {
            if (secret[i] != guess[i] && freq[guess[i]] > 0) {
                cows++;
                freq[guess[i]]--;
            }
        }
        
        return to_string(bulls) + "A" + to_string(cows) + "B";
    }
};
