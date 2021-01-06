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

## 6-16.
>The following function, although legal, is less useful than it might be. Identify and correct the limitation on this function:
```cpp
bool is_empty(string& s) { return s.empty(); }  // is_empty(const string& s)
```

Only define `s` as a `string` object will limit the type of arguments that can be used with the function.

## 6-17.
>Write a function to determine whether a `string` contains any capital letters. Write a function to change a `string` to all lowercase. Do the parameters you used in these functions have the same type? If so, why? If not, why not?

They have different types. To check if there is a capital letter in the string, the parameter has type `const string&`. Because with `const`, we can have plain string as input and also protect the content from being changed. But to convert letters to lowercase, we need type `string&` because we need to change its content.

## 6-18.
>Write declarations for each of the following functions. When you write these declarations, use the name of the function to indicate what the function does.
(a) A function named `compare` that returns a `bool` and has two parameters that are references to a clase named `matrix`.
```cpp
bool compare(matrix& a, matrix& b)
```
(b) A function named `change_val` that returns a `vector<int>` iterator and takes two parameters: One is an `int` and the other is an iterator for a `vector<int>`.
```cpp
vector<int>::iterator change_val(int, vector<int>::iterator)
```

## 6-19.
>Given the following declarations, determine which calls are legal and which are illegal. For those that are illegal, explain why.
```cpp
double calc(double);
int count(const string &, char);
int sum(vector<int>::iterator, vector<int>::iterator, int);
vector<int> vec(10);
calc(23.4, 55.1);  // illegal. `calc` only takes one parameter
count("abcda", 'a');  // legal
calc(66);  // legal
sum(vec.begin(), vec.end(), 3.8);  // legal
```

## 6-20.
>When should reference parameters be references to `const`? What happens if we make a parameter a plain reference when it could be a reference to `const`?

Use reference to `const` whenever it is possible.
If we make a parameter a plain reference, then we cannot pass a `const` object, a literal, and we may risk changing its value.

## 6-24.
>Explain the behavior of the following function. If there are problems in the code, explain what they are and how you might fix them.
```cpp
void print(const int ia[10])
{
  for (size_t i = 0; i != 10; ++i)
    cout << ia[i] << endl;
}
```

The function intends to loop through a array with size of 10 and print out each of its elements. But there is a problem in the code and we need to fix it as follows:
```cpp
void print(const int (&ia)[10]) {}
```
Because originally, we only passed in the pointer to the first element of the array.

## 6-28.
>In the second version of `error_msg` that has an `ErrCode` parameter, what is the type of `elem` in the `for` loop?

The type is `const string &`.

## 6-29.
>When you use an `initializer_list` in a range `for` would you ever use a reference as the loop control variable? If so, why? If not, why not?

Yes, I would do that. Because using `const` can avoid copying the value of each element in the `initializer_list`.

## 6-31.
>When is it valid to return a reference? A reference to `const`?

When you can find the preexisted object that the reference refered.

## 6-32.
>Indicate whether the following function is legal. If so, explain what it doesl; if not, correct any errors and then explain it.
```cpp
int &get(int *arry, int index) {return arry[index];}
int main() {
  int ia[10];
  for (int i = 0; i != 10; ++i) {
    get(ia, i) = i;
  }
}
```
Legal. It returns the values of elements in the array.

## 6-34.
>What would happen if the stopping condition in `factorial` were
```cpp
if (val != 0)
```

If the argument is negative, this code contains a recursion loop.

## 6-35.
>In the call to `factorial`, why did we pass `val - 1` rather than `val--`?

Due to the precedence of operator. If we use `val--`, then the argument passed in the function will always be `val`.

## 6-36.
>Write the declaration for a function that returns a reference to an array of ten `strings`, without using either a trailing return, `decltype`, or a type alias.

```cpp
string (&func(string (&arr_str)[10]))[10]
```

## 6-37.
>Write three additional declarations for the function in the previous exercise. One should use a type alias, one should use a trailing return, and the third should use `decltype`. Which form do you prefer and why?

```cpp
using arrT = string[10];
arrT& func1(arrT& arr);

auto func2(arrT& arr) -> string(&)[10];

string arrS[10];
decltype(arrS) &func3(arrT& arr);
```

## 6-38.
>Revise the `arrPtr` function on to return a reference to the array.

```cpp
decltype(arr) &arrPtr(int i) {
  return (i % 2) ? odd : even;
}
```

## 6-39.
>Explain the effect of the second declaration in each one of the following sets of declarations. Indicate which, if any, are illegal.
```cpp
int calc(int, int);
int calc(const int, const int);  // Illegal. Because top-level const has no effect on the objects that can be passed to the function

int get();
double get();  // Illegal. Because it is an error for two functions to differ only in terms of their return types.

int *reset(int *);
double *reset(double *);  // Legal.
```

## 6-40.
>Which, if either, of the following declarations are errors? Why?
```cpp
int ff(int a, int b = 0, int c = 0;
char *init(int ht = 24, int wd, char bckgrnd);  // Error. If a parameter has a default argument, all the parameters that follow it must also have default arguments.
```

## 6-41.
>Which, if any, of the following calls are illegal? Why? Which, if any, are legal but unlikely to match the programmer's intent? Why?
```cpp
char *init(int ht, int wd = 80, char bckgrnd = ' ');
init();  // Illegal. Because parameter ht needs a value
init(24, 10);  // Legal
init(14, '*');  // Illegal. wd is an int but passed in a char
```
