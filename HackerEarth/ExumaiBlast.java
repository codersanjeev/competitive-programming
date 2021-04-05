import java.util.Scanner;
class StringOperations {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
               String input = scanner.nextLine();
       input = input.toUpperCase();
        int count = 0;
        for (int i = 1; i < input.length(); i++) {
            if (input.charAt(i) == input.charAt(i - 1)) {
                count++;
            }
        }
        System.out.println(count);
    }
}