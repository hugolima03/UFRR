class q3 {
  public static void main(String[] args) {
    int i;
    for (i = 0; i < 101; i++) {
      int rest = i % 3;
      if (rest == 0) System.out.println(i);
    }
  }
}