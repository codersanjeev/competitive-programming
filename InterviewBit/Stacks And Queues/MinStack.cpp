stack<int> mainStack;
stack<int> minStack;

MinStack::MinStack() {
	while (!mainStack.empty()) {
		mainStack.pop();
	}
	while (!minStack.empty()) {
		minStack.pop();
	}
}

void MinStack::push(int x) {
	mainStack.push(x);
	if (minStack.empty()) {
		minStack.push(x);
	} else {
		int y = minStack.top();
		minStack.push(min(x, y));
	}
}

void MinStack::pop() {
	if (minStack.empty()) {
		return;
	} else {
		minStack.pop();
		mainStack.pop();
	}
}

int MinStack::top() {
	if (minStack.empty()) {
		return -1;
	}
	return mainStack.top();
}

int MinStack::getMin() {
	if (minStack.empty()) {
		return -1;
	} else {
		return minStack.top();
	}
}

