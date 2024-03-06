# Recursion

## What is Recursion?

Recursion is a method where the solution to a problem depends on solutions to sub-problems of the same problem.

## How does Recursion work?

A recursive function calls itself, with a modified input, and continues to do so until it reaches a base case. The base case is the condition that stops the recursion.

Example:

We want to calculate the factorial of a number. The factorial of a number is the product of all positive integers less than or equal to the number. For example, the factorial of 5 is 5 x 4 x 3 x 2 x 1 = 120.

5! = 5 x 4 x 3 x 2 x 1 = 120

4! = 4 x 3 x 2 x 1 = 24

5! = 5 x 4!

n! = n x (n-1)!

big problem: n!
the sub-problem: (n-1)!

## How to write a recursive function?

The recursive function has two parts:

-   Base case: The condition that stops the recursion.
-   Recursive case: The condition that calls the function itself.

## How to represent Recursion?

Recursion can be represented using a decision tree. The decision tree shows the different paths the recursive function takes to reach the base case.

## One branch recursion

One branch recursion is when the recursive function calls itself only once.

Example:

Our factorial example is a one branch recursion. The recursive function calls itself only once.

![Factorial_Decision_Tree](https://github.com/Ahmed-M-Aboutaleb/Algorithms/blob/main/6.%20Recursion/images/factorial_recursion_tree.png?raw=true)

It's better to use the iterative approach instead of recursion in one branch recursion because it's more efficient in space complexity.

```cpp
int factorial(int n) {
    if (n <= 1) {
        return 1; // base case (0! = 1! = 1)
    }
    return n * factorial(n - 1); // recursive case (n! = n * (n-1)!)
}
```

Complexity:

-   Time: O(n)
-   Space: O(n)

## Two branches recursion

Two branches recursion is when the recursive function calls itself twice.

Example:

The Fibonacci sequence is a two branches recursion. The recursive function calls itself twice.

The Fibonacci sequence is a series of numbers in which each number is the sum of the two preceding ones, usually starting with 0 and 1.

0, 1, 1, 2, 3, 5, 8, 13, 21, 34, ...

F(n) = F(n-1) + F(n-2)
F(0) = 0
F(1) = 1
F(2) = F(1) + F(0) = 1 + 0 = 1

![Fib_Decision_Tree](https://github.com/Ahmed-M-Aboutaleb/Algorithms/blob/main/6.%20Recursion/images/fibtree.png?raw=true)

```cpp
int fibonacci(int n) {
    if (n <= 1) {
        return n; // base case (fib(0) = 0, fib(1) = 1)
    }
    return fibonacci(n - 1) + fibonacci(n - 2); // recursive case (fib(n) = fib(n-1) + fib(n-2))
}
```

Complexity:

-   Time: O(2^n)
-   Space: O(n)
