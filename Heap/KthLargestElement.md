
```
class KthLargest {
public:
    KthLargest(int k, vector<int>& nums) {
        minHeap = std::priority_queue<int, vector<int>, greater<int>>(nums.begin(), nums.end());
        kthNumber = k;

        while(minHeap.size()>kthNumber)
            minHeap.pop();
    }
    
    int add(int val) {
        minHeap.push(val);

        if(minHeap.size()>kthNumber)
        minHeap.pop();

        return minHeap.top();
    }
private:
    std::priority_queue<int, vector<int>, greater<int>> minHeap;
    int kthNumber;
};
```
