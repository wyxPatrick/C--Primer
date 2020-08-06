
2-1. What are the differences between int, long, long long, and short? Between an unsigned and a signed type? Between a float and a double?

	Minimum size of int and short are 16 bits. Minimum size of long is 32 bits. Minimum size of long long is 64 bits.

	A signed type represents negative or positive numbers (including zero); an unsigned type represents only values greater than or equal to zero.

	float represents single-precision floating-point, and double represents double-precision floating-point.

2-2. To calculate a mortgage payment, what types would you use for the rate, principle, and payment? Explain why you selected each type.

	Double. For floating-point computations, float usually does not have enough precision, and the cost of double-precision calculations versus single-precision is negligible.

2-3. What output will the following code produce?

```
	unsigned u = 10, u2 = 42;
	std::cout << u2 - u << std::endl;  // 32
	std::cout << u - u2 << std::endl;  // Very large number

	int i = 10, i2 = 42;
	std::cout << i2 - i << std::endl;  // 32
	std::cout << i - i2 << std::endl;  // -32

	std::cout << i - u << std::endl;  // 0
	std::cout << u - i << std::endl;  // 0
```

2-5. Determine the type of each of the following literals. Explain the differences among the literals in each of the four examples:

	a). 'a': character literal, L'a': wide character literal, "a": string literal, L"a": wide string literal.
	
	b). 10: integer literal, 10u: unsigned integer literal, 10L: long integer literal, 10uL: unsigned long integer literal, 012: octal literal, 0xC: hexadecimal literal.
	
	c). 3.14: double-precision (double) literal, 3.14f: single-precision (float) literal, 3.14L: extended-precision (long double) literal
	
	d). 10: integer literal, 10u: unsigned integer literal, 10.: double-precision (double) literal, 10e-2: double-precision (double) literal

2-6. What, if any, are the differences between the following definitions:
	```
	int month = 9, day = 7;
	int month = 09, day = 07;
	```
	
	The above line are integer literals. The bottom line are octal literals.

2-7. What values do these literals represent? What type does each have?

	a). "Who goes with F\145rgus?\012": "Who goes with Fergus?", string literal.
	
	b). 3.14e1L: 31.4, extended-precision (long double) literal.
	
	c). 1024f: 1024.0, single-precision (float) literal.
	
	d). 3.14L: 3.14, extended-precision (long double) literal.
	

2-9. Explain the following definitions. For those that are illegal, explain what's wrong and how to correct it.

	a). std::cin >> int input_value;
		Defined variable named input_value as int type and initialized by a value passed from std::cin.

	b). int i = {3.14};
		Initialized variable i as int type with a value of 3.14.

	c). double salary = wage = 9999.99;
		Illegal. wage is not initialized.

	d). int i = 3.14;
		Initialized variable i as int type with a value of 3.14.

2-10. What are the initial values, if any, of each of the following variables?

```
	std::string global_str;
	int global_int;
	int main()
	{
		int local_int;
		std::string local_str;
	}
```

	global_str: "", global_int: 0, local_int: uninitialized, local_str: uninitialized

2-11. Explain whether each of the following is a declaration or a definition:

	a). extern int ix = 1024; definition

	b). int iy; definition

	c). extern int iz; declaration

2-12. Which, if any, of the following names are invalid?

	a). int double = 3.14; invalid

	b). int _; valid

	c). int catch-22; invalid

	d). int 1_or_2 = 1; invalid

	e). double Double = 3.14; valid

2-13. What is the value of j in the following program?

```
	int i = 42;
	int main()
	{
		int i = 100;
		int j = i;
	}
```

	The value of j is 100.

2-14. Is the following program legal? If so, what values are printed?

```
	int i = 100, sum = 0;
	for (int i = 0; i != 10; ++i)
		sum += i;
	std::cout << i << " " << sum << std::endl;
```

	It is legal. 10 45

2-15. Which of the following definitions, if any, are invalid? Why?

	a). int ival = 1.01;  valid

	b). int &rval1 = 1.01;  invalid, initializer must be an object

	c). int &rval2 = ival;  valid

	d). int &rval3;  invalid, a reference must be initialized

2-16. Which, if any, of the following assignments are invalid? If they are valid, explain what they do.

```
	int i = 0, &r1 = i; double d = 0, &r2 = d;

	a). r2 = 3.14159;  valid, d = 3.14159

	b). r2 = r1;  invalid, i and r2 are different types

	c). i = r2;  valid, i = (int) d

	d). r1 = d;  invlalid, r1 and d are different types
```

2-17. What does the following code print?

```
	int i, &ri = i;
	i = 5; ri = 10;
	std::cout << i << " " << ri << std::endl;
```

	10 10

2-19. Explain the key differences between pointers and references.

	Reference is an alias to an object. It is not an object and there is no way to make that reference refer to a different object. Reference must be initialzed at the time it is defined.

	Pointer is an object in its own right. Pointers can be assigned and copied, and a single pointer can point to several different objects over its lifetime. A pointer need not be initialized at the time it is defined. Pointers defined at block cope have undefined value if they are not initialized.

2-20. What does the following program do?

```
	int i = 42;
	int *p1 = &i;
	*p1 = *p1 * *p1;
```

	i = 1764

2-21. Explain each of the following definitions. Indicate whether any are illegal and, if so, why.

```
	int i = 0;
```

	a). double* dp = &i; Illegal, types must match.

	b). int *ip = i; Illegal, cannot assign an int to a pointer.

	c). int *p = &i; Legal.

2-22. Assuming p is a pointer to int, explain the following code:

	if (p)  // p points to an int, so it is not 0; the condition evaluates as true.
	if (*p)  // If *p points to 0, it is false; else, it is true.

2-23. Given a pointer p, can you determine whether p points to a valid object? If so, how? If not, why not?

	No, we can't. Because whether pointer is valid or not is controled by ourselves. For example:

```
	int *ptr = new int (10);
	int *ptrDup = ptr;

	delete ptr;
```

2-24. Why is the initialization of p legal but that of lp illegal?

```
	int i = 42;
	void *p = &i;
	long *lp = &i;
```

	Because void* pointer can hold the address of any object, and the type of the object at that address is unknown.
	But other types of pointers must match the type of the object.

2-25. Determine the types and values of each of the following variables.

	a). int* ip, i, &r = i;  ip is a pointer to int; i is an int; r is a reference to int.

	b). int i, *ip = 0;  i is an int, ip is a nullptr to int.

	c). int* ip, ip2;  ip is a pointer to int; ip2 is an int.

2-26. Which of the following are legal? For those that are illegal, explain why.

	a). const int buf;  Illegal, because buf is not initialized.

	b). int cnt = 0;  Legal.

	c). const int sz = cnt;  Legal.

	d). ++cnt; ++sz;  Illegal, sz is const type, so its value cannot be changed.

2-27. Which of the following initializations are legal? Explain why.

	a). int i = -1, &r = 0;  Illegal, initializer of a reference must be an object.

	b). int *const p2 = &i2;  Legal. p2 will always point to i2.

	c). const int i = -1, &r = 0; Legal. const &r = 0 is legal!

	d). const int *const p3 = &i2;  Legal. p2 will always point to a const int i2.

	e). const int *p1 = &i2;  Legal. p1 points to const int i2.

	f). const int &const r2;  Illegal. There is no type of &const.

	g). const int i2 = i, &r = i;  Legal. i2 is a const int and r is a reference to const.

2-28. Explain the following definitions. Identify any that are illegal.

	a). int i, *const cp;  Illegal. Pointer to const must be initialized.

	b). int *p1, *const p2;  Illegal. Pointer to const must be initialized.

	c). const int ic, &r = ic;  Illegal. ic must be initialized beacuse it is a const.

	d). const int *const p3;  Illegal. Pointer to const must be initialized.

	e). const int *p;  Legal. p points to a const int object.

2-29. Using the variables in the previous exercise, which of the following assignments are legal? Explain why.

	a). i = ic;  Legal. const int can define a int object.

	b). p1 = p3;  Illegal. int* cannot be initialized by const int*.

	c). p1 = &ic;  Illegal. int* cannot point to a const int object.

	d). p3 = &ic;  Illegal. The address stored in p3 cannot be changed.

	e). p2 = p1;  Illegal. The address stored in p2 cannot be changed.

	f). ic = *p3;  Illegal. ic is const whose value cannot be changed.

2-30. For each of the following declarations indicate whether the object being declared has top-level or low-level const.

```
	const int v2 = 0; int v1 = v2;
	int *p1 = &v1, &r1 = v1;
	const int *p2 = &v2, *const p3 = &i, &r2 = v2;
```

	v2 has a top-level const. p2 has a low-level const. p3 has both top-level const and low-level const. r2 has low-level const.

2-31. Given the declarations in the previous exercise determine whether the following assignments are legal. Explain how the top-level or low-level const applies in each case.

	r1 = v2;  Legal, v2 has a top-level const.
	p1 = p2; p2 = p1;  Illegal, p2 has a low-level const, but p1 doesn't. p2 = p1 is legal.
	p1 = p3; p2 = p3;  Illegal, p3 has a low-level const, but p1 doesn't. p2 = p3 is legal.

2-32. Is the following code legal or not? If not, how might you make it legal?

```
	int null = 0, *p = null;
```

	It is illegal. Pointer can't be initialized by an int. Change to: int null = 0; *p = &null; or *p = nullptr;

2-33. Using the variable definitions from this section, determine what happens in each of these assignments:

	a = 42; ok
	b = 42; ok
	c = 42; ok
	d = 42; d is an int*, error
	e = 42; e is const int*, error
	f = 42; f is const int, error

2-35. Determine the types deduced in each of the following definitions. Once you've figured out the types, write a program to see whether you were correct.

```
	const int i = 42;
	auto j = i; const auto &k = i; auto *p = &i;
	const auto j2 = i, &k2 = i;
```
	
	j is int, k is reference to const int, p is pointer to const int, j2 is const int, k2 is reference to const int.

2-36. In the following code, determine the type of each variable and the value each variable has when the code finishes:

```
	int a = 3, b = 4;
	decltype(a) c = a;
	decltype((b)) d = a;
	++c;
	++d;
```

	a: int, b: int, c: int, d: int&

2-37. Assignment is an example of an expression that yields a reference type. The type is a reference to the type of the left-hand operand. That is, if i is an int, then the type of the expression i = x is int&. Using that knowledge, determine the type and value of each variable in this code:

```
	int a = 3, b = 4;
	decltype(a) c = a;
	decltype(a = b) d = a;
```

	a: int, 3; b: int, 4; c: int, 3; d: int&. 3;

2-38. Describe the differences in type deduction between decltype and auto. Give an example of an expression where auto and decltype will deduce the same type and an example where they will deduce differing types.

	decltype will include top-level const and references, but auto will ignore them.
	Example:
	int i, &j = i;
	auto a = j; // int
	decltype(j) b; // int &
	auto c = i;  // int 
	decltype(i) d;  // int
