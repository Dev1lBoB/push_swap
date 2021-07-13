# push_swap
The goal of this project was to make a sorter of a stack of ints.
Push_swap recieves the stack as an list of arguments to the program.

In this subject there was given 11 functions which I should use to sort the stack using 1 extra stack.
Fuctions:
> sa : swap a - swap the first 2 elements at the top of stack a. Do nothing if there is only one or no elements).
> sb : swap b - swap the first 2 elements at the top of stack b. Do nothing if there is only one or no elements).
> ss : sa and sb at the same time.
> pa : push a - take the first element at the top of b and put it at the top of a. Do nothing if b is empty.
> pb : push b - take the first element at the top of a and put it at the top of b. Do nothing if a is empty.
> ra : rotate a - shift up all elements of stack a by 1. The first element becomes the last one.
> rb : rotate b - shift up all elements of stack b by 1. The first element becomes the last one.
> rr : ra and rb at the same time.
> rra : reverse rotate a - shift down all elements of stack a by 1. The last element becomes the first one.
> rrb : reverse rotate b - shift down all elements of stack b by 1. The last element becomes the first one.
> rrr : rra and rrb at the same time.

The program should write in stdout all the commands it uses to sort the stack.
The goal is to sort the stack with the minimum possible number of operations.

The other part of the project was to write a program named checker.
It also takes the stack as an list of arguments to the program.
Then it recieves list of instructions from the stdin line by line and executes it in the given stack.
After recieving EOF it stops and then displays "OK" if the stack A is sorted and stack B is empty.
Otherwise it displays "KO".

Bonus part of this project was to make a visualisation of the sorting process.
I 
