% Aluno: Hugo Lima Romão
% Avaliação 2 - DCC511
% Questão 6

% Comando para executar: swipl -s q6.pl

% Fatos - filme(Título, Gênero, Diretor, Ano, Duração)
filme('Amnésia', 'Suspense', 'Nolan', 2000, 113).
filme('Babel', 'Drama', 'Inarritu', 2006, 142).
filme('Capote', 'Drama', 'Miller', 2005, 98).
filme('Casablanca', 'Romance', 'Curtiz', 1942, 102).
filme('Matrix', 'Ficção', 'Wachowsk', 1999, 136).
filme('Rebecca', 'Suspense', 'Hitchcock', 1940, 130).
filme('Shrek', 'Aventura', 'Adamson', 2001, 90).
filme('Sinais', 'Ficção', 'Shymalan', 2002, 106).
filme('Spartacus', 'Ação', 'Kubrik', 1960, 184).
filme('Superman', 'Aventura', 'Donner', 1978, 143).
filme('Titanic', 'Romance', 'Cameron', 1997, 194).
filme('Tubarão', 'Suspense', 'Spielberg', 1975, 124).
filme('Volver', 'Drama', 'Almodóvar', 2006, 121).

suspense(X, Y, Z, W, V) :- filme(X, Y, Z, W, V), Y == 'Suspense'.
menorQue100(X, Y, Z, W, V) :- filme(X, Y, Z, W, V), V < 100.
entre2000E2005(X, Y, Z, W, V) :- filme(X, Y, Z, W, V), W >= 2000, W =< 2005.
classico(W) :- filme(_, _, _, W, _), W < 1980.
genero(X) :- filme(_, X, _, _, _).

% Quem	dirigiu	o	filme	Titanic?
?- filme('Titanic', _, D, _, _)

% Quais	são	os	filmes	de	suspense?
?- forall(suspense(X, Y, Z, W, V), writeln([X, Y, Z, W, V])).

% Quais	os	filmes	dirigidos	por	Donner?

?- filme(T, _, 'Donner', _, _)

% Em que	ano	foi	lançado	o	filme	Sinais?

?- filme('Sinais', _, _, A, _)

% Quais	os	filmes	com	duração inferior	a	100min.?

?- forall(menorQue100(X, Y, Z, W, V), writeln([X, Y, Z, W, V])).

% Quais	os	filmes	lançados	entre	2000	e	2005?

?- forall(entre2000E2005(X, Y, Z, W, V), writeln([X, Y, Z, W, V])).

% Usando	regra,	defina	o	predicado	clássico/1,	que	só	recupera	títulos	de	filmes	lançados antes	de	1980.

?- forall(classico(X), writeln([X])).

% Usando	 regra,	 defina	 o	 predicado	 gênero/2,	 que	 só	 recupera	 títulos	 de	 filmes	 de	 um	gênero	específico.

- forall(genero(X), writeln([X, Y, Z, W, V])).

% Usando	 clássico/1	 e	 gênero/2,	 faça	 uma	 consulta	 para	 recuperar	 títulos	 de	 filmes	clássicos	de	suspense.