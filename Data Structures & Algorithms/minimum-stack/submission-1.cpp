class MinStack {
    stack<int> s;
    stack<int> mins;
    // int prev_min = INT_MAX;

   public:
    MinStack() {}

    void push(int val) {
        s.push(val);
        // prev_min = min(prev_min, val);
        if (mins.empty()) 
            mins.push(val);
        else
            mins.push(min(val, mins.top()));
    }

    void pop() {
        s.pop();
        mins.pop();
    }

    int top() { return s.top(); }

    int getMin() { return mins.top(); }
};
