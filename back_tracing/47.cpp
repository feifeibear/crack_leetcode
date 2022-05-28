/*
47. Permutations II
Given a collection of numbers, nums, that might contain duplicates, return all possible unique permutations in any order.
*/

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        N_ = nums.size();
        // cur_record_ = nums;
        for(auto num : nums)
            cur_record_.emplace_back(num);
        backTracing(0);
        return res_;
    }
private:
    int N_;
    vector<vector<int>> res_;
    vector<int> cur_record_;
    void backTracing(int idx) {
        if (idx >= N_) {
            // vector<int> tmp(cur_record_);
            res_.emplace_back(cur_record_);
            return;
        }
        unordered_set<int> visited;
        for(int i = idx; i < N_; ++i) {
            auto num = cur_record_[i];
            if (visited.count(num))
                continue;
            swap(idx, i);
            backTracing(idx+1);
            swap(i, idx);
            visited.insert(num);
        }
    }
    
    void swap(int i, int j) {
        if (i == j)
            return;
        auto tmp = cur_record_[i];
        cur_record_[i] = cur_record_[j];
        cur_record_[j] = tmp;
    }
};
