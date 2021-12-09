public class q8 {
  public static void main(String[] args) {
    int num = 10;
    int i;

    for (i = 0; i <= num; i++) {
      if (num == 1) {
        break;
      } else {
        if (num % 2 == 0) {
          num /= 2;
        } else {
          num = 3 * (num + 1);
        }
      }
      System.out.println(num);
    }
  }
}
