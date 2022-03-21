## 10-4.
>Assuming v is a `vector<double>`, what, if anything, is wrong with calling `accumulate(v.cbegin(), v.cend(), 0)`?

The type of the third argument determines which + operator is used and is the type that `accumulate` returns. The type of literal `0` is `int`, thus we will loss all the decimals if we use `0`.

## 10-5.
>In the call to `equal` on rosters, what would happen if both rosters held C-style strings, rather than library `string`s?

Then it will compare the address of two C-style strings, but not their values.
