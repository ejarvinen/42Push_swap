# 42Push_swap
## Description
**Push_swap** is an algorithmic project designed to sort a stack of integers using a limited set of operations. The goal is to sort the numbers in ascending order with the minimum number of moves. This project has enhanced my understanding of sorting algorithms and their complexities. My implementation utilizes [bucket sort](https://en.wikipedia.org/wiki/Bucket_sort) to sort the two stacks and it's optimized for stack sizes <= 500.

## Features
- Sorting using two stacks (`a` and `b`).
- Efficiently finding the shortest sequence of operations.
- Various operations including swap, push, rotate, and reverse rotate.

## Available Operations
- `sa`, `sb`, `ss`: Swap the top two elements.
- `pa`, `pb`: Push from one stack to another.
- `ra`, `rb`, `rr`: Rotate stack (first becomes last).
- `rra`, `rrb`, `rrr`: Reverse rotate stack (last becomes first).

## Installation
1. Clone the repository:
```
git clone https://github.com/ejarvinen/42Push_swap.git
cd 42Push_swap
```
2. Update and initialize submodules:
```
git submodule init
git submodule update
```
3. Build the project using the Makefile:
```
make
```
## Usage
To use `push_swap`, run the following command with a set of integers:
```
./push_swap 4 67 3 87 23
```
