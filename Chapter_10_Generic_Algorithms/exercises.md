## 10-4.
>Assuming v is a `vector<double>`, what, if anything, is wrong with calling `accumulate(v.cbegin(), v.cend(), 0)`?

The type of the third argument determines which + operator is used and is the type that `accumulate` returns. The type of literal `0` is `int`, thus we will loss all the decimals if we use `0`.

## 10-5.
>In the call to `equal` on rosters, what would happen if both rosters held C-style strings, rather than library `string`s?

Then it will compare the address of two C-style strings, but not their values.

## 10-7.
>Determine if there are any errors in the following programs and, if so, correct the error(s):
(a)
```cpp
vector<int> vec; list<int> lst; int i;
while(cin >> i)
  lst.push_back(i);
copy(lst.cbegin(), lst.cend(), lst.begin());  // copy(lst.cbegin(), lst.cend(), back_inserter(vec));
```
(b)
```cpp
vector<int> vec;
vec.reserve(10);
fill_n(vec.begin(), 10, 0);  // no error
```

## 10-8.
>We said that algorithms do not change the size of the containers over which they operate. Why doesn't the use of `back_inserter` invalidate this claim?

Inserters like `back_inserter` is part of `<iterator>` rather than `<algorithm>`.

## 10-10.
>Why do you think the algorithms don't change the size of containers?

We pass only iterators to algorithms, not containers, so the algorithms have no direct access to the container members. If we want to change the size of a container, we must do it by calling the container members. Thus the algorithms cannot change the size of containers.

Insert container, however, has access to container members when we pass the container to it. Thus it can change the size of containers.
