-module(main).
-export([ main/0 ]).


% Main function
main() ->
    FileName = "ks_1000.dat",
    NbEvals = [ 10, 100, 500, 1000 ],
    NbRun = 100,
    FileNameOut = "rs.csv",

    { N, Profits, Weights, C } = ks:read_file_ks(FileName),
    Eval = ks:knapsackEval({ N, Profits, Weights, C }),
    
    {ok, Device} = file:open(FileNameOut, [write]),
    io:fwrite(Device, "nbEval fitness~n", [ ]),

    lists:map( fun(NbEval) -> % cette fun permet d'appliquer sur tous les elements de NbEvals
		       lists:foreach( fun(X) -> io:fwrite(Device, "~w ~w~n", [ NbEval, X ]) end, % cette fun ecrit le resultat
				      lists:map(fun(_) -> % cette fun retourne la valeur finale d'une random search
							{ solution, Value, _ } = ks:randomSearch(Eval, N, NbEval), 
							Value 
						end, 
						lists:seq(1, NbRun))) % seq donne une liste "fictive" de taille NbRun
	       end,
	       NbEvals),

    file:close(Device).
    

