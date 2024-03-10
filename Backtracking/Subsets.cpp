class Solution {
public:
    bool isValidState(vector<int> state, vector<vector<int>> solutions) {
        for (const auto& item : solutions) {
            if (item.size() != state.size())
                continue;

            int count = 0;
            for (int i = 0; i < item.size(); ++i) {
                for(int j=0; j<state.size(); ++j){

                if (item[i] == state[j])
                    count++;
                }
            }

            if (count == state.size())
                return false;
        }

        return true;
    }

    vector<int> getCandidates(vector<int> state, vector<int> nums) {
        vector<int> candidataes;
        for (auto num : nums) {
            auto it = std::find(state.begin(), state.end(), num);
            if (it == state.end())
                candidataes.push_back(num);
        }
        return candidataes;
    }

    void backtrack(vector<int>& nums, vector<int>& state,
                   vector<vector<int>>& solutions) {
        if (isValidState(state, solutions))
            solutions.push_back(state);

        vector<int> candidates = getCandidates(state, nums);
        for (const auto& candidate : candidates) {
            state.push_back(candidate);
            backtrack(nums, state, solutions);
            state.pop_back();
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> solutions;
        vector<int> state;
        backtrack(nums, state, solutions);
        return solutions;
    }
};
