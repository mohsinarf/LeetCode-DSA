```
class Solution {
public:
    int lastStoneWeight(std::vector<int>& stones) {
        // Create a max heap
        std::priority_queue<int> pq;
        
        // Add all stones to the max heap
        for (int stone : stones) {
            pq.push(stone);
        }
        
        // Process stones until at most one remains
        while (pq.size() > 1) {
            int stone1 = pq.top();
            pq.pop();
            int stone2 = pq.top();
            pq.pop();
            
            // If stones are not equal, add the difference back
            if (stone1 != stone2) {
                pq.push(stone1 - stone2);
            }
        }
        
        // Return the last stone weight or 0 if empty
        return pq.empty() ? 0 : pq.top();
    }

};

```
