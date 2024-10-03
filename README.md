# push_swap

## Overview
An algorithm that sorts using two stacks with the minimum number of operations possible.

## Requirement
macOS
## Usage
``` bash
git clone ...
cd push_swap
make
./push_swap <array of positive numbers>
```
![gif](https://github.com/retakashi/push_swap/blob/main/push_swap.gif)

### results
 - sa(swap a): Swap the first 2 elements at the top of stack a.
    Do nothing if there is only one or no elements.
 - sb(swap b): Swap the first 2 elements at the top of stack b.
    Do nothing if there is only one or no elements.
 - ss : sa and sb at the same time.
 - pa(push a): Take the first element at the top of b and put it at the top of a.
    Do nothing if b is empty.
 - pb(push b): Take the first element at the top of a and put it at the top of b.
    Do nothing if a is empty.
 - ra(rotate a): Shift up all elements of stack a by 1.
    The first element becomes the last one.
 - rb(rotate b): Shift up all elements of stack b by 1.
    The first element becomes the last one.
 - rr : ra and rb at the same time.
 - rra(reverse rotate a): Shift down all elements of stack a by 1.
    The last element becomes the first one.
 - rrb(reverse rotate b): Shift down all elements of stack b by 1.
    The last element becomes the first one.
 - rrr : rra and rrb at the same time.
