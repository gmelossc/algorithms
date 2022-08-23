#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e5;
// time complexity: O(nlog n)
//for each node i, we have a node built on a heap structure, so left son is 2*i and right son is 2*i+1
//for each node [i, j] --> left son is [i, (i+j)/2] and right son is [(i+j)/2 +1 , j]
//in this example i'll use seg tree to find the minimum value in a given range [a, b], so each node has the min value in [i, j]
int st[MAX << 2], values[MAX];

void build(int node, int i, int j){ // build seg tree at initial state
    if(i == j){ // if node is a leaf
        st[node] = values[i]; // some value, depending on the problem youre solving
        return;
    }
    else{ // otherwise
        int l = node << 1;
        int r = (node << 1) | 1;
        int m = (i+j) >> 1;

        build(l, i, m);
        build(r, m+1, j);

        //do some stuff on your seg tree
        if(values[st[l]] < values[st[r]]) st[node] = st[l];
        else st[node] = st[r];
    }
}

void update(int node, int i, int j, int pos, int new_value){ // updates a new_value in a given positiion pos and recalculates each node in O(log n)
    if(i == j){
        st[node] = new_value;
    }
    else{
        int l = (node << 1);
        int r = (node << 1) | 1;
        int m = (i+j) >> 1;

        if(pos <= m) update(l, i, m, pos, new_value); // if pos is before middle position, we go to left node
        else update(r, m+1, j, pos, new_value);// else we go to a right node

        //do some trivial alteration on st[node] depending on the problem needs
        st[node] = max(st[r], st[l]);
    }
}

int query(int node, int i, int j, int a, int b){
    if(i>=a && j <= b) return st[node]; //if [i,j] is subset of [a, b], we already have this value precalculated
    else if(i > b || j < a) return -1; // else the both sets are disjoint

    //otherwise, need to calculate the insersection of sets

    int l = node << 1;
    int r = (node << 1) | 1;
    int m = (i+j) >> 1;

    int lans = query(l, i, m, a, b);
    int rans = query(r, m+1, j, a, b);

    if(rans == -1) return lans;
    if(lans == -1) return rans;

    if(lans < rans) return lans;
    else return rans;
}


struct SegTree {
    int N;
    vector<int> seg;

    SegTree(int n) {
        N = n<<2;
        seg.assign(N, 0);
    }

    SegTree(vector<int> &arr) {
        N = arr.size() << 2;
        seg.assign(N, 0);
        build(1, 0, arr.size()-1, arr);
    }

    void update(int index, int value) {
        update(1, 0, (N>>2)-1, index, value);
    }

    void update_range(int left, int right) {
        // to be implemented with lazy propagation
    }

    int query(int index) {
        return query(1, 0, (N>>2)-1, index, index);
    }

    int query_range(int left, int right) {
        return query(1, 0, (N>>2)-1, left, right);
    }

private:
    void build(int node, int i, int j, vector<int> &arr){ // build seg tree at initial state
        if(i == j){ // if node is a leaf
            seg[node] = arr[i]; // some value, depending on the problem youre solving
            return;
        }
        else{ // otherwise
            int l = node << 1;
            int r = (node << 1) | 1;
            int m = (i+j) >> 1;

            build(l, i, m, arr);
            build(r, m+1, j, arr);

            //do some stuff on your seg tree
            seg[node] = seg[l] + seg[r];
        }
    }

    void update(int node, int i, int j, int pos, int new_value) { // updates a new_value in a given positiion pos and recalculates each node in O(log n)
        if(i == j){
            seg[node] = new_value;
        }
        else{
            int l = (node << 1);
            int r = (node << 1) | 1;
            int m = (i+j) >> 1;

            if(pos <= m) update(l, i, m, pos, new_value); // if pos is before middle position, we go to left node
            else update(r, m+1, j, pos, new_value);// else we go to a right node

            //do some trivial alteration on st[node] depending on the problem needs
            seg[node] = seg[l] + seg[r];
        }
    }

    int query(int node, int i, int j, int a, int b){
        if(i>=a && j<=b) return seg[node]; //if [i,j] is subset of [a, b], we already have this value precalculated
        else if(i > b || j < a) return 0; // else the both sets are disjoint

        //otherwise, need to calculate the insersection of sets

        int l = node << 1;
        int r = (node << 1) | 1;
        int m = (i+j) >> 1;

        int lans = query(l, i, m, a, b);
        int rans = query(r, m+1, j, a, b);

        return lans + rans;
    }
};


struct BigSegTree {
    struct STNode {
        int val = 0;
        int l, r;
        STNode *left = nullptr;
        STNode *right = nullptr;

        STNode() {};
        STNode(int _l, int _r) : l(_l), r(_r) {};
    };

    STNode seg;

    BigSegTree(int l, int r) {
        seg = STNode(l, r);
    }

    void update(int i, int x) {
        update(&seg, i, x);
    }

    int query(int i, int j) {
        return query(&seg, i, j);
    }

private:
    void update(STNode *root, const int i, const int x) {
        if(root->l == root->r) {
            root->val += x;
            return;
        }
        int mid = (root->l + root->r) / 2;
        if(i <= mid) {
            if(root->left == nullptr) root->left = new STNode(root->l, mid);
            update(root->left, i, x);
        } else {
            if(root->right == nullptr) root->right = new STNode(mid+1, root->r);
            update(root->right, i, x);
        }
        
        root->val = 0;
        if(root->left != nullptr) root->val += root->left->val;
        if(root->right != nullptr) root->val += root->right->val;
    }

    int query(STNode *root, const int i, const int j) {
        if(root == nullptr or i > root->r or j < root->l) return 0;
        if(i <= root->l and root->r <= j) return root->val;
        return query(root->left, i, j) + query(root->right, i, j);
    }
};

struct EfficientSegTree {
    int n;
    vector<int> a;
    EfficientSegTree(int _n) {
        n = _n;
        a.assign(n << 1, 0);
    }
    void add(int p, int x) {
        for (a[p += n] += x; p > 1; p >>= 1) a[p>>1] = a[p] + a[p^1];
    }
    int query(int l, int r) {  // sum on interval [l, r)
        int res = 0;
        for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
            if (l&1) res += a[l++];
            if (r&1) res += a[--r];
        }
        return res;
    }
};


int main(int argc, char const *argv[])
{
    // BigSegTree st(0, 1000000000);

    // st.update(10, 1);
    // st.update(1000000000, 1);

    // cout << st.query(0, 1000000000) << " " << st.query(10000, 1000000000-1) << " " << st.query(100000, 1000000000) << " " << st.query(10, 10);

    return 0;
}