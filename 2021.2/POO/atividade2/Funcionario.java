package atividade2;

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

  void mostrar() {
    System.out.println(this.name);
    System.out.println(this.department);
    System.out.println(this.pay);
    System.out.println(this.initialDate);
    System.out.println(this.id);
  }
}