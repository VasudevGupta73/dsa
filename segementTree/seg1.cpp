#include <bits/stdc++.h>
using namespace std;

class SegmentTree {
private:
    vector<long long> tree;
    int n;

    void build(int node, int start, int end, const vector<int>& arr) {
        if (start == end) {
            tree[node] = arr[start];
            return;
        }
        int mid = start + (end - start) / 2;
        build(2*node + 1, start, mid, arr);
        build(2*node + 2, mid + 1, end, arr);
        tree[node] = tree[2*node + 1] + tree[2*node + 2];
    }

    void update(int node, int start, int end, int index, int value) {
        if (start == end) {
            tree[node] = value;
            return;
        }
        int mid = start + (end - start) / 2;
        if (index <= mid)
            update(2*node + 1, start, mid, index, value);
        else
            update(2*node + 2, mid + 1, end, index, value);
        tree[node] = tree[2*node + 1] + tree[2*node + 2];
    }

    long long query(int node, int start, int end, int left, int right) {
        if (right < start || end < left) return 0; // no overlap
        if (left <= start && end <= right) return tree[node]; // complete overlap
        int mid = start + (end - start) / 2;
        return query(2*node + 1, start, mid, left, right) +
               query(2*node + 2, mid + 1, end, left, right);
    }

public:
    SegmentTree(const vector<int>& arr) {
        n = arr.size();
        tree.resize(4*n, 0);
        build(0, 0, n-1, arr);
    }

    void update(int index, int value) {
        if (index >= 0 && index < n) update(0, 0, n-1, index, value);
    }

    long long query(int left, int right) {
        return query(0, 0, n-1, left, right);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    SegmentTree st(arr);

    while (q--) {
        int type;
        cin >> type;

        if (type == 1) {
            int index, value;
            cin >> index >> value;
            // Input is 0-based, no conversion needed
            st.update(index, value);
        } else if (type == 2) {
            int left, right;
            cin >> left >> right;
            // Input is 0-based, no conversion needed
            cout << st.query(left, right-1) << "\n";
        }
    }

    return 0;
}