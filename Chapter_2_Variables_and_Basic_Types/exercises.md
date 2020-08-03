
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
