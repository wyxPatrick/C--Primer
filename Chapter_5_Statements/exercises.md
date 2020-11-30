## 5-1.
>What is a null statement? When might you use a null statement?

A null statement is a single semicolon `;`. A null statement is useful where the language requires a statement but the program's logic does not.

## 5-2.
>What is a block? When might you might use a block?

A block is also referred to as a compound statement. It is a (possibly empty) sequence of statements and declarations surrounded by a pair of curly braces. Blocks are used when the language requires a single statement but the logic of our program needs more than one.

## 5-3.
>Use the comma operator (4.10, p.157) to rewrite the `while` loop from section 1.4.1 (p.11) so that it no longer requires a block. Explain whether this rewrite improves or diminishes the readability of this code.

```cpp
while (val <= 10 && (sum += val, ++val)) ;
```

## 5-4.
>Explain each of the following examples, and correct any problems you detect.
```cpp
while (string::iterator iter != s.end()) {}  // execute the block as long as iter is at the end of s
while (bool status = find(word)) {}  // should be `bool status == find(word)`
if (!status) {}  // `status` is not accessible
```
