import java.util.*;
import java.lang.*;
import java.io.*;

public class Solution {
	static void dfs(List<String>[] dp, List<String> result, String current, int i) {
		if (i == 0) {
			result.add(current.trim());
			return;
		}
		for (String s : dp[i]) {
			String combined = s + " " + current;
			dfs(dp, result, combined, i - s.length());
		}
	}

	public ArrayList<String> wordBreak(String word, ArrayList<String> dict) {
		if (null == word || word.isEmpty() || null == dict || dict.isEmpty()) {
			return new ArrayList<String>(0);
		}

		ArrayList<String>[] dp = new ArrayList[word.length() + 1];
		dp[0] = new ArrayList<>();

		for (int i = 1; i <= word.length(); i++) {
			for (int j = 0; j < i; j++) {
				String check = word.substring(j, i);
				if (null != dp[j] && dict.contains(check)) {
					if (null == dp[i]) {
						dp[i] = new ArrayList<>();
					}
					dp[i].add(check);
				}
			}
		}
		if (null == dp[word.length()]) {
			return new ArrayList<String>(0);
		}
		ArrayList<String> result = new ArrayList<>();
		dfs(dp, result, "", word.length());
		Collections.sort(result);
		return result;
	}
}
