import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class Solution {

    static int minTime(int[][] roads, int[] machines) {
    Arrays.sort(roads, (x, y) -> Integer.compare(y[2], x[2]));

    int n = roads.length + 1;
    Map<Integer,Integer> parent = new HashMap<>();
    boolean[] red = new boolean[n];
    for(int machine: machines) red[machine]=true;

    // Find by Path Splitting
    java.util.function.IntFunction<Integer> find = x -> {
        while(x != parent.getOrDefault(x, x)) {
            x = parent.put(x, parent.get(x));
        }
        return x;
    };

    // Union by Size
    int[] size = new int[n];
    for(int i = 0; i < n; i++) size[i] = 1;
    java.util.function.Function<int[],Integer> union = roadArray -> {
        int root1 = find.apply(roadArray[0]);
        int root2 = find.apply(roadArray[1]);
        if(red[root1] && red[root2]) return roadArray[2];

        if(root1 != root2) {
            if(size[root1] > size[root2]) {
                int r = root1;
                root1 = root2;
                root2 = r;
            }
            parent.put(root1, root2);
            size[root2] += size[root1];
        }

        red[root1] |= red[root2];
        red[root2] |= red[root1];
        return 0;
    };

    return Arrays.stream(roads)
        .map(roadArray -> union.apply(roadArray))
        .reduce(0, Integer::sum);
}
    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) throws IOException {
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        String[] nk = scanner.nextLine().split(" ");

        int n = Integer.parseInt(nk[0]);

        int k = Integer.parseInt(nk[1]);

        int[][] roads = new int[n - 1][3];

        for (int i = 0; i < n - 1; i++) {
            String[] roadsRowItems = scanner.nextLine().split(" ");
            scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

            for (int j = 0; j < 3; j++) {
                int roadsItem = Integer.parseInt(roadsRowItems[j]);
                roads[i][j] = roadsItem;
            }
        }

        int[] machines = new int[k];

        for (int i = 0; i < k; i++) {
            int machinesItem = scanner.nextInt();
            scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");
            machines[i] = machinesItem;
        }

        int result = minTime(roads, machines);

        bufferedWriter.write(String.valueOf(result));
        bufferedWriter.newLine();

        bufferedWriter.close();

        scanner.close();
    }
}
