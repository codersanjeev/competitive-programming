public class Solution {
	public int solve(ArrayList<String> listStr) {
		if (listStr == null) { return 0; }
		int n = listStr.size();
		if (n == 0) { return 0; }
		String[] arrStr = listStr.toArray(new String[n]);
		int len = n;
		while (len > 1) {
			int overlapMax = 0;
			int I = 0, J = 0;
			String resStr = "";
			for (int i = 0; i < len; i++) {
				for (int j = i + 1; j < len; j++) {
					String curStr = findOverlap(arrStr[i], arrStr[j]);
					int overlapCur = - curStr.length() + arrStr[i].length() + arrStr[j].length();
					//System.out.println(i + " " + j + " " + curStr);
					if (overlapMax < overlapCur) {
						overlapMax = overlapCur;
						resStr = curStr;
						I = i;
						J = j;
					}
				}
			}
			--len;
			if (overlapMax == 0) {
				arrStr[0] += arrStr[len];
			} else {
				arrStr[I] = resStr;
				arrStr[J] = arrStr[len];
			}
		}
		return arrStr[0].length();
	}
	private String findOverlap(String a, String b) {
		int la = a.length();
		int lb = b.length();
		String res = a + b;
		for (int k = 1; k <= la; k++) {
			if (k > lb) { break; }
			if (b.endsWith(a.substring(0, k))) {
				res = b + a.substring(k);
			}
		}
		for (int k = 1; k <= lb; k++) {
			if (k > la) { break; }
			if (a.endsWith(b.substring(0, k))) {
				String tmpRes = a + b.substring(k);
				if (res.length() > tmpRes.length()) {
					res = tmpRes;
				}
			}
		}
		return res;
	}
}
