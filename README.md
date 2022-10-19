# pushswap
pushswap_project_42

## Description

The project suggests to implemet a sorting algirithm that can do sorting using certaint types of operations.
We sort stack data structure so there are available operations:

sa (swap a): Swap the first 2 elements at the top of stack a.

sb (swap b): Swap the first 2 elements at the top of stack b.

ss : sa and sb at the same time.

pa (push a): Take the first element at the top of b and put it at the top of a.

pb (push b): Take the first element at the top of a and put it at the top of b.

ra (rotate a): Shift up all elements of stack a by 1. The first element becomes the last one.

rb (rotate b): Shift up all elements of stack b by 1. The first element becomes the last one.

rr : ra and rb at the same time.

rra (reverse rotate a): Shift down all elements of stack a by 1. The last element becomes the first one.

rrb (reverse rotate b): Shift down all elements of stack b by 1. The last element becomes the first one.

rrr : rra and rrb at the same time.

It is required to sort any amount of integers using as minimum as possible of these operations.
Program takes as parameters integers that will be sorted and print to stdout names of needed operations as steps to make this stack sorted.

## Compilation

Makefile will compile binary using ```make``` command.
There is ```make bonus``` rule to create checker that take as paremeters the same integers as push_swap got and does the same operations that it read from stdin.
So it is needed redirect stdout of push_swap to stdin of checker using pipe ("|").

## Implementation

As push_swap is started it creates forward list to contain these integers.
First mediana of stack is calculated and next if integer is less than the mediana it pushed to the second stack.
While stack A is not sorted we will do this step as a cycle and then we will have gotten partly sorted stack B. Then we can return them back and sort stack A doing swaps and rotates of A stack.
If amount of inegers is large enough the proccess of calculetion medianas and pushing to another stack in cycle can be repeated in stack B to optimize overall amount of operations.
