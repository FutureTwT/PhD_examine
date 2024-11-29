#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
    int src, dest, weight;
};

bool compareEdge(const Edge& a, const Edge& b) {
    return a.weight < b.weight;
}

// 并查集：查找根节点
int findParent(int node, vector<int>& parent) {
    if (parent[node] == node) {
        return node;
    }
    // 递归压缩路径，让node直接指向根节点
    parent[node] = findParent(parent[node], parent);
    return parent[node];
}

void unionSets(int u, int v, vector<int>& parent, vector<int>& rank) {
    int rootU = findParent(u, parent);
    int rootV = findParent(v, parent);

    // rank 是一种优化策略，用于加速合并操作的效率，尽量保持集合的树结构扁平化，从而减少树的高度。
    if (rootU != rootV) {
        // 优先将较矮的树挂到较高的树上
        if (rank[rootU] < rank[rootV]) {
            parent[rootU] = rootV;
        } else if (rank[rootU] > rank[rootV]) {
            parent[rootV] = rootU;
        } else {
            parent[rootV] = rootU;
            rank[rootU]++;
        }
    }
}

void kruskal(vector<Edge>& edges, int numNodes) {
    sort(edges.begin(), edges.end(), compareEdge);

    vector<int> parent(numNodes, -1); 
    vector<int> rank(numNodes, 0);

    // 初始化并查集
    for (int i = 0; i < numNodes; ++i) {
        parent[i] = i;
    }

    vector<Edge> mst;

    for (const auto& edge : edges) {
        /*
        // 也可以指针迭代，使用auto自动迭代更方便
        for (auto it = edges.begin(); it != edges.end(); ++it) {
            const Edge& edge = *it; 
        }
        */
       if (findParent(edge.src, parent) != findParent(edge.dest, parent)) {
            // 判断是否存在共同根节点，如果没有，可以添加边，用于避免产生环
            mst.push_back(edge);
            unionSets(edge.src, edge.dest, parent, rank);
       }
    }

    // 输出最小生成树的边和权重
    cout << "Edges in MST:\n";
    for (const auto& edge : mst) {
        cout << edge.src << " - " << edge.dest << " : " << edge.weight << endl;
    }
}

int main() {
    vector<Edge> edges = {
        {0, 1, 2}, {0, 3, 6}, {1, 2, 3},
        {1, 3, 8}, {1, 4, 5}, {2, 4, 7},
        {3, 4, 9}
    };

    int numNodes = 5; // 节点数
    kruskal(edges, numNodes);

    return 0;
}