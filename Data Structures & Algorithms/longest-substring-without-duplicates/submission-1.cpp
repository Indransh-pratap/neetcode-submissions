class Solution {
   public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int maxlen = INT_MIN;
        vector<int> arr(256, 0);
if(s.size()==0) return 0;
        int l = 0;

        for (int r = 0; r < n; r++) {
            arr[s[r]]++;

            while(arr[s[r]] > 1) {
                arr[s[l]]--;
                l++;
            }

            maxlen = max(maxlen , r-l+1);
        }
        return maxlen;
    }
};
