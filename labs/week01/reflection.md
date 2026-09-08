# Week 1 reflection

Write concise answers in your own words.

## 1. Source and executable

What is the difference between `src/hello.cpp` and `build/manual/hello` after compilation?

Answer:`src/hello.cpp` contains the source code in C++, `build/manual/hello` contains a compiled machine code that the computer is able to understand and execute.

## 2. Compiler warnings

What is the purpose of `-Wall -Wextra -Wpedantic`?

Answer: The use of `-Wall -Wextra -Wpedantic` makes the compiler warn us about potential problems with our code.

## 3. Value and reference parameters

What is the difference between these declarations?

```cpp
void f(std::vector<int> values);
void f(std::vector<int>& values);
```

Answer: The first declaration passes the vector to the function as a copy. With the second declaration, a reference to the vector is passed, which allows the function to access and modify the original vector.

## 4. Const reference

Why can this parameter form be useful?

```cpp
void print(const std::vector<int>& values);
```

Answer:This parameter form allows the function to access the original vector without creating copies. However, it does not allow the function to modify the original vector. It can be useful when you need to pass large values to functions, but do not want these values to be changed.

## 5. Linux navigation

Which command shows the current working directory?

Answer:`pwd` prints the current working directory.

## 6. Git state

Which command shows modified files?

Answer: `git status`
