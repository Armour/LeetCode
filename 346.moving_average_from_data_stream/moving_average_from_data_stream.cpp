class MovingAverage {
public:
    queue<double> q;
    int n;
    double sum;

    /** Initialize your data structure here. */
    MovingAverage(int size) {
        n = size;
        sum = 0;
    }
    
    double next(int val) {
        if (q.size() >= n) {
            int v = q.front();
            q.pop();
            sum -= v;
        }
        q.push(val);
        sum += val;
        return sum / q.size();
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage obj = new MovingAverage(size);
 * double param_1 = obj.next(val);
 */
