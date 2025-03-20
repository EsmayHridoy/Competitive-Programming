/*** Disjoint Set Union Template ***/
int componentCount;
int componentCost[100005];
int parent[100005], treeSize[100005];

int findParent(int node) {
    if (parent[node] == node) return node;
    parent[node] = findParent(parent[node]);
    return parent[node];
}

void initializeDSU(int n) {
    for (int i = 0; i <= n; i++) {
        parent[i] = i;
        treeSize[i] = 1;
        componentCost[i] = ((1 << 30) - 1);
    }
    componentCount = n;
    return;
}

void unionSets(int x, int y) {
    int rootX = findParent(x);
    int rootY = findParent(y);
    if (rootX == rootY) return;
    if (treeSize[rootX] < treeSize[rootY]) swap(rootX, rootY);
    treeSize[rootX] += treeSize[rootY];
    parent[rootY] = rootX;
    componentCount--;
    return;
}
/*** Disjoint Set Union Template ***/

class Solution {
public:
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        initializeDSU(n);
        int nodeA, nodeB;
        for (auto& edge : edges) {
            nodeA = findParent(edge[0] + 1);
            nodeB = findParent(edge[1] + 1);
            if (nodeA != nodeB) {
                unionSets(edge[0] + 1, edge[1] + 1);
            }
        }
        for (auto& edge : edges) {
            nodeB = findParent(edge[1] + 1);
            componentCost[nodeB] &= edge[2];
        }

        vector<int> result;
        for (auto& q : query) {
            int rootA = findParent(q[0] + 1);
            int rootB = findParent(q[1] + 1);
            if (rootA == rootB) {
                result.push_back(componentCost[rootA]);
            } else {
                result.push_back(-1);
            }
        }
        return result;
    }
};