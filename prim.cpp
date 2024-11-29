#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int findMinVertex(const vector<int>& weights, const vector<bool>& visited) {
    int minVertex = -1;
    for (int i = 0; i < weights.size(); ++i) {
        if (!visited[i] && (minVertex == -1 || weights[i] < weights[minVertex])) {
            minVertex = i;
        }
    }
    return minVertex;
}

void primMST(const vector<vector<int>>& graph) {
    int numNodes = graph.size();
    vector<bool> visited(numNodes, false); 
    vector<bool> parent(numNodes, -1); 
    vector<int> weights(numNodes, INT_MAX); // 每个节点到最小生成树的距离

    weights[0] = 0;

    // 最小生成树一共numNodes-1条边，选择numNodes-1次即可
    for (int i = 0; i < numNodes-1; i++) {
        // 找出当前距离生成树最近的节点
        int minVertex = findMinVertex(weights, visited);
        visited[minVertex] = true;

        // 基于新增节点更新未访问节点到生成树的距离，每增加一个点，产生的额外边仅来自于该节点
        for (int j = 0; j < numNodes; j++) {
            // !visited[j] 避免产生环
            if (graph[minVertex][j] != 0 && !visited[j] && graph[minVertex][j] < weights[j]) {
                weights[j] = graph[minVertex][j];
                parent[j] = minVertex;
            }
        
        }
    }

    // 输出最小生成树的边和权重
    cout << "Edges in MST:\n";
    for (int i = 1; i < numNodes; ++i) {
        cout << parent[i] << " - " << i << " : " << graph[i][parent[i]] << endl;
    }
    
}

int main() {
    vector<vector<int>> graph = {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0}
    };

    primMST(graph); 

    return 0;
}