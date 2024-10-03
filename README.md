# push_swap
![gif](https://github.com/retakashi/push_swap/blob/main/images/push_swap_visual.gif)

## Overview
An algorithm that sorts using two stacks with the minimum number of operations possible.

## Requirement
macOS
## Usage
``` bash
git clone ...
cd push_swap
make
./push_swap <array of integer numbers>
```
![gif](https://github.com/retakashi/push_swap/blob/main/images/push_swap.gif)

If you want to check if it is sorted correctly↓
![gif](https://github.com/retakashi/push_swap/blob/main/images/push_swap_checker.gif)

### How to interpret the results
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

## Reference
[push-swap-pain](https://github.com/kaaaaakun/push-swap-pain)

[push_swap_tester](https://github.com/nafuka11/push_swap_tester)

[42 Push Swap - 100 & 500 numbers high score :)](https://www.youtube.com/watch?v=2aMrmWOgLvU)

