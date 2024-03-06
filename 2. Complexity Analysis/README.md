# Complexity Analysis

Term “analysis of algorithms” means an investigation of an algorithm’s efficiency.

The main goal is to determine the cost of running an algorithm and how to reduce that cost.

Cost is expressed as complexity, which is a function of the input size.

-   Time complexity: how long an algorithm takes to run.
-   Space complexity: how much memory an algorithm uses.

## Time Complexity

Time complexity depends on:

-   Size of input.
-   Speed of computer.
-   Efficiency of algorithm.
-   etc.

Instead of timing an algorithm, count the number of instructions that it performs.

The number of instructions performed may vary based on

-   The input size.
-   The organization of the input.

The number of instructions can be written as a cost
function on the input, expressed as T(n).

-   T(n) is the number of instructions performed on input of size n.
-   n is the size of the input.

We measure T(n) of an algorithm by counting the number of operations.

-   Each "simple" operation (+, -, =, <, >=) is one operation.
-   Loops and function calls are not simple operations, but depend upon the size of the data and the contents of a function.
-   Each memory access is one operation.

```
Arthmetic operations: +, -, *, / - 1 unit of time
Comparison operations: <, >, <=, >=, ==, != - 1 unit of time
Assignment operations: = - 1 unit of time
Return operations: return - 1 unit of time
```

Example:

```
Algorithm factorial(n) {
    f = 1; // 1 unit of time
    if(n>0) { // 1 unit of time
        for(i=1 to n) { // n+1 units of time
            f = f * i; // n units of time
        }
    }
    return f; // 1 unit of time
}

T(n) = 1 + 1 + (n+1) + n + 1
     = 2n + 4
```

## Growth Functions

| Type of Growth             | Function      |
| -------------------------- | ------------- |
| Constant                   | 1             |
| Logarithmic                | log(n)        |
| Linear                     | n             |
| Log Linear (Linearithmic ) | nlog(n)       |
| Quadratic                  | n<sup>2</sup> |
| Cubic                      | n<sup>3</sup> |
| Exponential                | 2<sup>n</sup> |
| Factorial                  | n!            |
