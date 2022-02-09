## 8-1.
>What causes the following `while` to terminate?
```while (cin << i)  /* ... */```

The condition of a stream is equivalent to `!fail()`, which means set either `failbit` or `badbit` will terminate the loop. For example, errors list below will terminate the loop:

  - System-level failure. (Set the `badbit`) Such as an unrecoverable r/w error.
  - Recoverable error. (Set the `failbit`) Such as reading a character when numeric data expected.
  - Reaching end-of-file. (Set both the `eofbit` and `failbit`)

## 8-12.
>Why didn't we use in-class initializers in `PersonInfo`?

Because the synthesised default constructor will be called when an object of class `PersonInfo` is created, which will default initialized its data members. Meanwhile, both `string` and `vector` have default constructors, and will be used when default initialized. Thus, we don't need in-class initializers to initialize data members in `PersonInfo`.

## 8-14.
>Why did we declare `entry` and `nums` as `const auto &`?

By using reference, we avoid copy every object in vectors. By using `const`, we avoid accidentally changing the values of elements in vectors.
