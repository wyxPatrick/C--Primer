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


