class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        //using negative marking technique
        for(int i = 0; i < nums.size(); i++)
        {
            int x = abs(nums[i]);
            nums[x] = -nums[x];
            if(nums[x] > 0) return x;
        }

        return nums[0];
    }
};