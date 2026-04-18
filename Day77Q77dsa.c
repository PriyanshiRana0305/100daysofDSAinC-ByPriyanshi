/*Problem Statement
Using BFS or DFS, check if the entire graph is connected.

Input Format
n m
edges

Output Format
CONNECTED
NOT CONNECTED

Sample Input
4 2
1 2
3 4

Sample Output
NOT CONNECTED*/
// LeetCode 133: Clone Graph (C - DFS)

// Definition for a Node
struct Node {
    int val;
    int numNeighbors;
    struct Node** neighbors;
};

// Array to store cloned nodes (index = node value)
struct Node* visited[101];

// DFS function to clone graph
struct Node* cloneGraph(struct Node* node) {
    if (node == NULL)
        return NULL;

    // If already cloned, return it
    if (visited[node->val] != NULL)
        return visited[node->val];

    // Create new node
    struct Node* clone = (struct Node*)malloc(sizeof(struct Node));
    clone->val = node->val;
    clone->numNeighbors = node->numNeighbors;
    clone->neighbors = (struct Node**)malloc(sizeof(struct Node*) * node->numNeighbors);

    // Mark as visited
    visited[node->val] = clone;

    // Clone neighbors recursively
    for (int i = 0; i < node->numNeighbors; i++) {
        clone->neighbors[i] = cloneGraph(node->neighbors[i]);
    }

    return clone;
}