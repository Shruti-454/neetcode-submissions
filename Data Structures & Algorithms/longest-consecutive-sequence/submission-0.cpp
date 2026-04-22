class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        int longest = 0;

        for (int num : s) {

            // Start only if it's the beginning of a sequence
            if (s.find(num - 1) == s.end()) {
                int currentNum = num;
                int streak = 1;

                // Count consecutive numbers
                while (s.find(currentNum + 1) != s.end()) {
                    currentNum++;
                    streak++;
                }

                longest = max(longest, streak);
            }
        }

        return longest;
    }
};