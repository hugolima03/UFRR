#include <stdio.h>
#include <stdlib.h>

#define tm 3

struct Data
{
  int dia;
  int ano;
  char mes[30];
};

struct Funcionario
{
  char nome[31];
  int idade;
  char sexo;
  char cpf[21];
  char cargo[30];
  struct Data nascimento;
  int salario;
};

int main()
{
  struct Funcionario func[tm];

  for (int i = 0; i < tm; i++)
  {
    printf("Nome: \n");
    scanf("%s", func[i].nome);

    printf("Idade: \n");
    scanf("%d", &func[i].idade);

    printf("Sexo: \n");
    scanf("%s", &func[i].sexo);

    printf("Cpf: \n");
    scanf("%s", func[i].cpf);

    printf("Cargo: \n");
    scanf("%s", func[i].cargo);

    printf("Salario: \n");
    scanf("%d", &func[i].salario);

    printf("Data de nascimento: \n");
    scanf("%d %s %d", &func[i].nascimento.dia, func[i].nascimento.mes, &func[i].nascimento.ano);
  }

  for (int i = 0; i < tm; i++)
  {
    printf("\n%s, %d, %s, %s, %s, %d\n", func[i].nome, func[i].idade, &func[i].sexo, func[i].cpf, func[i].cargo, func[i].salario);
  }

  return 0;
}