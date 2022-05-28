/*
Leetcode Problem 139
Given a string s and a dictionary of strings wordDict, 
return true if s can be segmented into a space-separated sequence of one or more dictionary words.
*/

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        Dict_.clear();
        mem_.clear();
        for (auto& w : wordDict) {
            Dict_.insert(w);
        }
        return DFS(s);
    }
    
    bool DFS(string s) {
        if(Dict_.count(s)) return true;
        if(mem_.find(s) != mem_.end()) return mem_[s];
            
        for(int i = 0; i < s.length(); ++i) {
            auto left = s.substr(0, i);
            auto right = s.substr(i);
            if (Dict_.count(left) && DFS(right)) {
                return mem_[s] = true;
            }
        }
        mem_[s] = false;
        return false;
    }
private:
    unordered_set<string> Dict_;
    unordered_map<string, bool> mem_;
};
