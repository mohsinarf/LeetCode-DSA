//
// Created by mohsin on 1/31/24.
//
#include <vector>
#include <string>
#include <set>

class Solution {
public:
    std::vector<std::vector<std::string>> solveNQueens(int n) {
        std::vector<std::vector<std::string>> solutions;
        std::vector<int> state;
        search(state, solutions, n);
        return solutions;
    }

private:
    bool is_valid_state(const std::vector<int>& state, int n) {
        return state.size() == n;
    }

    std::set<int> get_candidates(const std::vector<int>& state, int n) {
        std::set<int> candidates;
        if (state.empty()) {
            for (int i = 0; i < n; ++i) {
                candidates.insert(i);
            }
        } else {
            int position = state.size();
            for (int i = 0; i < n; ++i) {
                candidates.insert(i);
            }
            for (int row = 0; row < state.size(); ++row) {
                int col = state[row];
                candidates.erase(col);
                int dist = position - row;
                candidates.erase(col + dist);
                candidates.erase(col - dist);
            }
        }
        return candidates;
    }

    void search(std::vector<int>& state, std::vector<std::vector<std::string>>& solutions, int n) {
        if (is_valid_state(state, n)) {
            std::vector<std::string> state_string = state_to_string(state, n);
            solutions.push_back(state_string);
            return;
        }

        for (int candidate : get_candidates(state, n)) {
            state.push_back(candidate);
            search(state, solutions, n);
            state.pop_back();
        }
    }

    std::vector<std::string> state_to_string(const std::vector<int>& state, int n) {
        std::vector<std::string> ret;
        for (int i : state) {
            std::string row(n, '.');
            row[i] = 'Q';
            ret.push_back(row);
        }
        return ret;
    }
};
