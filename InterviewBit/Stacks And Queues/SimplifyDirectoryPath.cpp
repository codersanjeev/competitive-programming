string Solution::simplifyPath(string path) {
	vector <string> aList;
	int aPrevIndex = 0;
	for (int i = 0; i < path.size(); i++) {
		if (path[i] == '/') {
			if (i > aPrevIndex) {
				aList.push_back(path.substr(aPrevIndex, i - aPrevIndex));
			}
			aPrevIndex = i + 1;
		}
	}
	if (path.size() > aPrevIndex) {
		aList.push_back(path.substr(aPrevIndex, path.size() - aPrevIndex));
	}
	vector <string> aStack;
	for (int i = 0; i < aList.size(); i++) {
		if (aList[i] == ".") { continue; }
		if (aList[i] == "..") {
			if (aStack.empty() == false) {
				aStack.pop_back();
			}
			continue;
		}
		if (aList[i].size() > 0) {
			aStack.push_back(aList[i]);
		}
	}
	string aResult = "/";
	for (int i = 0; i < aStack.size(); i++) {
		aResult += aStack[i];
		if (i < (aStack.size() - 1)) {
			aResult += "/";
		}
	}
	return aResult;
}
