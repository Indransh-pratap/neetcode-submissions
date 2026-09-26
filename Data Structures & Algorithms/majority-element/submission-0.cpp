class Solution {
   public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int max = 0;
        int maxele = nums[0];
        int curr = 0;
        int currfre = 0;
        for (int i = 1; i < n; i++) {
            if (maxele == nums[i])
                max++;
            else
                {curr = nums[i];
            currfre++;
        }
        if (currfre > max) maxele = curr;
    }

    return maxele;
}
}
;