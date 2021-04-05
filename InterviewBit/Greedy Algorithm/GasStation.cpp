int Solution::canCompleteCircuit(const vector<int> &gas, const vector<int> &cost) {
	int start = 0, total = 0, tank = 0;
	int n = gas.size();
	for (int i = 0; i < n; i++) {
		if ((tank = tank + gas[i] - cost[i]) < 0) {
			start = i + 1;
			total += tank;
			tank = 0;
		}
	}
	return (total + tank < 0) ? -1 : start;
}
