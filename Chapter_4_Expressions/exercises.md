## 4-1. 
>What is the value returned by `5 + 10 * 20 / 2`?

105

## 4-2.
>Using Table 4.12(p. 166), parenthesize the following expressions to indicate the order in which the operands are grouped:
```cpp
* vec.begin()  // *(vec.begin())
*vec.begin()+1  // (*(vec.begin()))+1

## 4-3.
>Order of evaluation for most of the binary operators is left undefined to give the opportunities for optimization. This strategy presents a trade-off between efficient code generation and potential pitfalls in the use of the language by the programmer. Do you consider that an acceptable trade-off? Why or why not?

No. It is more error-prone.

## 4-4.
>Parenthesize the following expression to show how it is evaluated. Test your answer by compiling the expression (without parentheses) and printing its result.
12 / 3 * 4 + 5 * 15 + 24 % 4 / 2

((((12 / 3) * 4) + (5 * 15)) + ((24 % 4) / 2))

## 4-5.
>Determine the result of the following expressions.
-30 * 3 + 21 / 5 = -86
-30 + 3 * 21 / 5 = -18
30 / 3 * 21 % 5 = 0
-30 / 3 * 21 % 4 = -2

## 4-6.
>Write an expression to determine whether an int value is even or odd.

```cpp
if (a / 2 == 0){
  cout << "even" << endl;
}
else {
  cout << "odd" << endl;
}
```

## 4-7.
>What does overflow mean? Show three expressions that will overflow.

Overflow means the value is out of the range of the type. Such as:
```cpp
short a = 32767;
a++;

unsigned int b = 0;
b = b - 2;

int c = 2147483647;
c++;
```

## 4-8.
>Explain when operands are evaluated in the logical AND, logical OR, and equality operators.

* The right side of an `&&` is evaluated if and only if the left side is `true`.
* The right side of an `||` is evaluated if and only if the left side is `false`.
* Operands are evaluated when they are in or can be converted to the same type for equality operators.

## 4-9.
>Explain the behavior of the condition in the following `if`:
```cpp
const char *cp = "Hello World";
if (cp && *cp)
```

`cp` is a pointer to "Hello World" and it is not nullptr. `*cp` is the const char 'H' and it will return `true`. Thus, the if condition is evaluated as `true`.

## 4-10.
>Write the condition for a `while` loop that would read `ints` from the standard input and stop when the value read is equal to 42.

```cpp
int i = 0;
while (std::cin >> i && i != 42)
```

## 4-11.
>Write an expression that tests four values, `a`, `b`, `c`, and `d`, and ensures that `a` is greater than `b`, which is greater than `c`, which is greater than `d`.

```cpp
if (a > b && b > c && c > d)
```

## 4-12.
>Assuming `i`, `j`, and `k` are all `int`s, explain what `i != j < k` means.

It is equivalent to `i != (j < k)`.
