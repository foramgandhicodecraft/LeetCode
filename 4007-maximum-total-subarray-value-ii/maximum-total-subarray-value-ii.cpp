class SegmentTree {
    vector<int> segmentTree;
    bool isMinTree;
    int n;

public:
    SegmentTree (vector<int>& nums, bool flag) {
        n = nums.size();
        this->isMinTree = flag;

        segmentTree.resize(4*n);

        buildSegmentTree(0, 0, n-1, nums);
    }

    void buildSegmentTree(int i, int l, int r, vector<int>& nums) {
        if (l == r){
            segmentTree[i] = nums[l];
            return;
        }

        int mid = l + (r-l)/2;

        buildSegmentTree(2*i+1, l, mid, nums);
        buildSegmentTree(2*i+2, mid+1, r, nums);   // was 2*i-1 (bug)

        if (isMinTree){
            segmentTree[i] = min(segmentTree[2*i+1], segmentTree[2*i+2]);
        } else {
            segmentTree[i] = max(segmentTree[2*i+1], segmentTree[2*i+2]);
        }
    }

    int querySegmentTree (int start, int end, int i, int l, int r) {
        if (l > end || r < start) {
            return isMinTree ? INT_MAX : INT_MIN;
        }

        if (l >= start && r <= end) {
            return segmentTree[i];
        }

        int mid = l + (r-l)/2;

        int left  = querySegmentTree(start, end, 2*i+1, l, mid);
        int right = querySegmentTree(start, end, 2*i+2, mid+1, r);

        if (isMinTree) return min(left, right);
        else           return max(left, right);
    }

    int query (int start, int end) {
        return querySegmentTree(start, end, 0, 0, n-1);
    }
};

class Solution {
public:

    long long getValue (int l, int r, SegmentTree& minST, SegmentTree& maxST) {
        int minEl = minST.query(l,r);
        int maxEl = maxST.query(l,r);

        return (long long)maxEl - minEl;
    }
    long long maxTotalValue(vector<int>& nums, int k) {
        int n = nums.size();

        SegmentTree minST(nums, true);
        SegmentTree maxST(nums, false);

        // {val, l, r}
        priority_queue<tuple<long long, int, int>> pq;

        // step 1: initialize heap with best value for each l = 0 to n-1
        for (int l = 0; l < n; l++){
            long long value = getValue(l, n-1, minST, maxST);
            pq.push({value, l, n-1});
        }

        // step 2: find top k best values
        long long result = 0;
        while (k--) {
            auto [value, l, r] = pq.top();
            pq.pop();
            result += value;
            if (r - 1 >= l) {   // guard so we don't query an empty range
                long long nextBestValue = getValue(l, r-1, minST, maxST);
                pq.push({nextBestValue, l, r-1});
            }
        }

        return result;
    }
};