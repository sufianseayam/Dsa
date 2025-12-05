class Solution {
public:
    set<vector<int>> s;

    void comSum(vector<int>& arr, int idx, int target, vector<int> com, vector<vector<int>>& ans) {

        if (idx == arr.size() || target < 0) return;

        if (target == 0) {
            if (s.find(com) == s.end()) {
                ans.push_back(com);
                s.insert(com);
            }
            return;
        }
        com.push_back(arr[idx]);
        comSum(arr, idx + 1, target - arr[idx], com, ans);


        comSum(arr, idx, target - arr[idx], com, ans);

  
        com.pop_back();
        comSum(arr, idx + 1, target, com, ans);
    }
    vector<vector<int>> combinationSum(vector<int>& arr, int target) {
        vector<vector<int>> ans;
        vector<int> com;
        comSum(arr, 0, target, com, ans);
        return ans;
    }
};
