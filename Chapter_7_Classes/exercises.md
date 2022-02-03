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

## 7-16.
>What, if any, are the constraints on where and how often an access specifier may appear inside a class definition? What kinds of members should be defined after a `public`specifier? What kinds should be `private`?

There is no constraint on where and how often an access specifier may appear inside a class definition. A class may contain zero or more access specifiers, each kind of access specifiers can appears multiple times. There is no constraint on the sequence of access specifiers too.

The constructors and member functions that are part of the interface should be defined after a `public` specifier.

The data members and member functions that are part of the implementation should be defined after a `private` specifier.

## 7-17.
>What, if any, are the differences between using `class` or `struct`?

The only difference between `struct` and `class` is the default access level. The members defined before the first access specifier are `public` in `struct`, while those are `private` in `class`.

## 7-18.
>What is encapsulation? Why is it useful?

Encapsulation enforces the seperation between interface and implementation in a class via access specifiers. Encapsulation provides some advantages:

  - A class that is encapsulated hides its implementation to the user of the class, thus the user need not know how the class works, they can regard the class as a type (like a built-in type) instead.
  - User code cannot inadvertently corrupt the state of an encapsulated object.
  - The implementation of an encapsulated class can change over time without requiring changes in user code.

## 7-19.
>Indicate which members of your `Person` class you would declare as `public` and which you would declare as `private`. Explain your choice.

Constructors and member methods should be `public` because they are part of interface.

Data members should be `private` because they are part of implementation.

## 7-20.
>When are friends useful? Discuss the pros and cons of using friends.

A **friend** of a class can access non`public` members of that class.

Pros:
  - For functions that are part of the interface while not a member of the class, they can access the non`public` members of that class.

Cons:
  - If the implementation of the class changes over time, its friend may also requiring changes.

## 7-25.
>Can `Screen` safely rely on the default versions of copy and assignment? If so, why? If not, why not?

Yes, because all the data members of `Screen` are built-in types or `string`, which can rely on synthesized versions for copy and assignment.

## 7-28.
>What would happen in the previous exercise if the return type of `move`, `set`, and `display` was `Screen` rather than `Screen&`?

If then, every time we call `move`, `set` or `display`, the function will return a new `Screen` object that is the copy of the original `Screen` object with the changes we made, while the original `Screen` object keeps unchanged.

## 7-30.
>It is legal but redundant to refer to members through the `this` pointer. Discuss the pros and cons of explicitly using the `this` pointer to access members.

Pros:

  - It is much more clear by using `this` to refer members.
  - The parameters in member function can have the same name as the data members if we use `this` pointer to refer data members.

Cons:

  - The code will look redundant.
