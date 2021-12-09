public class q10 {
  static int n = 50;

  static public void main(String[] args) {
    int i, j;

    for (i = 0; i < n; i++) {
      for (j = 1; j <= i; j++) {
        System.out.printf("%d ", j * i);
      }
      System.out.println("");
    }
  }
}
