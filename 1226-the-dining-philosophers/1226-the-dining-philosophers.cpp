class Semaphore {
private:
    int count;
    mutex mtx;
    condition_variable cv;

public:
    Semaphore(int c = 1) : count(c) {}

    void wait() {
        unique_lock<mutex> lock(mtx);

        while (count == 0)
            cv.wait(lock);

        count--;
    }

    void signal() {
        unique_lock<mutex> lock(mtx);
        count++;
        cv.notify_one();
    }

    bool try_lock() {
        unique_lock<mutex> lock(mtx);

        if (count == 0)
            return false;

        count--;
        return true;
    }
};

class DiningPhilosophers {
private:
    std::mutex forks[5];

public:
    DiningPhilosophers() {}

    void wantsToEat(int i,
                    function<void()> pickLeftFork,
                    function<void()> pickRightFork,
                    function<void()> eat,
                    function<void()> putLeftFork,
                    function<void()> putRightFork) {
        
      
        int left = i;
        int right = (i + 1) % 5;
        
        
        int first = std::min(left, right);
        int second = std::max(left, right);
        
    
        forks[first].lock();
        forks[second].lock();
        
      
        pickLeftFork();
        pickRightFork();
        eat();
        putLeftFork();
        putRightFork();

        forks[second].unlock();
        forks[first].unlock();
    }
};     
