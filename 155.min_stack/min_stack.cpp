class MinStack {
private:
    stack<int> s;
    stack<int> min;
public:
    void push(int x) {
        s.push(x);
        if (min.empty() || x <= min.top()) {
            min.push(x);
        }
    }

    void pop() {
        int x = s.top();
        s.pop();
        if (!min.empty() && x == min.top())
            min.pop();
    }

    int top() {
        return s.top();
    }

    int getMin() {
        return min.top();
    }
};
