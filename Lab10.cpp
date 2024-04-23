/*  Author: Jovani Benavides
*  Course: CSCI-115
* 
* BFS and DFS
*/
#include <iostream>
#include <queue>
#include <stack>

using namespace std;

const int MAX_NODES = 10;

// Function to perform (BFS)
void BFS(int numNodes, int adjList[MAX_NODES + 1][MAX_NODES + 1], bool visited[]) {
    queue<int> q;
    q.push(1); // Start BFS from node 1
    visited[1] = true;

    cout << "BFS Order: ";
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        cout << node << " ";

        for (int adjNode = 1; adjNode <= numNodes; adjNode++) {
            if (adjList[node][adjNode] && !visited[adjNode]) {
                visited[adjNode] = true;
                q.push(adjNode);
            }
        }
    }
    cout << endl;
}

// Function to perform (DFS)
void DFS(int node, int adjList[MAX_NODES + 1][MAX_NODES + 1], bool visited[]) {
    visited[node] = true;
    cout << node << " ";

    for (int adjNode = 1; adjNode <= MAX_NODES; adjNode++) {
        if (adjList[node][adjNode] && !visited[adjNode]) {
            DFS(adjNode, adjList, visited);
        }
    }
}

int main() {
    int numNodes;
    cout << "Enter the number of nodes (maximum 10): ";
    cin >> numNodes;

    int adjList[MAX_NODES + 1][MAX_NODES + 1] = {0}; // Adjacency matrix representation of the graph
    bool visited[MAX_NODES + 1] = {false};

    cout << "Enter the adjacency list for each node:\n";
    for (int i = 1; i <= numNodes; i++) {
        int numAdjNodes;
        cout << "Enter the number of adjacent nodes for node " << i << ": ";
        cin >> numAdjNodes;

        cout << "Enter the adjacent nodes for node " << i << ": ";
        for (int j = 0; j < numAdjNodes; j++) {
            int adjNode;
            cin >> adjNode;
            adjList[i][adjNode] = 1;
        }
    }

    // Reset visited array before each traversal
    fill(visited, visited + MAX_NODES + 1, false); // Standard Lib function 

    cout << "\nPerforming BFS\n";
    BFS(numNodes, adjList, visited);

    // Reset visited array before each traversal
    fill(visited, visited + MAX_NODES + 1, false);

    cout << "\nPerforming DFS\nDFS Order: ";
    DFS(1, adjList, visited);
    cout << endl;

    return 0;
}
