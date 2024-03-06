# Analysis of Non-Recursive Algorithms

1. Define a parameter indicating an input’s size (n)
2. Identify the basic operation
3. Does C(n) depends only on **n** or it also depend on type of input
4. Setup sum expressing the number of times basic operation is executed
5. Find closed form for the sum or at least establish it’s order of growth

T(n) = C<sub>op</sub> \* C(n)

C<sub>op</sub> = Execution time of basic operation

C(n) = Number of times basic operation is executed for input size n

For loop starting from 0 to n-1, C(n) = \[
\sum\_{i=0}^{n-1}
\]1 = n-1-1+1 = n-1 = Θ(n)

## Sequence

t<sub>A</sub>+t<sub>B</sub> = max(t<sub>A</sub>, t<sub>B</sub>)

if t<sub>A</sub> = Θ(n) and t<sub>B</sub> = Θ(n<sup>2</sup>) then t<sub>A</sub>+t<sub>B</sub> = Θ(max(n, n<sup>2</sup>)) = Θ(n<sup>2</sup>)

## if then else

t<sub>A</sub>/ t<sub>B</sub> = max(t<sub>A</sub>, t<sub>B</sub>)
