% Small word or Clause replacement.
change(eats,[is,eating]).                      
change(cooks,[is,cooking]).
change(jumps,[is,falling]). 
change(cook,[were,cooking]).
change(eat,[were,eating]).
change(ram,prince).
change(shyam,king).
change(he,prince).
change(seeta,princess).
change(geeta,princess).
change(she,princess).
change(banana,[banana,cake]).
change(apple,[apple,pie]).
change(lasagna,[a,dish]).
change(meat,[delicious,food]).
change(cat,ms_india).
change(dog,mr_india).
change(we,they).
change(they,we).
change(children,kittens).
change(play,[were,crying]).
change(plays,[was,crying]).


% Grammar rules 

ss --> art, n, v, art, n | n,v.			%% sentence

n-->bname|gname|anim|plu|obj1|obj2|obj3. %% nouns

art-->[a]|[an]|[the]|[].			%% articles

bname --> [ram]|[shyam]|[he].           %% boy names/pronoun     
gname-->[seeta]|[geeta]|[she].		%% girl names/pronoun

anim-->[dog]|[cat].			%% animals

plu-->[they]|[we]|[children].		%% plurals

obj1 --> [apple]|[banana].		%% objects(nouns)
obj2--> [lasagna].
obj3-->[meat].

v-->v1|v2|v3|v4.			%% verbs

v1-->[eats]|[eat].
v2-->[cooks]|[cook].
v3-->[jumps].
v4-->[play]|[plays].

% Following are the rules to recursively check and create new messages with replacements

% Checking the grammar first.
change([H|T],[]):-not(ss([H|T],[])),write("Grammar incorrect").

change([H|T],[]):-ss([H|T],[]),ct([H|T],[]).

ct([],[]).
ct([H|T],[]):- phrase(art,[H]),tab(1),write(H),tab(1),ct(T,[]);                         % articles and plurals aren't replaced
               phrase(plu,[H]),change(H,X),tab(1),write(X),tab(1),ct(T,[]).


ct([H|T],[]):- phrase(v1,[H]),change(H,[X,Y]),tab(1),write(X),tab(1),write(Y),tab(1),ct(T,[]);          % verb changes
phrase(v2,[H]),change(H,[X,Y]),tab(1),write(X),tab(1),write(Y),tab(1),ct(T,[]);
phrase(v3,[H]),change(H,[X,Y]),tab(1),write(X),tab(1),write(Y),tab(1),ct(T,[]);
phrase(v4,[H]),change(H,[X,Y]),tab(1),write(X),tab(1),write(Y),tab(1),ct(T,[]).

ct([H|T],[]):- phrase(bname,[H]),change(H,Y),write(Y), ct(T,[]);		% noun changes
phrase(gname,[H]),change(H,Y),write(Y), ct(T,[]);
phrase(anim,[H]),change(H,Y),write(Y), ct(T,[]);
phrase(anim,[H]),change(H,Y),write(Y), ct(T,[]);
phrase(obj1,[H]),change(H,(X,Y)),write(X),tab(1),write(Y),ct(T,[]);
phrase(obj1,[H]),change(H,[X,Y]),write(X),tab(1),write(Y),ct(T,[]);
phrase(obj2,[H]),change(H,[X,Y]),write(X),tab(1),write(Y),ct(T,[]);
phrase(obj3,[H]),change(H,[X,Y]),write(X),tab(1),write(Y),ct(T,[]).

