class FizzBuzz {
private:
    int n;
    int i;
    mutex mtx;
    condition_variable cv;

public:
    FizzBuzz(int n) {
        this->n = n;
        i = 1;
    }

    void fizz(function<void()> printFizz) {
        while (true) {
            unique_lock<mutex> lock(mtx);

            while (i <= n && !(i % 3 == 0 && i % 5 != 0))
                cv.wait(lock);

            if (i > n) {
                cv.notify_all();
                return;
            }

            printFizz();
            i++;
            cv.notify_all();
        }
    }

    void buzz(function<void()> printBuzz) {
        while (true) {
            unique_lock<mutex> lock(mtx);

            while (i <= n && !(i % 3 != 0 && i % 5 == 0))
                cv.wait(lock);

            if (i > n) {
                cv.notify_all();
                return;
            }

            printBuzz();
            i++;
            cv.notify_all();
        }
    }

    void fizzbuzz(function<void()> printFizzBuzz) {
        while (true) {
            unique_lock<mutex> lock(mtx);

            while (i <= n && !(i % 3 == 0 && i % 5 == 0))
                cv.wait(lock);

            if (i > n) {
                cv.notify_all();
                return;
            }

            printFizzBuzz();
            i++;
            cv.notify_all();
        }
    }

    void number(function<void(int)> printNumber) {
        while (true) {
            unique_lock<mutex> lock(mtx);

            while (i <= n && !(i % 3 != 0 && i % 5 != 0))
                cv.wait(lock);

            if (i > n) {
                cv.notify_all();
                return;
            }

            printNumber(i);
            i++;
            cv.notify_all();
        }
    }
};