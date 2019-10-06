-module(mergesort).
-export([merge_sort/1]).

merge_sort(UnsortedList) when length(UnsortedList) =< 1 -> UnsortedList;
merge_sort(UnsortedList) ->
    Half = length(UnsortedList) div 2,
    {Left, Right} = lists:split(Half, UnsortedList),
    lists:merge(merge_sort(Left), merge_sort(Right)).
