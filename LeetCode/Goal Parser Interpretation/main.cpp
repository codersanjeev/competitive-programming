class Solution {
  public:
	string interpret(string command) {
		string ans = "";
		int i = 0 , n = command.size();
		while (i < n) {
			if (command[i] == 'G') {
				ans += command[i];
				i++;
			} else if (command[i] == '(' && command[i + 1] == ')') {
				ans += 'o';
				i += 2;
			} else if (command[i] == '(' && command[i + 1] == 'a') {
				ans += "al";
				i += 4;
			}
		}
		return ans;
	}
};