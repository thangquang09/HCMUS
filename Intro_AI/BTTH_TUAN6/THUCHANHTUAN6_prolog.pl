parent(marry, bill).
parent(tom, bill).
parent(tom, liz).
parent(bill, ann).
parent(bill, sue).
parent(sue, jim).

woman(marry).
man(tom).
man(bill).
woman(liz).
woman(sue).
woman(ann).
man(jim).

child(Y, X) :- parent(X, Y).
mother(X, Y) :- parent(Y, X), woman(X).
grandparent(X, Z) :- parent(X, Y), parent(Y, Z).
sister(X, Y) :- parent(Z, X), parent(Z, Y), woman(X).