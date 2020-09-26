# Task selection problem

This problem consists of how to select, from a set of tasks, which ones should be done to maximize some value (in this case, it will be how to maximize the amount of money won).

## Input

The input consists of three lines.

- The first is `N` the number os tasks.
- The second is a row with `N` integers representing each task's deadline (must be scheduled to a slot BEFORE the deadline).
- The third is a row with `N` floats representing each task's worth (how much money you receive from completing them).

Dates start at 1.

None of the rows need to be sorted (as the solution will sort it).

## Solution

The solution is pretty simple. It is a greedy algorithm where you select the worthiest task (the one which grants the most money) and schedule it as close as possible from the deadline. If the deadline "date" is already occupied, you try to select the previous date, and so on. If no dates are available for this task, just ignore it.

## Example

```
Input:
5
1 5 3 3 2
1 9 3 2 7

Output:
21
```

The solution is to choose the tasks that are worth 9, 7, 3, and 2. The task with value 1 then cannot be selected, and that's it. Time slot 4 is empty because there is no task to be scheduled at that time.

```
Tasks selected for each time slot:
Time:  1 2 3 4 5
Value: 2 7 3   9
```
