# Asymptotic Analysis

The study of the variations in the performance of the algorithm with the change in the order of the input size is called Asymptotic Analysis.

The main goal is to determine the cost of running an algorithm and how to reduce that cost.

## Asymptotic Notations

Asymptotic notations are mathematical notations to describe the running time of an algorithm when the input tends towards a particular value or a limiting value. In other words, it defines the mathematical limits of its run-time performance. Using the asymptotic analysis, we can easily conclude the average-case, best-case, and worst-case scenario of an algorithm.

### Big-O Notation

Big O notation (Big-Oh) is used to describe the upper bound of an algorithm. It is the formal way to express the upper bound of an algorithm's running time. It measures the worst-case scenario of an algorithm.

The proof of the Big O notation is given by the following formula:

```plaintext
f(n) ≤ c.g(n) where n ≥ n0

0 <= c < ∞
```

Where: c and n0 are constants and called witnesses.

Example: If f(n) = n<sup>2</sup>+2n+1, g(n) = n<sup>2</sup>.
Proof that f(n) = O(g(n)):

Answer:
to prove that f(n) = O(g(n)), we need to find the value of c and n0 such that f(n) ≤ c.g(n) where n ≥ n0.

```
f(n) ≤ c.g(n) where n ≥ n0

= n^2 + 2n + 1 ≤ c.n^2

= n>=1 (set n0 = 1)

n^2 >n

= n^2 > 1

= n^2 + 2n + 1 ≤ n^2 + 2n^2 + n^2

= n^2 + 2n + 1 ≤ 4n^2

c=4, n0=1
```

> In polynomial functions, We can get Big O notation by the dominant term of the function.

> The easiest way to prove Big O notation is to make every term of the function to be less than or equal to the dominant term of the function.

For example, if f(n) = 3n<sup>2</sup> + 2n + 1, then we can do

```plaintext
3n^2 + 2n + 1 ≤ 3n^2 + 2n^2 + n^2
3n^2 + 2n + 1 ≤ 6n^2
```

To <strong>disprove</strong> Big O notation, we can do the following:

1. Suppose that f(n) belongs to O(g(n))
2. Show that f(n) leads to a contradiction.

For example, if f(n) = 2n + 3 is Not O(1), then we can do

```plaintext
Suppose that f(n) belongs to O(1)
2n + 3 ≤ c.1
2n + 3 ≤ c
```

This is a contradiction because the left-hand side of the equation is not less than or equal to the right-hand side of the equation.

### Big-Ω Notation

Big-Ω (Big-Omega) notation symbolizes the lower bound of the running time of an algorithm. Thus, it provides the best-case complexity of an algorithm. It determines the fastest time that an algorithm can run.

The proof of the Big-Ω notation is given by the following formula:

```

f(n) ≥ c.g(n) where n ≥ n0

0 < c <= ∞

```

to prove that f(n) = Ω(g(n)), we do the following:

1. Drop the lower order terms (Positive).

For example, if f(n) = 3n<sup>2</sup> + 2n + 1, then we can do

```plaintext
3n^2 + 2n + 1 ≥ 3n^2

c=3, n0=0

```

another method

1. Drop the constant factor.
2. Drop all terms except the least power of n (Positive).

For example, if f(n) = 3n<sup>2</sup> + 2n + 1, then we can do

```plaintext
3n^2 + 2n + 1 ≥ n^2

c=1, n0=0

```

### Big-Θ Notation

Big-Θ (Big-Theta) notation is used to describe the average-case complexity of an algorithm. It is the formal way to express the average bound of an algorithm's running time. It measures the average-case scenario of an algorithm.

The proof of the Big-Θ notation is given by the following formula:

```

c1.g(n) ≤ f(n) ≤ c2.g(n) where n ≥ n0

0 < c1 <= c2 < ∞

```

The Left-hand side of the equation represents the lower bound, and the right-hand side of the equation represents the upper bound.

### Remember That

1. log<sub>b</sub>(N.M) = log<sub>b</sub>N + log<sub>b</sub>M

2. log<sub>b</sub>(N/M) = log<sub>b</sub>N - log<sub>b</sub>M

3. log<sub>b</sub>N<sup>K</sup> = K.log<sub>b</sub>N

4. log<sub>b</sub>(1) = 0

5. log<sub>b</sub>(b) = 1

6. log<sub>b</sub>(b<sup>k</sup>) = k

7. b<sup>log<sub>b</sub>k</sup> = k

8. log<sub>e</sub>8 = Ln(8)

9. log<sub>b</sub>a = 1/log<sub>a</sub>b

10. log<sub>a</sub>b = c, then a<sup>c</sup> = b
