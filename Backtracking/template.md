# Template

```
// Function to check if it is a valid solution
bool isValidState(const unordered_set<int>& state) {
    // Implement according to the specific problem
    return true;  // Placeholder, replace with actual implementation
}

// Function to get candidates for the next state
vector<int> getCandidates(const unordered_set<int>& state) {
    // Implement according to the specific problem
    return {};  // Placeholder, replace with actual implementation
}

bool isSolutionPossible(const unordered_set<int>& state){
    return true;
}

// Backtracking function
void backtrack(unordered_set<int>& state, vector<unordered_set<int>>& solutions) {
    if (isValidState(state)) {
        solutions.push_back(state);
        // return;  // Uncomment this line if you want to stop at the first solution
    }
    
    if(!isSolutionPossible()){
    	return;
    }

    for (int candidate : getCandidates(state)) {
        state.insert(candidate);
        backtrack(state, solutions);
        state.erase(candidate);
    }
}

// Entry point function
vector<unordered_set<int>> solve() {
    vector<unordered_set<int>> solutions;
    unordered_set<int> state;
    backtrack(state, solutions);
    return solutions;
}

```

## Reference

- https://www.youtube.com/watch?v=A80YzvNwqXA
