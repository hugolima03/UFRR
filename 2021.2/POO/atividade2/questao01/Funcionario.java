package questao01;

public class Funcionario {
  String name;
  String department;
  Double pay;
  String initialDate;
  String id;

  void recebeAumento(double value) {
    this.pay += value;
    System.out.println("Salário aumentado, novo salário: " + this.pay);
  }
  
  void calculaGanhoAnual() {
    System.out.println("Salário anual: " + this.pay * 12);
  }
}