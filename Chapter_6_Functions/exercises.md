## 6-1.
>What is the difference between a parameter and an argument?

Arguments are the initializers for a function's parameters.

## 6-2.
>Indicate which of the following functions are in error and why. Suggest how you might correct the problems.
```cpp
// return type is not the same.
int f() {  // string f()
  string s;
  return s;
}

// does not declare the return type
f2(int i) { }  // void f2(int i) { }

// cannot have parameters with the same name
int calc(int v1, int v1) { }  // int calc(int v1, int v2) { }

// function body should be enclosed
double square(double x) return x * x;  // double square(double x) {return x * x;}
```

## 6-6.
>Explain the differences between a parameter, a local variable, and a local `static` variable. Give an example of a function in which each might be useful.

A `local variable` is a variable defined inside the function scope.

A `parameter` is also a local variable, but the definition is in the parameter list of the function.

A `local static variable` is a local variable that defined with `static` keyword. It has a lifetime much longer than usual local variable.

```cpp
int foo(int param) {
  int lv;
  static int lsv = 1;
  lv = param + lsv;
  ++lsv;
  return lv;
}
```

Here, `param` is the parameter, `lv` is the local variable, `lsv` is the local static variable.

## 6-12.
>Rewrite the program from exercise 6.10 in section 6.2.1 (p. 210) to use references instead of pointers to swap the value of two ints. Which version do you think would be easier to use and why?

Reference version is easier to use because there is no need to worry about operations related to address.

## 6-13.
>Assuming T is the name of a type, explain the difference between a function declared as `void f(T)` and `void f(T&)`.

For `void f(T)`, only the value is passed into the function. But for void f(T&), the parameter is a reference.

## 6-14.
>Give an example of when a parameter should be a reference type. Give an example of when a parameter should not be a reference.

When we want multiple returns from a function and when we need access to the argument, the parameter should be a reference type.
When the value of the parameters may change but should not affect the objects which passed in the function.

## 6-15.
>Explain the rationale for the type of each of `find_char`'s parameters. In particular, why is `s` a reference to `const` but `occurs` is a plain reference? Why are these parameters references, but the `char` parameter `c` is not? What would happen if we made `s` a plain reference? What if we made `occurs` a reference to `const`?

`s` is a reference because it passes in the original string which we do not want to change, so we use `const` to protect it. But we want additional return value `occurs` from a single function, then we need to make `occurs` as a reference.
There is no need to mae `c` as a reference because in this function we only need the value of `c` and we don't need to change it.
Make `s` a plain reference will not affect anything except introducing risk to change its value by mistake.
If we made `occurs` a reference to `const`, then we cannot revise it, which means it will not count the appearance of `c` in the string `s`.
