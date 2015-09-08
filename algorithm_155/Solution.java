class MinStack {
    Stack<Integer> stack = new Stack<Integer>();
    Stack<Integer> min = new Stack<Integer>();
    
    public void push(int x) {
        stack.push(x);
        if(min.empty()) {
            min.push(x);
        } else if(x <= min.peek()) {
            min.push(x);
        }
    }

    public void pop() {
        int x = stack.pop();
        if(x == min.peek()) {
            min.pop();
        }
    }

    public int top() {
        return stack.peek();
    }

    public int getMin() {
        return min.peek();
    }
}

