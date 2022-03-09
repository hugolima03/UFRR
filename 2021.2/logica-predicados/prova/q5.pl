% Aluno: Hugo Lima Romão
% Avaliação 2 - DCC511
% Questão 5

% Comando para executar: swipl -s q5.pl

% Fatos
% partidas(Voo, Destino, HoraPrevista, HoraReal) 
partidas('TP123', 'Lisboa', 14.5, 14.5).
partidas('NI234', 'Manchester', 15.42, 16.0).
partidas('TP876', 'Faro', 14.3, 14.5).
partidas('NI498', 'Madrid', 15.0, 15.0).

% chegadas(Voo, Origem, HoraPrevista, HoraReal)

chegadas('TP123', 'Lisboa', 14.0, 14.58).
chegadas('NI533', 'Funchal', 15.0, 15.0).
chegadas('TP877', 'Santiago', 14.5, 15.0).
chegadas('NI498', 'Manchester', 16.0, 15.83).

parteAHoras(A) :- partidas(A, _, C, D), C == D.

vaivém(V) :- partidas(V, D, _, _), chegadas(V, E, _, _), D == E.

ligação(A, B) :- partidas(_, B, _, _), chegadas(_, A, _, _), A \== B.

chegaAtrasado(V) :- chegadas(V, _, A, H), H > A.

emConflito(V) :- partidas(V, _, A, H), chegadas(V, _, A, H), A < H.