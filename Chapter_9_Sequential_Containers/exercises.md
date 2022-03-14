## 9-1.
>Which is the most appropriate - a `vector`, a `deque`, or a `list` - for the following program tasks? Explain the rationale for your choice. If there is no reason to prefer one or another container, explain why not.
  (a) Read a fixed number of words, inserting them in the container alphabetically as they are entered. We'll see in the next chapter that associative containers are better suited to this problem.
  (b) Read an unknown number of words. Always insert new words at the back. Remove the next value from the front.
  (c) Read an unknown number of integers from a file. Sort the numbers and then print them to standard output.

(a) List. Since the sequence of the words need to be alphabetical, the container needs to support insert in the middle effeciently.
(b) Deque. The container needs to support insert/delete in the front and back effeciently.
(c) Vector. There is no need to use other containers. And to sort the numbers in container, random access is usually needed.

## 9-2.
>Define a `list` that holds elements that are `deque`s that hold `int`s.

```cpp
std::list<std::deque<int>> a_list_of_deque_of_ints;
```

## 9-3.
>What are the constraints on the iterators that form iterator ranges?

Two iterators, `begin` and `end`:
  - They refer to elements of the same container.
  - It is possible to reach `end` by repeatedly incrementing `begin`.

## 9-4.
>Write a function that takes a pair of iterators to a `vector<int>` and an `int` value. Look for that value in the range and return a `bool` indicating whether it was found.

```cpp
bool contains(vector<int>::const_iterator first, vector<int>::const_iterator last, int value) {
    for (; first != last; ++first)
        if (*first == value)
            return true;
    return false;
}
```

## 9-5.
>Rewrite the previous program to return an iterator to the requested element. Note that the program must handle the case where the element is not found.

```cpp
auto find(vector<int>::const_iterator first, vector<int>::const_iterator last, int value) {
    for (; first != last; ++first)
        if (*first == value)
            return first;
    return last;
}
```

## 9-6.
>What is wrong with the following program? How might you correct it?
```cpp
list<int> lst1;
list<int>::iterator iter1 = lst1.begin(), iter2 = lst1.end();
while (iter1 < iter2) /* ... */
```

Fixed:
```cpp
while (iter1 != iter2)
```
Operator `<` is not implemented in `std::list` because `std::list` is essentially a doubly linked list. Addresses of nodes of linked list are not necessarily continuous.

## 9-7.
>What type should be used as the index into a `vector` of `int`s?

`std::vector<int>::size_type`.

## 9-8.
>What type should be used to read elements in a `list` of `string`s? To write them?

We can used `std::list<std::string>::const_iterator` or `std::list<std::string>::iterator` to read elements, and use `std::list<std::string>::iterator` to write them.

## 9-9.
>What is the difference between the `begin` and `cbegin` functions?

`cbegin` is a const member that returns the container's `const_iterator` type.
`begin` is nonconst and returns the container's `iterator` type.

## 9-10.
>What are the types of the following four objects?
```cpp
vector<int> v1;
const vector<int> v2;
auto it1 = v1.begin(), it2 = v2.begin();
auto it3 = v1.cbegin(), it4 = v2.cbegin();
```

`it1` is `vector<int>::iterator`.
`it2`, `it3` and `it4` are `vector<int>::const_iterator`.

## 9-11.
>Show an example of each of the six ways to create and initialize a `vector`. Explain what values each `vector` contains.

```cpp
vector<int> v1;  // empty
vector<int> v2(v1);  // empty
vector<int> v3 = v1;  // empty
vector<int> v4{1, 2, 3};  // 3 elements: 1, 2, 3
vector<int> v5 = {1, 2, 3};  // 3 elements: 1, 2, 3
vector<int> v6(v5.begin(), v5.end());  // 3 elements: 1, 2, 3
vector<int> v7(5);  // 5 elements: 0, 0, 0, 0, 0
vector<int> v8(5, 1);  // 5 elements: 1, 1, 1, 1, 1
```

## 9-12.
>Explain the differences between the constructor that takes a container to copy and the constructor that takes two iterators.

The constructor that takes a container to copy requires the container type and the element type of the two containers are both match exactly.
The constructor that takes two iterators requires the element type of the source container must be compatible with the element type of the destiny container.
For example:
```cpp
#include <vector>
#include <list>

struct A {
};

struct B {
  B(A a) {}  // type A can convert to type B
};

int main() {
  std::vector<A> va;
  std::vector<B> vb;

  std::list<A> la(vb.begin(), vb.end());  // Error, convert B to A
  std::list<B> lb(va.begin(), va.end());  // OK, convert A to B

  return 0;
}
```

The requirement of the former constructor is stricter than the latter.

## 9-17.
>Assuming `c1` and `c2` are containers, what (if any) constraints does the following usage place on the types of `c1` and `c2`?
```cpp
if (c1 < c2)
```

The constraints are:

  1. The lefthand and righthand operands must have the same container type and element type.
  2. The element of the container must support the `<` operator.

## 9-21.
>Explain how the loop from page 345 that used the return from `insert` to add elements to a `list` would work if we inserted into a `vector` instead.

The member function `insert(p, t)` has the same effect on both `list` and `vector` containers, but the cost is different. Inserting an element into `list` is cheap, while inserting an element into `vector` will cause all the elements after the newly inserted element be moved. Thus every time the `while` loop body is executed, all elements in the `vector` are moved backward, and new element is inserted in the front of the `vector`.

## 9-22.
>Assuming `iv` is a `vector` of `int`s, what is wrong with the following program? How might you correct the problem(s)?
```cpp
vector<int>::iterator iter = iv.begin(), mid = iv.begin() + iv.size() / 2;
while (iter != mid)
  if (*iter == some_val)
    iv.insert(iter, 2 * some_val);  // Error, we should update the iterator
```

```cpp
vector<int>::iterator iter = iv.begin(), mid = iv.begin() + iv.size() / 2;
while (iter != mid) {
  if (*iter == some_val) {
    iter = iv.insert(iter, 2 * some_val);
    ++iter;
  }
  ++iter;
}
```

## 9-23.
>In the first program in this section on page 346, what would the values of `val`, `val2`, `val3`, and `val4` be if `c.size()` is 1?

Same value that equals to the first element.

## 9-25.
>In the program on page 349 that erased a range of elements, what happens if `elem1` and `elem2` are equal? What if `elem2` or both `elem1` and `elem2` are the off-the-end iterator?

  - If `elem1` and `elem2` are equal, nothing will be deleted.
  - If `elem2` is the off-the-end iterator, elements from `elem1` to the end will be deleted.
  - If `elem1` and `elem2` are both off-the-end iterators, nothing will be deleted.

## 9-29.
>Given that `vec` holds 25 elements, what does `vec.resize(100)` do? What if we next wrote `vec.resize(10)`?

```cpp
vec.resize(100);  // adds 75 elements of value 0 to the back of vec
vec.resize(10);  // erases 90 elements from the back of vec
```

## 9-30.
>What, if any, restrictions does using the version of `resize` that takes a single argument place on the element type?

If the container holds elements of a class type and resize adds elements we **must supply an initializer** or the element type must have a **default constructor**.

## 9-31.
>The program on page 354 to remove even-valued elements and duplicate odd ones will not work on a `list` or `forward_list`. Why? Revise the program so that it works on these types as well.

List doesn't support iterator arithmetic.

```cpp
for (auto cur = data.begin(); cur != data.end();)
  if (*cur & 0x1)
    cur = data.insert(cur, *cur), advance(cur, 2);
  else
    cur = data.erase(cur);
```

```cpp
for (auto cur = data.begin(), prv = data.before_begin(); cur != data.end();)
  if (*cur & 0x1)
    cur = data.insert_after(prv, *cur),
    advance(cur, 2);
    advance(prv, 2);
  else
    cur = data.erase_after(prv);
```

## 9-32.
>In the program on page 354 would it be legal to write the call to `insert` as follows? If not, why not?
```cpp
iter = vi.insert(iter, *iter++);
```

It is illegal, because the iterator will be invalidated.

## 9-33.
>In the final example in this section what would happen if we did not assign the result of `insert` to `begin`? Write a program that omits this assignment to see if your expectation was correct.

The program will crase, because the iterator will be invalidated after the insertion.

```cpp
#include <iostream>
#include <vector>

using std::vector; using std::cout; using std::endl;

int main() {
  vector<int> v{1, 2, 3, 4, 5, 6, 7, 8, 9};
  auto begin = v.begin();
  while (begin != v.end()) {
    ++begin;
    v.insert(begin, 42);
    ++begin;
  }
  for (auto i : v)
    cout << i << " ";
  return 0;
}
```

## 9-34.
>Assuming `vi` is a container of `int`s that includes even and odd values, predict the behavior of the following loop. After you've analyzed this loop, write a program to test whether your expectations were correct.
```cpp
iter = vi.begin();
while (iter != vi.end())
  if (*iter % 2)
    iter = vi.insert(iter, *iter);
  ++iter;
```

Infinite loop.

## 9-35.
>Explain the difference between a `vector`s `capacity` and its `size`.

The `size` of a container is the number of **elements** it already holds;
The `capacity` is how many elements it can hold before more **space** must be allocated.

## 9-36.
>Can a container have a `capacity` less than its `size`?

No, it can't.

## 9-37.
>Why don't `list` or `array` have a `capacity` member?

`list` does not hold elements contiguously. `array` has the fixed size statically.

## 9-39.
>Explain what the following program fragment does:
```cpp
vector<string> svec;
svec.reserve(1024);
string word;
while (cin >> word)
  svec.push_back(word);
svec.resize(svec.size() + svec.size() / 2);
```
The `while` loop will read words from `cin` and store them in the vector. Even if we initially reserved 1024 elements, if there are more words read from `cin`, out vector's capacity will be automatically increased (most implementations will double the previous capacity) to accommodate them.

And now comes the catch. `resize()` is different from `reserve()`. In this case, `resize()` will add another `svec.size()/2` value initialized elements to `svec`. If this exceeds `svec.capacity()` it will also automatically increase it to accommodate the new elements.

## 9-40.
>If the program in the previous exercise reads 256 words, what is its likely `capacity` after it is `resize`d? What if it reads 512? 1,000? 1,048?

read | size | capacity
------ | ------ | ------
256 | 384 | 1024
512 | 768 | 1024
1000 | 1500 | 2000 (clang is 2048)
1048 | 1572 | 2048

## 9-42.
>Given that you want to read a character at a time into a `string`, and you know that you need to read at least 100 characters, how might you improve the performance of your program?

Use member `reserve(120)` to allocate enough space for this string.
