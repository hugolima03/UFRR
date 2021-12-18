package atividade2;

public class TestFuncionario {
  public static void main(String[] args) {
    Funcionario hugo = new Funcionario();

    hugo.name = "Hugo";
    hugo.department = "Programador de ";
    hugo.pay= 10.0;
    hugo.initialDate = "Hugo";
    hugo.id = "12121212-9";
    hugo.mostrar();

    hugo.recebeAumento(1600);

    hugo.calculaGanhoAnual();
  }
}
