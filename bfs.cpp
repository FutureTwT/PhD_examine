#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void bfs(const vector<vector<int>>& adj, int startNode) {
    int numNodes = adj.size();
    vector<bool> visited(numNodes, false);
    queue<int> q;

    q.push(startNode);
    visited[startNode] = true;

    cout << "BFS starting: " << endl;
    while(!q.empty()) {
        int current = q.front();
        q.pop();
        cout << current << " ";

        for (int i=0; i<numNodes; i++) {
            if (adj[current][i] == 1 && !visited[i]) {
                q.push(i);
                visited[i] = true;
            }
        }
    }
    cout << endl;
}

int main() {
    vector<vector<int>> adj = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 1, 0},
        {1, 1, 0, 0, 1},
        {0, 1, 0, 0, 1},
        {0, 0, 1, 1, 0}
    };

    int startNode = 0;
    bfs(adj, startNode);
    
    return 0;
}