class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        //using negative marking technique
        vector<pair<int, int>> p;

        for(int i = 0; i < nums.size(); i++)
        {
            int x = abs(nums[i]);
            nums[x] = -nums[x];
            if(nums[x] > 0) return x;
        }


        // for(auto x: p)
        // {
        //     if(x.first > 0)
        //     return x.second;
        // }
        return nums[0];
    }
};