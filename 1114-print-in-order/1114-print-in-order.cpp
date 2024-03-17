class Foo {
    condition_variable firstJobDone,secondJobDone;
    mutex firstMutex,secondMutex;
    bool firstDone,secondDone;
public:
    Foo() {
        firstDone=0;
        secondDone=0;
    }

    void first(function<void()> printFirst) {
        
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        unique_lock<mutex> lck(firstMutex);
        firstDone=1;
        firstJobDone.notify_all();
        
    }

    void second(function<void()> printSecond) {
        
        // printSecond() outputs "second". Do not change or remove this line.
        unique_lock<mutex> lck1(firstMutex);
        firstJobDone.wait(lck1,[this](){return firstDone==1;});
        printSecond();
        unique_lock<mutex> lck2(secondMutex);
        secondDone=1;
        secondJobDone.notify_all();
        firstDone=0;
        
    }

    void third(function<void()> printThird) {
        unique_lock<mutex> lck2(secondMutex);
        secondJobDone.wait(lck2,[this](){return secondDone==1;});
        // printThird() outputs "third". Do not change or remove this line.
        printThird();
        secondDone=0;
    }
};