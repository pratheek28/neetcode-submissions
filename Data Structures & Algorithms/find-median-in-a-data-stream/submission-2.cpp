class MedianFinder {
    priority_queue<int, vector<int>, greater<int>> minHeap;
    priority_queue<int> maxHeap;
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if (maxHeap.empty() || num <= maxHeap.top()) {
            maxHeap.push(num);
        }else {
            minHeap.push(num);
        }

        if (maxHeap.size() > minHeap.size() + 1) {
            int val = maxHeap.top();
            maxHeap.pop();
            minHeap.push(val);
        }else if (minHeap.size() > maxHeap.size()) {
            int val = minHeap.top();
            minHeap.pop();
            maxHeap.push(val);
        }
    }
    
    double findMedian() {
        if (maxHeap.size() > minHeap.size()) {
            return maxHeap.top();
        }

        return (maxHeap.top() + minHeap.top()) / 2.0;
    }
};