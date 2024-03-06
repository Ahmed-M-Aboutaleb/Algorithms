# Introduction

Any program is combination of algorithms and data structures.

## So, what are algorithms?

An algorithm is a sequence of steps that are followed to solve a particular problem. Algorithms can perform calculation, data processing and automated reasoning tasks.

Example: How to make a cup of tea?

1. Boil water
2. Add tea leaves
3. Add sugar
4. Pour boiled water

## Problem Solving Cycle

1. Understand the problem
2. Decide on:
    - computational means
    - exact vs. approximate solving
    - algorithm design technique
3. Design an algorithm
4. Prove correctness
5. Analyze the algorithm
6. Implement the algorithm

## Algorithm Design Techniques

Any algorithm can be described in three ways:

1. Natural Language:

-   When this way is chosen care should be taken, we
    should ensure that each & every statement is definite.

2. Graphical Representation:

-   This method will work well when the algorithm is
    small& simple.

3. Pseudo Code:

-   In this method, we should typically describe
    algorithms as program, which resembles language like
    Pascal & algol.

## Pseudo-Code Conventions

1. Comments begin with `//` and continue to the end of the line.
2. Blocks are indicated with matching braces `{ and }`.
3. An identifier is a sequence of letters, digits, and underscores, starting with a letter.
4. Data types are not specified (Not explicitly declared).
5. Variables are assigned using `:=` or `<-`.
   Example: `x := 5` or `x <- 5`
6. There are two boolean values: `true` and `false`.
7. The comparison operators are `=`, `!=`, `<`, `>`, `<=`, and `>=`.
8. Logical operators are `AND`, `OR`, and `NOT`.
9. While loops are indicated with

```
While <condition> do {
    <statement>
}
```

For loop is indicated with

```
For variable := start to end step value do {
    <statement>
}
```

Repeat until loop is indicated with

```
repeat {
    <statement>
} until <condition>
```

10. A conditional statement has the following forms.

-   `If <condition> then <statement>`

-   `If <condition> then <statement-1> Else <statement-2>`

-   ```
    select case(expression) {
        case 1: <statement-1>
        case n: <statement-n>
        default: <statement>
    }
    ```

11. Input and output are done using the instructions read &
    write.

12. There is only one type of procedure:
    Algorithm, the heading takes the form,
    Algorithm Name (Parameter lists)
