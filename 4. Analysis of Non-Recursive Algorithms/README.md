# Analysis of Non-Recursive Algorithms

## Summations basics

$\sum_{i=m}^{n} i$

$\sum_{i=1}^{5} i$ = 1+2+3+4+5 = 15

the number of terms in the sum is n-m+1 = 5-1+1 = 5

### Definitions

$\sum_{i=m}^{n} g(i)$

1. The function g(i) is called the summand
2. The variable i is called summation index
3. The variable m is called lower bound of summation
4. The variable n is called upper bound of summation

### Analysing the summation

S = $\sum_{i=1}^{7} (3i + 2)$

S = 3(1)+2 + 3(2) + 2 + 3(3) + 2 + 3(4) + 2 + 3(5) + 2 + 3(6) + 2 + 3(7) + 2

= 3(1+2+3+4+5+6+7) + 2(7)

= 3(28) + 14

= 84 + 14

= 98

### Properties

1. $\sum_{i=m}^{n} c = c(n-m+1)$

2. $\sum_{i=m}^{n} (c.g(i)) = c.\sum_{i=m}^{n} g(i)$

3. $\sum_{i=m}^{n} (g(i)+h(i)) = \sum_{i=m}^{n} g(i) + \sum_{i=m}^{n} h(i)$

4. $\sum_{i=m}^{n} (g(i)-h(i)) = \sum_{i=m}^{n} g(i) - \sum_{i=m}^{n} h(i)$

We can split the sum into two parts by splitting the range of summation into two parts

$\sum_{i=m}^{n} g(i) = \sum_{i=m}^{k} g(i) + \sum_{i=k+1}^{n} g(i)$

where k is a number between m and n

### Arithmetic Series

$\sum_{i=1}^{n} i = 1+2+3+4+5+...+n = \frac{n(n+1)}{2}$

### Some useful summations

1. $\sum_{i=1}^{n} 1 = n$
2. $\sum_{i=1}^{n} i = \frac{n(n+1)}{2} ≈ \frac{1}{2}n^2$
3. $\sum_{i=1}^{n} i^2 = \frac{n(n+1)(2n+1)}{6} ≈ \frac{1}{3}n^3$
4. $\sum_{i=1}^{n} i^k ≈ \frac{1}{k+1}n^{k+1}$
5. $\sum_{i=1}^{n} a^i = \frac {a^{n+1}-1}{a-1}$

## Analysis of Loops

1. Define a parameter indicating an input’s size (n)
2. Identify the basic operation
3. Does C(n) depends only on **n** or it also depend on type of input
4. Setup sum expressing the number of times basic operation is executed
5. Find closed form for the sum or at least establish it’s order of growth

T(n) = C<sub>op</sub> \* C(n)

C<sub>op</sub> = Execution time of basic operation

C(n) = Number of times basic operation is executed for input size n

For loop starting from 0 to n-1, C(n) = $\sum_{i=1}^{n-1} 1$ = n-1-1+1 = n-1 = Θ(n)

```

x = 0
for i = 1 to n do
x = x + 1 // Takes C time
end for

```

T(n) = $\sum_{i=1}^{n} C$ = nC = Θ(n)

## Nested Loops

```

for i = 1 to n do
    for j = 1 to n do
        x = x + 1
    end for
end for

```

T(n) = $\sum_{i=1}^{n} \sum_{j=1}^{n} C$ = n\*n\*C = $n^2C$ = Θ(n<sup>2</sup>)

## While Loops

```

i = 1
while i <= n do
    x = x + 1
    i = i + 1
end while

```

In this case, we can't directly calculate the number of times the basic operation is executed so we see number of iterations and the value of i.

Iteration 0: i = 1
Iteration 1: i = 2
Iteration 2: i = 4
Iteration 3: i = 8
Iteration 4: i = 16
Iteration k: i = $2^k$

loop terminates when $2^k = n$
k = log<sub>2</sub>n
T(n) = C\*log<sub>2</sub>n = Θ(log<sub>2</sub>n)

## Sequence

t<sub>A</sub>+t<sub>B</sub> = max(t<sub>A</sub>, t<sub>B</sub>)

if t<sub>A</sub> = Θ(n) and t<sub>B</sub> = Θ(n<sup>2</sup>) then t<sub>A</sub>+t<sub>B</sub> = Θ(max(n, n<sup>2</sup>)) = Θ(n<sup>2</sup>)

## if then else

t<sub>A</sub>/ t<sub>B</sub> = max(t<sub>A</sub>, t<sub>B</sub>)
