#include <bits/stdc++.h>
using namespace std;

struct PersistentSegTree {
private:
    struct SegNode {
        int val = 0;
        SegNode *left = nullptr;
        SegNode *right = nullptr;
    };

    void buildSeg(SegNode *root, int l, int r) {
        if(l == r) return;
        int mid = (l+r)/2;
        root->left = new SegNode();
        root->right = new SegNode();
        buildSeg(root->left, l, mid);
        buildSeg(root->right, mid+1, r);
    }

    void updateSeg(SegNode *prev, SegNode *root, int l, int r, const int pos, const int x) {
        if(l == r) {
            root->val = x;
            return;
        }
        int mid = (l+r)/2;
        if(pos <= mid) {
            root->right = prev->right;
            root->left = new SegNode();
            updateSeg(prev->left, root->left, l, mid, pos, x);
        } else {
            root->left = prev->left;
            root->right = new SegNode();
            updateSeg(prev->right, root->right, mid+1, r, pos, x);
        }
        root->val = root->left->val + root->right->val;
    }

    int querySeg(SegNode *root, int l, int r, const int i, const int j) {
        if(i > r or j < l) return 0;
        if(i <= l and r <= j) return root->val;
        int mid = (l+r)/2;
        return querySeg(root->left, l, mid, i, j) + querySeg(root->right, mid+1, r, i, j);
    }

    vector<SegNode> seg;
    int L, R;

public:
    PersistentSegTree(int l, int r) {
        seg.assign(1, SegNode());
        L = l;
        R = r;
        buildSeg(&seg[0], l, r);
    }

    void add(int pos, int x) {
        SegNode newNode;
        updateSeg(&seg.back(), &newNode, L, R, pos, x);
        seg.push_back(newNode);
    }

    int query(int index, int i, int j) {
        return querySeg(&seg[index], L, R, i, j);
    }
};

// int main() {
    
//     PersistentSegTree pst(0, 100);

//     pst.add(0, 10);
//     pst.add(50, 10);
//     pst.add(75, 10);
//     pst.add(100, 10);

//     cout << pst.query(4, 1, 99) << endl;

//     return 0;
// }