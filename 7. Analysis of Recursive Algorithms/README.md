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
T(n) = 2c + T(n-2)

T(n) = kc + T(n-k), when k>=1;
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

### Master Theorem on Decreasing Functions

```
T(n) = aT(n-b) + f(n)

where a is the number of recursive calls, b is the factor by which the input size is reduced, and f(n) is the cost of the non-recursive work.

```

### Case 1

If a < 1 -> T(n) = θ(f(n))

### Case 2

If a = 1 -> T(n) = θ(nf(n))

Example:

T(n) = T(n-1) + 1 = θ(n)

T(n) = T(n-1) + n = θ(n<sup>2</sup>)

T(n) = T(n-1) + log n = θ(n log n)

We can observe that if a = 1
then T(n) = θ(n \* f(n))

### Case 3

If a > 1 -> T(n) = θ(a<sup>n/b</sup> \* f(n))

T(n) = 2T(n-1) + 1 = θ(2<sup>n</sup>)

T(n) = 3T(n-1) + 1 = θ(3<sup>n</sup>)

T(n) = 2T(n-1) + n = θ(n2<sup>n</sup>)

### Summary

1. If a < b<sup>d</sup> -> T(n) = θ(n<sup>d</sup>)
2. If a = b<sup>d</sup> -> T(n) = θ(n<sup>d</sup> log n)
3. If a > b<sup>d</sup> -> T(n) = θ(n<sup>log<sub>b</sub>a</sup>)

### Master Theorem on Dividing Functions

```
T(n) = aT(n/b) + f(n)
```

### Case 1

If log<sub>b</sub>a < k -> T(n) = θ(n<sup>k</sup>)

if f(n) = O(n<sup>k</sup>) where k >= 0 -> T(n) = θ(n<sup>k</sup>)

if f(n) = O(n<sup>k</sup> log<sup>p</sup> n) where k >= 0 and p >= 0 -> T(n) = θ(n<sup>k</sup> log<sup>p</sup> n) else T(n) = θ(n<sup>k</sup>)

### Case 2

If log<sub>b</sub>a = k -> T(n) = θ(n<sup>k</sup> log n)

If f(n) = O(n<sup>k</sup> log<sup>p</sup> n) where

p > -1 -> T(n) = θ(n<sup>k</sup> log<sup>p+1</sup> n)

p = -1 -> T(n) = θ(n<sup>k</sup> log log n)

p < -1 -> T(n) = θ(n<sup>k</sup>)

### Case 3

If log<sub>b</sub>a > k -> T(n) = θ(n<sup>log<sub>b</sub>a</sup>)

### Summary

1. If log<sub>b</sub>a < k -> T(n) = θ(n<sup>k</sup>)
2. If log<sub>b</sub>a = k -> T(n) = θ(n<sup>k</sup> log n)
3. If log<sub>b</sub>a > k -> T(n) = θ(n<sup>log<sub>b</sub>a</sup>)

### Examples

1. T(n) = 2T(n/2) + 1

a = 2, b = 2, f(n) = O(1)

log<sub>2</sub>2 = 1

f(n) = θ(1) = θ(n<sup>0</sup>)
k = 0

log<sub>2</sub>2 = 1 > 0 // Case 1

T(n) = θ(n<sup>log<sub>b</sub>a</sup>) = θ(n)

2. T(n) = 4T(n/2) + n

a = 4, b = 2, f(n) = O(n)

log<sub>2</sub>4 = 2

f(n) = θ(n) = θ(n<sup>1</sup>)
k = 1

log<sub>2</sub>4 = 2 > 1 // Case 1

T(n) = θ(n<sup>log<sub>b</sub>a</sup>) = θ(n<sup>2</sup>)

3. T(n) = 2T(n/2) + n

a = 2, b = 2, f(n) = O(n)

log<sub>2</sub>2 = 1

f(n) = θ(n) = θ(n<sup>1</sup>)
k = 1

log<sub>2</sub>2 = 1 = 1 // Case 2

T(n) = θ(n<sup>k</sup> log n) = θ(n log n)

4. T(n) = 2T(n/2) + n<sup>2</sup>

a = 2, b = 2, f(n) = O(n<sup>2</sup>)

log<sub>2</sub>2 = 1

f(n) = θ(n<sup>2</sup>)
k = 2

log<sub>2</sub>2 = 1 < 2 // Case 3

T(n) = θ(n<sup>k</sup>) = θ(n<sup>2</sup>)
