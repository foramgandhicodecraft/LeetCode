class MedianFinder {
public:
// move the lower half elements in max heap and the upper half elements in min heap
priority_queue<int>max_heap;
priority_queue<int, vector<int>, greater<int>>min_heap;
    MedianFinder() { }
    
    void addNum(int num) {
        max_heap.push(num);
        min_heap.push(max_heap.top());
        max_heap.pop();

        while (max_heap.size() < min_heap.size()){
            max_heap.push(min_heap.top());
            min_heap.pop();
        }
    }
    
    
    double findMedian() {
        if (max_heap.size() == min_heap.size()){ // even number of elements
            double ans = (min_heap.top() + max_heap.top()) / 2.0;
            return ans;
        }

        return max_heap.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */