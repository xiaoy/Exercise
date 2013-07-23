-module(bool).
-export([b_not/1]).
-export([b_and/2]).
-export([b_or/2]).
-export([b_nand/2]).

b_not(A) ->
    A /= true.
b_and(A, B) ->
    S = (A == B),
    S == true.
b_or(A, B) ->
    A /= B.
b_nand(A, B) ->
    R = b_and(A, B),
    b_not(R).
