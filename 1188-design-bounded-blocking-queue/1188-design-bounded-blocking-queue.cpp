class BoundedBlockingQueue {
    queue<int>q;
    mutex mtx;
    condition_variable cv;
    int capacity;
    int curr_size;
public:
    BoundedBlockingQueue(int capacity) {
        this->capacity=capacity;
    }
    
    void enqueue(int element) {
        unique_lock<mutex> lck(mtx);
        cv.wait(lck,[this](){return curr_size<capacity;});
        q.push(element);
        curr_size++;
        cv.notify_all();
    }
    
    int dequeue() {
        unique_lock<mutex> lck(mtx);
        cv.wait(lck,[this](){return curr_size>0;});
        int ans=q.front();
        q.pop();
        curr_size--;
        cv.notify_all();
        return ans;
    }
    
    int size() {
        lock_guard<mutex> lck(mtx);
        return curr_size;
    }
};