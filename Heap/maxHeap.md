```
#include <iostream>
#include <vector>
#include <stdexcept>

class MaxHeap {
public:
    void printHeap() const {
        std::cout << "Printing heap ...\n";
        for (const auto& item : container)
            std::cout << item << " ";
        std::cout << '\n';
    }

    void pop() {
        std::cout << "Pop element from heap\n";
        if (container.empty())
            throw std::out_of_range("Empty heap.");

        int lastElement = container.back();
        container.pop_back();
        container[0] = lastElement;

        heapifyDown(0);
        printHeap();
    }

    void heapifyDown(size_t index) {
        while (hasLeftChild(index)) {
            size_t largestChild = getLeftChild(index);

            if (hasRightChild(index)) {
                size_t rightChild = getRightChild(index);
                largestChild = (container[largestChild] < container[rightChild]) ? rightChild : largestChild;
            }

            if (container[index] >= container[largestChild])
                break;
            std::swap(container[index], container[largestChild]);
            index = largestChild;
        }
    }

    void add(int item) {
        std::cout << "Add item to heap " << item << '\n';
        container.emplace_back(item);

        heapifyUp(container.size() - 1);
        printHeap();
    }

    void heapifyUp(size_t index) {
        while (hasParent(index)) {
            size_t parentIndex = getParent(index);

            if (container[index] <= container[parentIndex])
                break;

            std::swap(container[index], container[parentIndex]);
            index = parentIndex;
        }
    }

    bool hasParent(const size_t& index) const { return index > 0; }
    bool hasLeftChild(const size_t& index) const { return (2 * index + 1) < container.size(); }
    bool hasRightChild(const size_t& index) const { return (2 * index + 2) < container.size(); }

    size_t getLeftChild(const size_t& index) const { return 2 * index + 1; }
    size_t getRightChild(const size_t& index) const { return 2 * index + 2; }
    size_t getParent(const size_t& index) const { return (index - 1) / 2; }

    int peek() const {
        if (container.empty())
            throw std::out_of_range("Empty container");

        return container[0];
    }

private:
    std::vector<int> container;
};

int main() {
    MaxHeap maxheap;
    maxheap.add(10);
    maxheap.add(1);
    maxheap.add(4);
    maxheap.add(8);
    maxheap.add(15);
    maxheap.pop();
    maxheap.pop();
    maxheap.pop();
    maxheap.pop();
    maxheap.pop();
    try {
        maxheap.pop(); // Trying to pop from an empty heap
    }
    catch (const std::out_of_range& e) {
        std::cerr << e.what() << '\n';
    }

    return 0;
}
```
