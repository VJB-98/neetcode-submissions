class MinStack {
    stack<long> s;
    long min;

   public:
    MinStack() {}

    void push(int val) {
        if (s.empty()) {
            s.push(0);
            min = val;
        } else {
            s.push(val - min);
            if (val < min) min = val;
        }
    }

    void pop() {
        long pop = s.top();
        s.pop();

        if (pop < 0) {
            min = min - pop;
        }
    }

    int top() {
        long top = s.top();
        return s.top() > 0 ? (top + min) : min;
    }

    int getMin() { return min; }
};
