## 3-3. 
>Explain how whitespace characters are handled in the string input operator and in the getline function.

 * String input operator will separate the input by whitespaces.
 * `getline(is, s)` will separate input by newline `\n`. Whitespaces are ignored.

## 3-7.
>What would happen if you define the loop control variable in the previous exercise as type char? Predict the results and then change your program to use a char to see if you were right.

If use type `char` instead of `char &`, `c` is a copy of each character of string `str`, not a reference. Thus, `str` will not change.

## 3-8.
>Rewrite the program in the first exercise, first using a while and again using a traditional for loop. Which of the three approaches do you prefer and why?

I prefer the range for. It is more concise.

## 3-9.
>What does the following program do? Is it valid? If not, why not?
```cpp
string s;
cout << s[0] << endl;
```

This code was dereferencing and printing the first item stored in `s`. Since `s` is empty, such operation is invalid.

## 3-10.
>Is the following range for legal? If so, what is the type of c?
```cpp
const string s = "Keep out!";
for (auto &c : s) { /* ... */}
```

Depending on the code within the for loop. The type of `c` is `const char&`.

## 3-12.
>Which, if any, of the following vector definitions are in error? For those that are legal, explain what the definition does. For those that are not legal, explain why they are illegal.
```cpp
vector<vector<int>> ivec;
vector<string> svec = ivec;
vector<string> svec(10, "null");
```

(a) It is legal. It is a vector of a vector of int.
(b) Illegal. ivec is a vector of int, not string.
(c) Legal. It is a vector of 10 "null" strings.

## 3-13.
>How many elements are there in each of the following vectors? What are the values of the elements?
```cpp
vector<int> v1;
vector<int> v2(10);
vector<int> v3(10, 42);
vector<int> v4{10};
vector<int> v5{10, 42};
vector<string> v6{10};
vector<string> v7{10, "hi"};
```

(a) size: 0, no values.
(b) size: 10, values: 0.
(c) size: 10, values: 42.
(d) size: 1, value: 10.
(e) size: 2, values: 10, 42.
(f) size: 10, values: "".
(g) size: 10, values: "hi".


