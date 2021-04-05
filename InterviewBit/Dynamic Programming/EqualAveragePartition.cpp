int getHash(int s, int z, int ii) {
	return s - z + ii;
}

bool isInCache(int nrRemainingElements, int currentIdx, int elementsSum, vector<vector<vector<bool>>> &cache) {
	if (cache.size() <= nrRemainingElements) {
		return false;
	}
	if (cache[nrRemainingElements].size() <= currentIdx) {
		return false;
	}
	if (cache[nrRemainingElements][currentIdx].size() <= elementsSum) {
		return false;
	}
	return cache[nrRemainingElements][currentIdx][elementsSum];
}

void addToCache(int nrRemainingElements, int currentIdx, int elementsSum, vector<vector<vector<bool>>> &cache) {
	if (cache.size() <= nrRemainingElements) {
		cache.resize(nrRemainingElements + 1);
	}
	if (cache[nrRemainingElements].size() <= currentIdx) {
		cache[nrRemainingElements].resize(currentIdx + 1);
	}
	if (cache[nrRemainingElements][currentIdx].size() <= elementsSum) {
		cache[nrRemainingElements][currentIdx].resize(elementsSum + 1);
	}
	cache[nrRemainingElements][currentIdx][elementsSum] = true;
}

vector<vector<int>> pick(int elementsSum, int nrRemainingElements, int currentIdx, vector<int> &A, vector<vector<vector<bool>>> &cache) {
	vector<vector<int>> result;
	if (nrRemainingElements == 0 || elementsSum < 0 || currentIdx >= A.size() || currentIdx > A.size() - nrRemainingElements) {
		return result;
	}
	int key = getHash(elementsSum, nrRemainingElements, currentIdx);
	if ( isInCache(nrRemainingElements, currentIdx, elementsSum, cache)) {
		return result;
	}
	if (nrRemainingElements == 1 && currentIdx == A.size() - 1 &&  A[currentIdx] != elementsSum) {
		addToCache(nrRemainingElements, currentIdx, elementsSum, cache);
		return result;
	}
	if (nrRemainingElements == 1 && A[currentIdx] == elementsSum) {
		result = vector<vector<int>>(2, vector<int>());
		result[0].push_back(A[currentIdx]);
		for (int i = currentIdx + 1; i < A.size(); i++) {
			result[1].push_back(A[i]);
		}
		return result;
	}
	result = pick(elementsSum - A[currentIdx], nrRemainingElements - 1, currentIdx + 1, A, cache);
	if (!result.empty()) {
		result[0].insert(result[0].begin(), A[currentIdx]);
		return result;
	} else {
		result = pick(elementsSum, nrRemainingElements, currentIdx + 1, A, cache);
		if (!result.empty()) {
			result[1].insert(result[1].begin(), A[currentIdx]);
			return result;
		}
	}
	addToCache(nrRemainingElements, currentIdx, elementsSum, cache);
	return result;
}

vector<vector<int> > Solution::avgset(vector<int> &A) {
	sort(A.begin(), A.end());
	vector<vector<int>> result;
	int totalSum = 0;
	for (int i = 0; i < A.size(); i++) {
		totalSum += A[i];
	}
	vector<vector<vector<bool>>> cache;
	for (int sizeOfSet1 = 1; sizeOfSet1 <= A.size() / 2; sizeOfSet1++) {
		double sumOfSet1D = (double) sizeOfSet1 * totalSum / A.size();
		int sumOfSet1 = sumOfSet1D;
		if (abs(sumOfSet1D - sumOfSet1) > 1e-8) { continue; }
		result = pick(sumOfSet1, sizeOfSet1, 0, A, cache);
		if (!result.empty()) {
			return result;
		}
	}
	return result;
}
