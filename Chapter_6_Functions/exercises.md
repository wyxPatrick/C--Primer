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
