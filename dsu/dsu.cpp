#include<iostream>
using namespace std;
class Dsu {
public:
    vector<int> parent;
    vector<int> rank;

    // Constructor
    Dsu(int n) {
        parent.resize(n + 1);
        rank.resize(n + 1, 0);

        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }

    // Find with Path Compression
    int findParent(int node) {
        if (parent[node] == node)
            return node;

        return parent[node] = findParent(parent[node]);
    }

    // Union by Rank
    void union_op(int u, int v) {
        int pu = findParent(u);
        int pv = findParent(v);

        if (pu == pv)
            return;

        if (rank[pu] < rank[pv]) {
            parent[pu] = pv;
        }
        else if (rank[pu] > rank[pv]) {
            parent[pv] = pu;
        }
        else {
            parent[pv] = pu;
            rank[pu]++;
        }
    }

    // Check if two nodes are in same component (cycle detection helper)
    bool check_cycle(int u, int v) {
        return findParent(u) == findParent(v);
    }
};
int main(){
    cout<<"Hello World";
    return 0;

}