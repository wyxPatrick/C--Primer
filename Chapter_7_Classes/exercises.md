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

## 7-33.
>What would happen if we gave `Screen` a `size` member defined as follows? Fix any problems you identify.
```cpp
pos Screen::size() const
{
    return height * width;
}
```

The return type `pos` is a member `typedef` of class `Screen`, thus it needs the scope operator `Screen::pos`.

## 7-34.
>What would happen if we put the `typedef` of `pos` in the `Screen` class on page 285 as the last line in the class?

Then every usage of `pos` would be an error because of lacking definition.

## 7-35.
>Explain the following code, indicating which definition of `Type` or `initVal` is used for each use of those names. Say how you would fix any errors.
```cpp
typedef string Type;
Type initVal();  // std::string
class Exercise {
public:
    typedef double Type;
    Type setVal(Type);  // double setVal(double)
    Type initVal();  // double initVal()
private:
    int val;
};
Type Exercise::setVal(Type parm) {  // double Exercise::setVal(double para)
    val = parm + initVal();
    return val;
}
```

## 7-36.
>The following initializer is in error. Identify and fix the problem.
```cpp
struct X {
    X (int i, int j) : base(i), rem(base % j) { }
    int rem, base;
};
```

The order of member initialization is the same with the order they appear in the class definition. Since `rem` appears first, it will be initialized first. But the value of `base` is undefined when `rem` is initialized, thus the value of `rem` is undefined. To fix the problem, we can either switch the order of definitions of `rem` and `base` or we can use the constructor parameters `i` and `j` direct initialize `rem(i % j)`.

## 7-37.
>Using the version of `Sales_data` from this section, determine which constructor is used to initialized each of the following variables and list the values of the data members in each object:
```cpp
Sales_data first_item(cin);  // Sales_data(std::istream& is);
int main() {
    Sales_data next;  // Sales_data(std::string s = "");
    Sales_data last("9-999-99999-9");  // Sales_data(std::string s = "");
}
```

As listed in comments above.

## 7-39.
>Would it be legal for both the constructor that takes a `string` and the one that takes an `istream&` to have default arguments? If not, why not?

It is illegal for both constructors to have default arguments. If then, there will be two default constructors, and that's an error.

## 7-40.
>Choose one of the following abstractions (or an abstraction of your own choosing). Determine what data are needed in the class. Provide an appropriate set of constructors. Explain your decisions.
(a) Book  (b) Data  (c) Employee
(d) Vehicle  (e) Object  (f) Tree

(a) Book
```cpp
class Book {
public:
    Book() : isbn(""), name(""), author(), publish_year(0), publisher(""), version(0) {}
    Book(const std::string& i, const std::string& n, const std::vector<std::string>& au, unsigned y, const std::string& p = "", unsigned v = 1) : isbn(i), name(n), author(au), publish_year(y), publisher(p), version(v) {}
    Book(std::istream& is) {
        is >> isbn >> name;
        std::string s;
        is >> s;
        author.push_back(s);
        is >> publish_year >> publisher >> version;
    }
private:
    std::string isbn;
    std::string name;
    std::vector<std::string> author;
    unsigned publish_year;
    std::string publisher;
    unsigned version;
};
```

## 7-42.
>For the class you wrote for exercise 7.40 in section 7.5.1 (p. 291), decide whether any of the constructors might use delegation. If so, write the delegating constructor(s) for your class. If not, look at the list of abstractions and choose one that you think would use a delegating constructor. Write the class definition for that abstraction.

```cpp
class Book {
public:
    Book() : Book("", "", std::vector<std::string>(), 0, "", 0) {}
    Book(const std::string& i, const std::string& n, const std::vector<std::string>& au, unsigned y, const std::string& p = "", unsigned v = 1) : isbn(i), name(n), author(au), publish_year(y), publisher(p), version(v) {}
    Book(std::istream& is) {
        is >> isbn >> name;
        std::string s;
        is >> s;
        author.push_back(s);
        is >> publish_year >> publisher >> version;
    }
private:
    std::string isbn;
    std::string name;
    std::vector<std::string> author;
    unsigned publish_year;
    std::string publisher;
    unsigned version;
};
```

## 7-44.
>Is the following declaration legal? If not, why not?
```cpp
vector<NoDefault> vec(10);
```

It is illegal, the constructor of `vector` taken a single number will call the default constructor of elements to value initialize its elements, but the class of the elements `NoDefault` does not have a default constructor, thus the code will not compile.

## 7-45.
>What if we defined the `vector` in the previous exercise to hold objects of type C?

Then the code ```vector<C> vec(10);``` is legal.

## 7-46.
>Which, if any, of the following statements are untrue? Why?
  (a) A class must provide at least one constructor.
  (b) A default consturctor is a constructor with an empty parameter list.
  (c) If there are no meaningful default values for a class, the class should not provide a default constructor.
  (d) If a class does not define a default constructor, the compiler generates one that initializes each data member to the default value of its associated type.

  (a) True. If the programmer doesn't provide any constructor, the compiler will synthesise one default constructor.
  (b) False. A constructor of which all parameters have default values also defines a default constructor.
  (c) False. If no constructor defined, there will always be a default constructor.
  (d) False. Only if a class does not define **any constructors**, will the compiler generate synthesised default constructor.

## 7-47.
>Explain whether the `Sales_data` constructor that takes a `string` should be `explicit`. What are the benefits of making the constructor `explicit`? What are the drawbacks?

It should be `explicit`. Otherwise, code like `item.combine("9-999-99999-9")` will compile, but the code has no logical meaning.

Making the constructor `explicit` will stop compiler from automatically converting one type to the class type, which makes the code same as anticipation.

The drawback is we must call the constructor explicitly if we want to cover one type to the class type.

## 7-48.
>Assuming the `Sales_data` constructors are not `explicit`, what operations happen during the following definitions
```cpp
string null_isbn("9-999-99999-9");  // call string constructor
Sales_data item1(null_isbn);  // call Sales_data constructor
Sales_data item2("9-999-99999-9");  // first convert "9-999-99999-9" to string, then call Sales_data constructor
```

If the constructors are `explicit`, the same operations happen.

## 7-49.
>For each of the three following declarations of `combine`, explain what happens if we call `i.combine(s)`, where `i` is a `Sales_data` and `s` is a `string`:
  (a) ```Sales_data &combine(Sales_data);```  // Correct. It will first convert `s` to `Sales_data`, then copy that temporary into the parameter of `combine`.
  (b) ```Sales_data &combine(Sales_data&);```  // Wrong. It will first convert `s` to `Sales_data`, then pass the reference to that temporary into the parameter of `combine`, but passing a reference to a temporary is error.
  (c) ```Sales_data &combine(const Sales_data&) const;  // Wrong and will not compile, because it should not be a const member function. It will first convert `s` to `Sales_data`, then pass the const reference to that temporary into the parameter of `combine`.

## 7-51.
>Why do you think `vector` defines its single-argument constructor as `explicit`, but `string` does not?

Because semantically speaking, a number is different from a vector, but a char array is the same as string.

## 7-54.
>Should the members of `Debug` that begin with `set_` be declared as `constexpr`? If not, why not?

No, becuase the function contains excutable statement other than `return`.

## 7-55.
>Is the `Data` class from section 7.5.5 (p.298) a literal class? If not, why not? If so, explain why it is literal.

No, because std::string is not a literal type.

## 7-56.
>What is a `static` class member? What are the advantages of `static` members? How do they differ from ordinary members?

A `static` class member is a member that is associated with the class, rather than with individual objects of the class type. It exists outside any object of the class.

Advantages:

  - Storage efficient.
  - If a `static` member of a class changes, each object of the class will use the new value of that `static` member.
  - A `static` data member can have incomplete type.
  - A `static` member (either a data member or a member function) can be used as a default argument.

Differences between ordinary members and `static` members:

  - A `static` member belongs to the class, an ordinary member belongs to objects of the class.
