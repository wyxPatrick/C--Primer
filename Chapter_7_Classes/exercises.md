## 7-5.
>Provide operations in your `Person` class to return the name and address. Should these functions be `const`? Explain your choice.

Yes, these functions should be `const`. Because we only want to read from these functions and don't want them to change object's content.

## 7-8.
>Why does `read` define its `Sales_data` parameter as a plain reference and `print` define its parameter as a reference to `const`?

Because in `read` we want to modify the `item`, but in `print` we don't want to change the `item`.

## 7-10.
>What does the condition in the following `if` statement do?
```cpp
if (read(read(cin, data1), data2))
```

Check if both arguments are read correctly.
