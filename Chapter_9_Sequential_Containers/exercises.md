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
