class Solution {
    // 1. यहाँ vector<vector<int>>& output किया (2D vector reference)
    void solve(vector<int>& nums, vector<int> temp, vector<vector<int>>& output, int i)
    {
        // base case
        if(i == nums.size())
        {
            output.push_back(temp); // अब यह लाइन बिना एरर के चलेगी
            return;
        }

        // ignore karege
        // 2. यहाँ 'tepm' की स्पेलिंग ठीक करके 'temp' किया
        solve(nums, temp, output, i + 1);

        // accept kruga
        temp.push_back(nums[i]);
        solve(nums, temp, output, i + 1);
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> output;
        vector<int> temp;

        solve(nums, temp, output, 0);
        return output;
    }
};
