# Graphs
graph = nodes + edges

## Directed graph
A directed graph is a graph in which edges have a direction. In other words, the relationship between nodes is one-way.

## Undirected graph
An undirected graph is a graph in which edges have no direction. In other words, the relationship between nodes is bidirectional.

## Neighbor nodes
Neighbor nodes are nodes directly connected to a given node by an edge. In an undirected graph, these are also referred to as adjacent nodes.

## Adjacency list
An adjacency list is a data structure used to represent a graph. It consists of a list of lists or a mapping of nodes to lists, where each list contains the neighbors of a particular node.

## Depth first traversal
Depth-first traversal is a graph traversal algorithm that explores as far as possible along each branch before backtracking. It uses a stack data structure to keep track of visited nodes and the order in which nodes are visited.
```
// Iterative function to perform DFS traversal
void DFS(unordered_map<int, vector<int>>& adjList, int startNode) {
    vector<bool> visited;
    visited.resize(adjList.size(), false);
    stack<int> stack;

    stack.push(startNode);

    while (!stack.empty()) {
        int currentNode = stack.top();
        stack.pop();

        if (!visited[currentNode]) {
            cout << currentNode << " ";
            visited[currentNode] = true;

            // Explore all adjacent nodes
            for (int neighbor : adjList[currentNode]) {
                if (!visited[neighbor]) {
                    stack.push(neighbor);
                }
            }
        }
    }
}
```

```
// Recursive function for DFS traversal
void DFSRecursive(unordered_map<int, vector<int>>& adjList, vector<bool>& visited, int currentNode) {
    visited[currentNode] = true;
    cout << currentNode << " ";

    // Explore all adjacent nodes
    for (int neighbor : adjList[currentNode]) {
        if (!visited[neighbor]) {
            DFSRecursive(adjList, visited, neighbor);
        }
    }
}

// Wrapper function for DFSRecursive
void DFS(unordered_map<int, vector<int>>& adjList, int startNode) {
    vector<bool> visited(adjList.size(), false);
    DFSRecursive(adjList, visited, startNode);
}
```

```
// Iterative function to perform BFS traversal
void BFS(unordered_map<int, vector<int>>& adjList, int startNode) {
    vector<bool> visited;
    visited.resize(adjList.size(), false);
    queue<int> queue;

    queue.push(startNode);
    visited[startNode] = true;

    while (!queue.empty()) {
        int currentNode = queue.front();
        queue.pop();
        
        cout << currentNode << " ";

        // Explore all adjacent nodes
        for (int neighbor : adjList[currentNode]) {
            if (!visited[neighbor]) {
                queue.push(neighbor);
                visited[neighbor] = true;
            }
        }
    }
}
```

```
// Recursive function for BFS traversal
void BFSRecursive(unordered_map<int, vector<int>>& adjList, vector<bool>& visited, queue<int>& q) {
    if (q.empty()) // Base case: if the queue is empty, return
        return;

    int currentNode = q.front();
    q.pop();
    cout << currentNode << " ";

    // Explore all adjacent nodes
    for (int neighbor : adjList[currentNode]) {
        if (!visited[neighbor]) {
            visited[neighbor] = true;
            q.push(neighbor);
        }
    }

    BFSRecursive(adjList, visited, q); // Recursive call for the next level
}

// Wrapper function for BFSRecursive
void BFS(unordered_map<int, vector<int>>& adjList, int startNode) {
    vector<bool> visited(adjList.size(), false);
    queue<int> q;
```




    q.push(startNode);
    visited[startNode] = true;
    BFSRecursive(adjList, visited, q);
}


