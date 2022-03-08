% Aluno: Hugo Lima Romão
% Avaliação 2 - DCC511
% Questão 2

% Comando para executar: swipl -s q2.pl

% Fatos - filme(Título, Gênero, Ano, Duração)
filme('Uma linda mulher', romance, 1990, 119).
filme('Sexto sentido', suspense, 2001, 108).
filme('A cor púrpura', drama, 1985, 152).
filme('Copacabana', comédia, 2001, 92).
filme('E o vento levou', drama, 1939, 233).
filme('Carrington', romance, 1995, 130).

% Regras
classico(X, Y, Z, W) :- filme(X, Y, Z, W), Z =< 1985.

classico(X, Y) :- filme(X, Y, Z, _), Z =< 1985.

% Query para filmes clássicos
?- forall(classico(X, Y, Z, W),writeln([X, Y, Z, W])).

% Query para nome e genero dos filmes clássicos.
?- forall(classico(X, Y),writeln([X, Y])).