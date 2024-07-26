class MedianFinder {
public:
    
    
    /*
        Approach : 
            1. Take two heaps; min_heap, max_heap
            2. min_heap will contain all the greater half elements and max_heap will contain the lower half elements. This is to facilitate the two middle elements at the top of min_heap and max_heaps
            3. When trying to add an element, always add to exactly one heap for this code it's min_heap. And add the top of min_heap to the max_heap and pop from min_heap. 
            
                example :     max_heap [3, 2, 1]
                              min_heap [8, 10, 12]
                              median right now is 3 + 8 / 2
                              num = 9
                              
                              After addition 
                              max_heap [3, 2, 1]
                              min_heap [8, 9, 10, 12]
                              
                              After max_heap population and min_heap popping
                              max_heap [8, 3, 2, 1]
                              min_heap [9, 10, 12]
                              
                              Since we always want to keep the size of the min_heap more in case of imbalance, we will do the push into min_heap once more of the top of the max_heap and popping it.
                              max_heap [3, 2, 1]
                              min_heap [8, 9, 10, 12]
                              
                              Now the median is 8.
                              
                              
                              let's say num = 11
                              After same steps the heaps will be
                              max_heap [3, 2, 1]
                              min_heap [8, 9, 10, 11, 12]
                              
                              max_heap [8, 3, 2, 1]
                              min_heap [9, 10, 11, 12]
                              
                              New median would be 8 + 9 / 2
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