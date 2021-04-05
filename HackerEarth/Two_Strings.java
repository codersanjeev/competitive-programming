import java.io.*;
import java.util.*;

class Two_Strings{
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		while(n!=0){
		    String s = sc.next();
		String t = sc.next();
		if (checkpermut(s, t))
			System.out.println("YES");
		else
			System.out.println("NO");
		n--;
		}

	}

	static boolean checkpermut(String s1, String s2){
		if (s1.length() != s2.length())
			return false;
		int[] letterscount = new int[128];
		char[] s1_array = s1.toCharArray();
		for (char c : s1_array)
			letterscount[c]++;
		for (int i=0; i<s2.length(); i++){
			int c = (int)s2.charAt(i);
			letterscount[c]--;
			if (letterscount[c] < 0)
				return false;
		}
		return true;
	}
}