# Analysis of Recursive Algorithms

## Iteration Method

The basic idea is to expand the recurrence and express it as a summation of terms dependent only on n and the initial conditions.

### Example

T(n) = T(n-1) +1 , and T(1) = θ(1).

```

T(n) = T(n-1) + 1
     = T(n-2) + 1 + 1
     = T(n-3) + 1 + 1 + 1
     = T(n-4) + 1 + 1 + 1 + 1
     = T(n-k) + k
```

when n-k = 1, k = n-1.

T(n) = T(n-1) + 1.
T(n) = T(n-k) + k.
T(n) = T(1) + (n-1) = θ(n).

## The Recursion-Tree Method

In this method, we draw a recursion tree and see how many branches are there at each level of the tree. We sum the work done at each level of the tree to obtain a time function.

```
        Cn
    /    |    \
C(n/3)  c(n/3)  c(n/3)
```

T(n) = 3<sup>h</sup>\*T(1) + $\sum_{i=0}^{h-1} cn$

T(n) = 3<sup>h</sup>\*T(1) + cn\*(h-1-0+1)

T(n) = 3<sup>h</sup>\*T(1) + cn\*h

3<sup>h</sup> = n

h = log<sub>3</sub>n

T(n) = 3<sup>log<sub>3</sub>n</sup>\*T(1) + cn\*log<sub>3</sub>n

T(n) = n\*T(1) + cn\*log<sub>3</sub>n

T(n) = θ(n) + θ(nlog<sub>3</sub>n)

T(n) = θ(nlog<sub>3</sub>n)

## The Master Method

The master method provides a "cookbook" method for solving recurrences of the form:

T(n) = aT(n/b) + f(n)

= aT(n/b) + n<sup>d</sup>.

b > 1, a ≥ 1

We commonly use the master method to solve divide-and-conquer recurrences.

a = number of subproblems in the recursion
b = size of each subproblem

### Case 1

f(n) <= N<sup>log<sub>b</sup>(a)</sup>

If N<sup>log<sub>b</sup>(a)</sup> is greater than n<sup>d</sup>, then the solution is θ(n<sup>log<sub>b</sup>(a)</sup>)

### Case 2

If N<sup>log<sub>b</sup>(a)</sup> is less than n<sup>d</sup>, then the solution is θ(n<sup>d</sup>).

### Case 3

If N<sup>log<sub>b</sup>(a)</sup> is equal to n<sup>d</sup>, then the solution is θ(n<sup>d</sup>log<sub>b</sub>n).

### Example

T(n) = 4T(n/2) + n

a = 4, b = 2, d = 1

n<sup>log<sub>b</sub>a</sup> = n<sup>log<sub>2</sub>4</sup> = n<sup>2</sup>

n<sup>d</sup> = n<sup>1</sup> = n

n<sup>log<sub>2</sub>4</sup> is greater than n<sup>1</sup>, so the solution is θ(n<sup>2</sup>).
