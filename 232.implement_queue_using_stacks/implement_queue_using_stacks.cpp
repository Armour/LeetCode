class Queue {
private:
    stack<int> s1, s2;

public:
    // Push element x to the back of queue.
    void push(int x) {
        s1.push(x);
    }

    // Removes the element from in front of queue.
    void pop(void) {
        if (!s2.empty()) {
            s2.pop();
        } else {
            if (s1.empty())
                return;
            while (s1.size() != 1) {
                int x = s1.top();
                s1.pop();
                s2.push(x);
            }
            s1.pop();
        }
    }

    // Get the front element.
    int peek(void) {
        if (!s2.empty()) {
            return s2.top();
        } else {
            if (s1.empty())
                return NULL;
            while (!s1.empty()) {
                int x = s1.top();
                s1.pop();
                s2.push(x);
            }
            return s2.top();
        }
    }

    // Return whether the queue is empty.
    bool empty(void) {
        return (s1.empty() && s2.empty());
    }
};
