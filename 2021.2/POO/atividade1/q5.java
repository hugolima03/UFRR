public class q5 {
  public static void main(String[] args) {
    for (int n = 1; n <= 10; n++) {
      int num = n;

      for (int j = (num - 1); j >= 1; j--) {
        num *= j;
      }

      System.out.println(num);
    }
  }
}
