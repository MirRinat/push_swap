# Push_swap
The Push_swap project is a very simple and highly effective algorithm project: data will need to be sorted. 

• The game is composed of 2 stacks named a and b. 

• To start with:

    ◦ a contains a random number of either positive or negative numbers without any duplicates.
    ◦ b is empty
  
• The goal is to sort in ascending order numbers into stack a.

• To do this you have the following operations at your disposal:

    sa : swap a - swap the first 2 elements at the top of stack a. Do nothing if there is only one or no elements).

    sb : swap b - swap the first 2 elements at the top of stack b. Do nothing if there is only one or no elements).

    ss : sa and sb at the same time.

    pa : push a - take the first element at the top of b and put it at the top of a. Do nothing if b is empty.

    pb : push b - take the first element at the top of a and put it at the top of b. Do nothing if a is empty.

    ra : rotate a - shift up all elements of stack a by 1. The first element becomes the last one.

    rb : rotate b - shift up all elements of stack b by 1. The first element becomes the last one.

    rr : ra and rb at the same time.

    rra : reverse rotate a - shift down all elements of stack a by 1. The last element becomes the first one.

    rrb : reverse rotate b - shift down all elements of stack b by 1. The last element becomes the first one.

    rrr : rra and rrb at the same time.


# How to start and sort

git clone https://github.com/MirRinat/push_swap.git

cd push_swap

make

./push_swap --help

    ./push_swap (unsorted stack)    Sort stack
    ./checker (unsorted stack)      Check commands
    -v              Print stacks after command
    --clear         Clear window before sorting stacks
    -c              View what command are doing(for checker)

For example:

./push_swap 5 1 4 2 3

    ra
    pb
    ra
    pb
    rra
    sa
    pa
    pa

ARG="1 5 2 4 3"; ./push_swap $ARG | ./checker -c $ARG

    Command
    stack A: [ 1 | 5 | 2 | 4 | 3 ]

    stack B: [ ]

    Command pb

    stack A: [ 5 | 2 | 4 | 3 ]

    stack B: [ 1 ]

    Command ra

    stack A: [ 2 | 4 | 3 | 5 ]

    stack B: [ 1 ]

    Command pb

    stack A: [ 4 | 3 | 5 ]

    stack B: [ 2 | 1 ]

    Command sa

    stack A: [ 3 | 4 | 5 ]

    stack B: [ 2 | 1 ]

    Command pa

    stack A: [ 2 | 3 | 4 | 5 ]

    stack B: [ 1 ]

    Command pa

    stack A: [ 1 | 2 | 3 | 4 | 5 ]

    stack B: [ ]

    OK
