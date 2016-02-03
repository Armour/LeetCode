class Stack {
private:
    queue<int> q1, q2;

    void swap_queue() {
        queue<int> tmp;
        tmp = q1;
        q1 = q2;
        q2 = tmp;
    }

public:
    // Push element x onto stack.
    void push(int x) {
        q1.push(x);
    }

    // Removes the element on top of the stack.
    void pop() {
        if (q1.empty())
            return;
        while (q1.size() != 1) {
            int x = q1.front();
            q1.pop();
            q2.push(x);
        }
        q1.pop();
        swap_queue();
    }

    // Get the top element.
    int top() {
        if (q1.empty())
            return NULL;
        while (q1.size() != 1) {
            int x = q1.front();
            q1.pop();
            q2.push(x);
        }
        int x = q1.front();
        q1.pop();
        q2.push(x);
        swap_queue();
        return x;
    }

    // Return whether the stack is empty.
    bool empty() {
        return q1.empty();
    }
};
