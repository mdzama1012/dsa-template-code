// Min-stack implementation in O(1) space

#include <bits/stdc++.h>

class minStack {
private:
	int currMin;
	stack<int> myStack;

    int flag(int num) {
        return num - currMin;
    }

    int getPrevMin(int flag) {
        return currMin - flag;
    }

public:
		minStack() {
			currMin = -1;
		}

		void push(int num) {
			if (myStack.empty()) {
				currMin = num;
				myStack.push(num);
			} else if (num < currMin) {
				myStack.push(flag(num));
				currMin = num;
			} else {
				myStack.push(num);
			}
		}

		int pop() {
			if (myStack.empty()) return -1;

			int popped = top();
			if (myStack.top() < 0) {
				currMin = getPrevMin(myStack.top());
			}
			myStack.pop();
			return popped;
		}

		int top() {
			if (myStack.empty()) return -1;

			if (myStack.top() < 0) {
				return currMin;
			}
			return myStack.top();
		}

		int getMin() {
			if (myStack.empty()) return -1;
			return currMin;
		}
};
