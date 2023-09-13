class Solution {
public:
    int n;
    vector<vector<int>> dp;

    int solve(int i, vector<int> &nums, int pos) {
        if (i >= n) return 0;
        if (dp[i][pos] != -1) return dp[i][pos];

        int answer = 0;

        //pick
        if (pos) 
        {  
            for (int j = i + 1; j < n; ++j) 
            {
                if (nums[j] - nums[i] > 0) 
                {
                    answer = max(answer, 1 + solve(j, nums, 0));
                }
            }
        } 
        else 
        {  
            for (int j = i + 1; j < n; ++j) 
            {
                if (nums[j] - nums[i] < 0) 
                {
                    answer = max(answer, 1 + solve(j, nums, 1));
                }
            }
        }

        // dont pick current element
        answer = max(answer, solve(i + 1, nums, pos));

        return dp[i][pos] = answer;
    }

    int wiggleMaxLength(vector<int>& nums) {
        n = (int)nums.size();
        if (n == 0) return 0;

        dp.resize(n + 1, vector<int>(2, -1));
        
        // Start either expecting an increase or a decrease
        return 1 + max(solve(0, nums, 0), solve(0, nums, 1)); 
    }
};
