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

## 5-8.
>What is a "dangling else"? How are `else` clauses resolved in C++?

Dangling else is a problem that there is more `if` branches than `else` branches and we want to know which `if` a given `else` belongs.
In C++ the ambiguity is resolved by specifying that each `else` is matched with the closest preceding unmatched `if`.

## 5-13.
>Each of the programs in the highlighted text on page 184 contains a common programming error. Identify and correct each error.
```cpp
unsigned aCnt = 0, eCnt = 0, iouCnt = 0;
char ch = next_text();
switch (ch) {
  case 'a': aCnt++;  // need `break`
  case 'e': eCnt++;  // need `break`
  default: iouCnt++;
}

unsigned index = some_value();
switch (index) {
  case 1:
    int ix = get_value();  // control bypasses an explicitly initialized variable
    ivec[ix] = index;
    break;
  default:
    ix = ivec.size() - 1;
    ivec[ix] = index;
}

unsigned evenCnt = 0, oddCnt = 0;
int digit = get_num() % 10;
switch (digit) {
  case 1, 3, 5, 7, 9:  // should be case 1: case 3: case 5: case 7: case 9:
    oddcnt++;
    break;
  case 2, 4, 6, 8, 10:  // should be case 2: case 4: case 6: case 8: case 10:
    evencnt++;
    break;
}

unsigned ival = 512, jval = 1024, kval = 4096;  // case label must be integral const expression, change to `constexpr unsigned ival = 512, jval = 1024, kval = 4096;`
unsigned bufsize;
unsigned swt = get_bufCnt();
switch (swt) {
  case ival:
    bufsize = ival * sizeof(int);
    break;
  case jval:
    bufsize = jval * sizeof(int);
    break;
  case kval:
    bufsize = kval * sizeof(int);
    break;
}
