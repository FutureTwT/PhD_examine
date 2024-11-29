#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void dfs(const vector<vector<int>>& adj, int startNode) {
    int numNodes = adj.size();
    vector<bool> visited(numNodes, false);
    stack<int> s;

    s.push(startNode);
    visited[startNode] = true;

    cout << "DFS starting: " << endl;
    while(!s.empty()) {
        int current = s.top();
        s.pop();
        cout << current << " ";

        for (int i=numNodes-1; i>=0; --i) {
            if (adj[current][i] == 1 && !visited[i]) {
                s.push(i);
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
    dfs(adj, startNode);
    
    return 0;
}