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

## 4-13.
>What are the values of `i` and `d` after each assignment?
```cpp
int i;
double d;
d = i = 3.5; // i = 3, d = 3
i = d = 3.5; // d = 3.5, i = 3
```

## 4-14.
>Explain what happens in each of the `if` tests:
```cpp
if (42 = i) // error: literals are rvalues
if (i = 42) // evaluated as true
```

## 4-15.
>The following assignment is illegal. Why? How would you correct it?
```cpp
double dval;
int ival;
int *pi;
dval = ival = pi = 0;
```

Cannot assign the value of a pointer to an `int`.
```cpp
pi = 0;
dval = ival = 0;
```

## 4-16.
>Although the following are legal, they probably do not behave as the programmer expects. Why? Rewrite the expressions as you think they should be.
```cpp
if (p = getPtr() != 0) // it will evaluate getPtr() != 0 first
if (i = 1024) // it is assignment rather than comparison
```

```cpp
if ((p = getPtr()) != 0)
if (i == 1024)
```

## 4-17.
>Explain the difference between prefix and postfix increment.

Prefix increments its operand and yields the changed object as its result. The postfix operator increments the operand but yield a copy of the original, unchanged value as its result.

## 4-18.
>What would happen if the `while` loop on page 148 that prints then elements from a `vector` used the prefix increment operator?

We would dereference the incremented value, skip the first element, and even attempt to dereference one too many elements if the sequence had no negative values.

## 4-19.
>Given the `ptr` points to an `int`, that `vec` is a `vector<int>`, and that `ival` is an `int`, explain the behavior of each of these expressions. Which, if any, are likely to be incorrect? Why? How might each be corrected?
```cpp
ptr != 0 && *ptr++;  // Check if the pointer is a nullptr. If it is not, then check the value it points to
ival++ && ival;  // Check if ival is 0. If it is not, then check the value of ival incremented by 1
vec[ival++] <= vec[ival];  // Error! **Undefined behavior**
// correct:
vec[ival] <= vec[ival+1];

## 4-20.
>Assuming that `iter` is a `vector<string>::iterator`, indicate which, if any, of the following expressions are legal. Explain the behavior of the legal expressions and why those aren't legal are in error.
```cpp
*iter++;  // *iter, then ++iter
(*iter)++;  // illegal, *iter is a string
*iter.empty();  // illegal, iter doesn't have member function empty()
iter->empty();  // indicate whether iter is empty or not
++*iter;  // illegal, string can't be incremented
iter++->empty();  // iter->empty(), then ++iter
