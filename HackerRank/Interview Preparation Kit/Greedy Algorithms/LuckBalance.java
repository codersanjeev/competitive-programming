import java.util.*;

public class Solution {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int k = scanner.nextInt();
        int total = 0;
        List<Integer> importantContests = new ArrayList<>();
        for (int i=0; i<n; i++){
            int luck = scanner.nextInt();
            int importance = scanner.nextInt();
            total += luck;
            if (importance == 1) {
                importantContests.add(luck);
            } 
        }
        Collections.sort(importantContests);
        int luckToFlip = 0;
        int mustWinImprCount = importantContests.size() - k;
        for (int i=0; i<mustWinImprCount; i++){
            luckToFlip += importantContests.get(i);
        }
        int result = total - 2*luckToFlip;
        System.out.println(result);
    }
}
