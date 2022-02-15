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

