grass_eater(goat).

fierce_animal(wolf).

meat_eater(X) :- fierce_animal(X).

eat(X, meat) :- meat_eater(X).
eat(X, grass) :- grass_eater(X).

eat(X, Y) :- meat_eater(X), grass_eater(Y).

drink(X, water) :- meat_eater(X).
drink(X, water) :- grass_eater(X).

consume(X, Y) :- eat(X, Y).
consume(X, Y) :- drink(X, Y).