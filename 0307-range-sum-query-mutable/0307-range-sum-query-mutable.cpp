/*
    Best segment tree template
*/
class SegTree {
private:
    vector<int> seg;
public:
    SegTree() {}
    SegTree(vector<int> A) {
        int n = A.size();
        seg.resize(4*n, 0);
        buildTree(0, 0, n-1, A);
    }
    int merge(int a, int b) {
        return a + b;
    }
    void buildTree(int curr, int left, int right, vector<int>& A) {
        if (left == right) {
            seg[curr] = A[left];
            return;
        }

        int mid = left + (right - left)/2;
        buildTree(2 * curr + 1, left, mid, A);
        buildTree(2 * curr + 2, mid + 1, right, A);
        seg[curr] = merge(seg[2 * curr + 1], seg[2 * curr + 2]);
    }
    void updateTree(int curr, int left, int right, int index, int val) {
        // No overalp
        if (index < left || index > right) return;

        // Complete Overlap
        if (left == right) {
            if (left == index) seg[curr] = val;
            return;
        }
        int mid = left + (right - left)/2;
        updateTree(2 * curr + 1, left, mid, index, val);
        updateTree(2 * curr + 2, mid + 1, right, index, val);
        seg[curr] = merge(seg[2 * curr + 1], seg[2 * curr + 2]);
    }
    int queryRange(int curr, int left, int right, int qleft, int qright) {
        // No overlap
        if (qleft > right || qright < left) return 0;

        // Complete overlap(The query totally shadows the current range): Return the current node value
        if (qleft <= left && qright >= right) return seg[curr];
        
        int mid = left + (right - left)/2;
        int left_subtree = queryRange(2 * curr + 1, left, mid, qleft, qright);
        int right_subtree = queryRange(2 * curr + 2, mid + 1, right, qleft, qright);
        return merge(left_subtree, right_subtree);
    }
};

class NumArray {
    SegTree st;
    int n;
public:
    NumArray(vector<int>& nums) {
        this->st = SegTree(nums);
        this->n = nums.size();
    }
    
    void update(int index, int val) {
        st.updateTree(0, 0, n-1, index, val);
    }
    
    int sumRange(int left, int right) {
        return st.queryRange(0, 0, n-1, left, right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */