% Aluno: Hugo Lima Romão
% Avaliação 2 - DCC511
% Questão 3

% Comando para executar: swipl -s q3.pl

% Fatos - pessoa(Nome,Sexo,Altura).
pessoa(ana,f,1.68).
pessoa(bia,f,1.75).
pessoa(ivo,m,1.73).
pessoa(raí,m,1.57).

% Regras
casal(H, M) :- pessoa(_, H, Z), pessoa(_, M, W),  Z > W.
todosCasais :- casal(H, M), write([H, M]), fail.

% Query

?- forall(casal(H, M),writeln([H, M])).
% ?- todosCasais