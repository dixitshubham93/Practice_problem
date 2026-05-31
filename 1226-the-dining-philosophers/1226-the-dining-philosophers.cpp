class Semaphore {
private:
    int count;
    mutex mtx;
    condition_variable cv;

public:
    Semaphore(int c = 1) : count(c) {}
    void setCount(int c){
        count = c;
    }
    void signal() {
        unique_lock<mutex> lock(mtx);
        count++;
        cv.notify_one();
    }

    void wait() {
        unique_lock<mutex> lock(mtx);

        while (count == 0)
            cv.wait(lock);

        count--;
    } 
};

class DiningPhilosophers {
private:
   Semaphore fork[5];
   mutex mtx;
public:
  
    DiningPhilosophers() {
        for(int i = 0;i<5;i++){
            fork[i].setCount(1);
        }
    }

    void wantsToEat(int i,
                    function<void()> pickLeftFork,
                    function<void()> pickRightFork,
                    function<void()> eat,
                    function<void()> putLeftFork,
                    function<void()> putRightFork) {

     
            lock_guard<mutex>lock(mtx);
            fork[i%5].wait();
            fork[(i+1)%5].wait();
            pickLeftFork();
            pickRightFork();
            eat();
            putLeftFork();
            fork[i%5].signal();
            putRightFork();
            fork[(i+1)%5].signal();
       
    }
};