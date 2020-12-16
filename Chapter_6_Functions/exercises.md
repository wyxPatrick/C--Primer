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
