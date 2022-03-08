% Aluno: Hugo Lima Romão
% Avaliação 2 - DCC511
% Questão 1

% Comando para executar: swipl -s q1.pl

% Fatos
entrada(pao).
entrada(salada).
prato(carne).
prato(peixe).
prato(massa).
sobremesa(fruta).
sobremesa(pudim).
sobremesa(sorvete).

% Regras
menu(Entrada, Prato, Sobremesa) :- entrada(Entrada), prato(Prato), sobremesa(Sobremesa).

% Query para listas todas as combinações de Menu
% O predicado forall é fornecido pelo prolog e obedece a seguinte regra:
% forall(member(R), Action).
?- forall(menu(Entrada, Prato, Sobremesa),writeln([Entrada, Prato, Sobremesa])).