// Isso ocorre pois o tipo Int possui um número limitado de bits de informação, podendo alcançar até 65536

public class q6 {
  public static void main(String[] args) {
    for (long n = 1; n <= 20; n++) {
      long num = n;

      for (long j = (num - 1); j >= 1; j--) {
        num *= j;
      }

      System.out.println(num);
    }
  }
}
