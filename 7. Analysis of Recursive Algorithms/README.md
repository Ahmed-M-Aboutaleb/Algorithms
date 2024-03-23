# Analysis of Recursive Algorithms

## Introduction

In this section, we will learn how to analyze recursive algorithms. We will learn about the iteration method, the recursion-tree method, and the master method.

## Recurrence Relations

A recurrence relation is an equation that recursively defines a sequence. It is a way to define a function in terms of its value on smaller inputs.

### Example

T(n) = T(n-1) + 1, and T(1) = θ(1).

```

factorial(n) {
    if n == 0 then return 1;
    end if
    return n * factorial(n-1);
}
```

T(n) = c + T(n-1)

T(n) = cost of non-recursive work + cost of recursive work

```
T(n-1) = c + T(n-2)

replace T(n-1) in T(n)

T(n) = c + [ c + T(n-2) ]
T(n-1) = 2c + T(n-2)
T(n-2) = 3c + T(n-3)
T(n-k) = kc + T(n-k), when k>=1;
```

we know that T(0) = C;

so we choose k such that n-k = 0;

k = n;

```
T(n) = nC + T(0)
T(n) = nC + C
T(n) = (n+1)C
T(n) = θ(n)
```

and that's how we get the time complexity of the factorial function using substitution method.

## Iteration Method

The basic idea is to expand the recurrence and express it as a summation of terms dependent only on n and the initial conditions.

### Steps

1. Expand the recurrence relation.
2. Observe the pattern.
3. Guess the form of the solution.
4. Prove the guess by induction.

### Example

```

factorial(n) {
    if n == 0 then return 1;
    end if
    return n * factorial(n-1);
}
```

T(n) = c + T(n-1)

1. Expand the recurrence relation.

```
T(n) = c + T(n-1)
T(n) = c + [ c + T(n-2) ]
T(n) = 2c + T(n-2)
T(n) = 3c + T(n-3)
continue this process until we reach the base case.
```

2. Observe the pattern.

We can see that each term is increasing by a constant value of c and the recursive term T(n-k) where k is number of iterations.

3. Guess the form of the solution.

T(n) = kc + T(n-k)

4. Prove the guess by induction.

Base case: T(0) = c

```
n - k = 0
n = k
```

Inductive step: Assume T(k) = kc + T(0)

```
T(k+1) = c + T(k)
T(k+1) = c + kc + T(0)
T(k+1) = (k+1)c + T(0)
T(k+1) = (k+1)c
T(n) = nc
T(n) = θ(n)
```

## The Recursion-Tree Method

In this method, we draw a recursion tree and see how many branches are there at each level of the tree. We sum the work done at each level of the tree to obtain a time function.

We can use the recursion-tree method to solve recurrences of the form:

T(n) = aT(n/b) + Cn<sup>d</sup>

```
a = number of subproblems in the recursion
b = size of each subproblem
C = cost of the work done outside the recursive calls
d = exponent in the running time of the "combine" step
```

### Example

![tree_png](https://github.com/Ahmed-M-Aboutaleb/Algorithms/blob/main/7.%20Analysis%20of%20Recursive%20Algorithms/images/tree.png?raw=true)

Cost at each level:

Level 0: Cn

Level i: a<sup>i</sup>C(n/b<sup>i</sup>)

Number of leaves = a<sup>log<sub>b</sub>n</sup>

Total cost = Cn<sup>d</sup> + Cn<sup>d</sup>log<sub>b</sub>n

T(n) = a<sup>h</sup>T(1) + $\sum_{i=0}^{h-1} a^i C(n/b^i)$

$n/3^h = 1 -> 3^h = n -> h = log_3 n$

T(n) = 3<sup>log<sub>3</sub>n</sup>T(1) + $\sum_{i=0}^{h-1}cn$

T(n) = nT(1) + cn log<sub>3</sub>n

T(n) = θ(n log n)

## The Master Method

The master method provides a "cookbook" method for solving recurrences of the form:

T(n) = aT(n/b) + f(n)

where a >= 1, b > 1, and f(n) is an asymptotically positive function.

### Steps

1. Extract the values of a, b, and f(n).

2. Compare f(n) with n<sup>log<sub>b</sub>a</sup>.

3. Determine the case that applies.

### Case 1

Running time dominated by the cost at leaves.

f(n) = O(n<sup>log<sub>b</sub>a - ε</sup>),
Where ε > 0

T(n) = θ(n<sup>log<sub>b</sub>a</sup>)

If f(n) grows polynomially (by factor $n^ε$) slower than n<sup>log<sub>b</sub>a</sup> -> $\frac{n^{log_ba}} {f(n)}$, then the solution is:

T(n) = θ(n<sup>log<sub>b</sub>a</sup>)

### Example

T(n) = 9T(n/3) + n

Step 1: a = 9, b = 3, f(n) = n

Step 2:

n<sup>log<sub>b</sub>a</sup> = n<sup>log<sub>3</sub>9</sup> = n<sup>2</sup>

f(n) = n

Step 3:

n<sup>log<sub>b</sub>a</sup> > f(n) -> case 1

T(n) = θ(n<sup>log<sub>3</sub>9</sup>) = θ(n<sup>2</sup>)

### Case 2

Running time evenly distributed among all levels.

f(n) = θ(n<sup>log<sub>b</sub>a</sup> log<sup>k</sup>n)

T(n) = θ(n<sup>log<sub>b</sub>a</sup> log<sup>k+1</sup>n)

Another way to write this is:

f(n) = θ(n<sup>log<sub>b</sub>a</sup>)

T(n) = θ(n<sup>log<sub>b</sub>a</sup> log n)

### Example

T(n) = 2T(n/2) + θ(n)

Step 1: a = 2, b = 2, f(n) = n

Step 2:

n<sup>log<sub>b</sub>a</sup> = n<sup>log<sub>2</sub>2</sup> = n

f(n) = n

Step 3:

f(n) = θ(n) or n<sup>log<sub>b</sub>a</sup> = f(n) -> case 2

T(n) = θ(n log n)

### Case 3

Running time dominated by cost at root consequently, To solve this type of recurrence, we need only to characterize the dominating term.

f(n) = Ω(n<sup>log<sub>b</sub>a + ε</sup>),
Where ε > 0

T(n) = θ(f(n))

### Example

T(n) = 3T(n/4) + n log n

Step 1: a = 3, b = 4, f(n) = n log n

Step 2:

n<sup>log<sub>b</sub>a</sup> = n<sup>log<sub>4</sub>3</sup> = n<sup>log<sub>4</sub>4</sup> = n

f(n) = n log n

Step 3:

f(n) = Ω(n) or n<sup>log<sub>b</sub>a</sup> < f(n) -> case 3

T(n) = θ(n log n)

## Summary of the Master Method

1. If f(n) < n<sup>log<sub>b</sub>a</sup>, then T(n) = θ(n<sup>log<sub>b</sub>a</sup>).

2. If f(n) = n<sup>log<sub>b</sub>a</sup>, then T(n) = θ(n<sup>log<sub>b</sub>a</sup> logn).

3. If f(n) > n<sup>log<sub>b</sub>a</sup>, then T(n) = θ(f(n)).
