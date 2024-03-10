class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> state;
        vector<vector<int>> solutions;
        backtrack(nums, state, solutions);

        return solutions;
    }

    void backtrack(vector<int>& nums, vector<int>& state, vector<vector<int>>& solutions){
        if(isValidState(nums, state))
            solutions.push_back(state);
        
        vector<int> candidates = getCandidates(nums, state);

        for(const auto& candidate : candidates){
            state.push_back(candidate);
            backtrack(nums, state, solutions);
            state.pop_back();
        }
    }

    inline bool isValidState(vector<int> nums, vector<int> state){
        return (state.size() == nums.size());
    }
    inline vector<int> getCandidates(vector<int> nums, vector<int> state){
        vector<int> candidates;
        std::set<int> stateSet(state.begin(), state.end());

        for(const auto& num : nums){
            auto it = stateSet.find(num);
            if(it == stateSet.end())
                candidates.push_back(num);
        }

        return candidates;
    }

};
