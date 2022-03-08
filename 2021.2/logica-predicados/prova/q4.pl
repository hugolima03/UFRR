% Aluno: Hugo Lima Romão
% Avaliação 2 - DCC511
% Questão 3

% Fatos
% funcionario(Código, Nome, Salário) 
funcionario(1, ana, 1000.90). 
funcionario(2, bia, 1200.00). 
funcionario(3, ivo, 903.50).
funcionario(4, leo, 2500.35).
funcionario(5, clô, 1800.00).
funcionario(6, gil, 1100.00).

% depende(Código, Nome)
depende(1, ary). 
depende(3, rai). 
depende(3, eva). 
depende(4, lia). 
depende(4, noé).
depende(5, eli).

% Query para consultar dependentes da Ivo.
?- funcionario(Codigo,ivo,_), depende(Codigo, Nome).

% Query para consultar quem depende de funcionário com salário inferior a 950.00.
?- funcionario(Codigo, _, Salario), depende(Codigo, Nome), Salario < 950.

% Query para consultar funcionários que não possuem dependentes.
?- funcionario(Codigo, Nome, _), not(depende(Codigo, _)).

% Query para consultar quem tem salário entre 1500 e 3000
?- funcionario(Codigo, _, Salario), Salario > 1500, Salario < 3000.