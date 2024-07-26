class MedianFinder {
public:
    
    /*
        Approach : 
        1. Put first half of the stream in a max_heap and second half in a min_heap as they would appear sorted in the stream.
        2. To execute this minimally, always put the element in min_heap first, and then shift the top of min_heap to max_heap if required. 
    */    
    priority_queue<int, vector<int>, greater<int>> min_heap;
    priority_queue<int> max_heap;
    
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        min_heap.push(num);
        max_heap.push(min_heap.top());
        min_heap.pop();
        if (max_heap.size() > min_heap.size()) {
            min_heap.push(max_heap.top());
            max_heap.pop();
        }
    }
    
    double findMedian() {
        if (max_heap.size() < min_heap.size()) return min_heap.top();
        return (double)(min_heap.top() + max_heap.top())/2;
        // return min_heap.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */