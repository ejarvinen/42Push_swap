# 42Push_swap

A program implementing bucket sort type sorting algorithm to sort a stack with a limited set of instructions and the smallest number of moves using two stacks (A and B). In the beginning, stack A contains unsorted input given to the program and stack B is empty. In the end, stack A will contain the sorted input starting from the smallest number. Stack B will empty in the end. 

The program is optimized for stack sizes equal to and smaller than 500 numbers. Accepted input values should be of type `integer` and belong in the range of `INT_MAX` and `INT_MIN`.

## How to run
_This project has been developed in macOS._
`git clone` to desired directory. `cd` into that directory. Run `git submodule init` and `git submodule update` in the same directory and then `make`. Example use of the `./push_swap` executable:
```
./push_swap 2 4 3 1 5
```
The program will print each action taken during sorting to the terminal as follows:
- `sa (swap a)`: Swap the first 2 numbers at the top of stack A. Does nothing if there's only one or zero numbers to swap.
- `sb (swap b)`: Swap the first 2 numbers at the top of stack B. Does nothing if there's only one or zero numbers to swap.
- `ss`: Does `sa` and `sb` at the same time.
- `pa (push a)`: Takes the first number at the top of B and puts it at the top of A. Does nothing if B is empty.
- `pb (pusb b)`: Takes the first number at the top of A and puts it at the top of B. Does nothing if A is empty.
- `ra (rotate a)`: Shifts up all numbers of stack A by 1. The first number becomes the last one.
- `rb (rotate b)`: Shifts up all numbers of stack B by 1. The first number becomes the last one.
- `rr`: Does `ra` and `rb` at the same time.
- `rra (reverse rotate a)`: Shifts down all numbers of stack A by 1. The last number becomes the first one.
- `rrb (reverse rotate b)`: Shifts down all numbers of stack B by 1. The last number becomes the first one.
- `rrr`: Does `rra` and `rrb` at the same time.
