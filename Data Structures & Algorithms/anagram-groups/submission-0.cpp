class Solution {
   public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> mpp;

        for (string str : strs) {
            vector<int> freq(26, 0);
            for (char ch : str) {
                freq[ch - 'a']++;
            }

            string key = "";

            for (int i = 0; i < 26; i++) {
                key += to_string(freq[i]) + "#";
            }

            mpp[key].push_back(str);
        }

        for (auto& it : mpp) {
            ans.push_back(it.second);
        }
        return ans;
    }
};
