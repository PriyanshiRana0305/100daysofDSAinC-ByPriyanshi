/*Problem: Print topological ordering of a Directed Acyclic Graph (DAG) using DFS.*/
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

Node* createNode(int v) {
    Node* n = (Node*)malloc(sizeof(Node));
    n->vertex = v;
    n->next = NULL;
    return n;
}

void addEdge(Node* adj[], int u, int v) {
    Node* n = createNode(v);
    n->next = adj[u];
    adj[u] = n;
}

void dfs(int v, int visited[], Node* adj[], int stack[], int* top) {
    visited[v] = 1;

    Node* temp = adj[v];
    while (temp) {
        int u = temp->vertex;
        if (!visited[u])
            dfs(u, visited, adj, stack, top);
        temp = temp->next;
    }

    stack[++(*top)] = v;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    Node* adj[n];
    for (int i = 0; i < n; i++) adj[i] = NULL;

    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(adj, u, v);
    }

    int visited[n];
    for (int i = 0; i < n; i++) visited[i] = 0;

    int stack[n], top = -1;

    for (int i = 0; i < n; i++) {
        if (!visited[i])
            dfs(i, visited, adj, stack, &top);
    }

    while (top >= 0) {
        printf("%d ", stack[top--]);
    }

    return 0;
}