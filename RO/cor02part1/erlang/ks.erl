-module(ks).
-export([ main/0, knapsackEval/1, rndSol/1, randomSearch/3, print/1, read_file_ks/1 ]).

% sub-function to define knapsackEval
somme(_,_,[]) ->
    { 0, 0 };
somme([Pr | TPr] , [Po | TPo], [ B | TB ]) ->
    { Spr, Spo } = somme(TPr, TPo, TB),
    case B == 0 of
	true -> { Spr, Spo };
	false -> { Pr + Spr, Po + Spo }
    end.

% sub-function to define knapsackEval
calculBeta([], []) ->
    0;
calculBeta([Pr | TPr] , [Po | TPo]) ->
    max(Pr / Po, calculBeta(TPr, TPo)).
  
% Produce the evaluation function of the knapsack problem
knapsackEval({ _, Profits, Poids, C }) -> 
    Beta = calculBeta(Profits, Poids),
    fun({solution, _, Bits}) ->
	    { Sprofits, Spoids } = somme(Profits, Poids, Bits),
	    case Spoids < C of
		true -> {solution, Sprofits, Bits};
		false -> {solution, Sprofits - Beta * (Spoids - C), Bits}
	    end
    end.

% Produce a random solution
rndSol(N) ->
    { solution, 0, lists:map(fun(_) -> random:uniform(2) - 1 end, lists:seq(1,N)) }.

% sub-function which returns the maximum between 2 solutions
maxSol({solution, V1, _}, {solution, V2, Bits2}) when V1 < V2 ->
    { solution, V2, Bits2 };
maxSol({solution, V1, Bits1}, {solution, V2, _}) when V1 >= V2 ->
    { solution, V1, Bits1 }.

% Random search
randomSearch(Eval, N, 1) ->
    Eval(rndSol(N));
randomSearch(Eval, N, NbEval) ->
    maxSol(randomSearch(Eval, N, NbEval - 1), Eval(rndSol(N))).
    
% Print a solution
print({solution, V, Bits}) ->
    io:format("~w ~w~n", [ V , Bits ]).

% read a file
read_file_ks(Filename) ->
    % open the file
    {ok, Device} = file:open(Filename, [read]),
    % first line : n
    {ok, Line1} = file:read_line(Device),
    { N, _ } = string:to_integer(Line1),
    % second line : profits
    {ok, Line2} = file:read_line(Device),
    Profits = lists:map(fun(X) -> {Int, _} = string:to_integer(X), Int end, string:tokens(Line2, " ")),
    % third line : weights
    {ok, Line3} = file:read_line(Device),
    Weights = lists:map(fun(X) -> {Int, _} = string:to_integer(X), Int end, string:tokens(Line3, " ")),
    % fourth line : Capacity
    {ok, Line4} = file:read_line(Device),
    { C, _ } = string:to_integer(Line4),
    % close file
    file:close(Device),
    % result
    { N, Profits, Weights, C }.


% Main function
main() ->
    N = 3,
    Profits = [ 10, 8, 9 ],
    Poids = [ 4, 5, 6 ],
    C = 10.5,
    Eval = knapsackEval({ N, Profits, Poids, C } ),
    S = { solution, 0, [ 1, 1 , 1 ] },
    print(Eval(S)),
    print(randomSearch(Eval, N, 100)),
    { N2, Profits2, Weights2, C2 } = read_file_ks("ks_5.dat"),
    Eval2 = knapsackEval({ N2, Profits2, Weights2, C2 }),
    print(randomSearch(Eval2, N2, 1000)),
    ok.
