class FooBar {
private:
    int n;
    mutex mtx;
    condition_variable cv;
    bool isFooTurn;

public:
    FooBar(int n) {
        this->n = n;
        isFooTurn=1;
    }

    void foo(function<void()> printFoo) {
        
        for (int i = 0; i < n; i++) {
            
        	// printFoo() outputs "foo". Do not change or remove this line.
            unique_lock<mutex> lck(mtx);
            cv.wait(lck,[this](){return isFooTurn==1;});
        	printFoo();
        	isFooTurn=0;
            cv.notify_all();
        }
    }

    void bar(function<void()> printBar) {
        
        for (int i = 0; i < n; i++) {
            unique_lock<mutex> lck(mtx);
            cv.wait(lck,[this](){return isFooTurn==0;});
            
        	// printBar() outputs "bar". Do not change or remove this line.
        	printBar();
            isFooTurn=1;
            cv.notify_all();
        }
    }
};