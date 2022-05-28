/*
46. Permutations
Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.
*/


class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        back_tracing(nums, 0);
        return res_;
    }
    
    void back_tracing(vector<int>& nums, int i) {
        int N = nums.size();
        if (i == N - 1) {
            res_.emplace_back(nums);
            return;
        }
        
        for (int j = i; j < N; ++j) {
            swap_(nums, i, j);
            back_tracing(nums, i + 1);
            swap_(nums, i, j);
        }
    }
private:
    vector<vector<int>> res_;
    
    void swap_(vector<int>& nums, int i, int j) {
        auto tmp = nums[i];
        nums[i] = nums[j];
        nums[j] = tmp;
    }
};
