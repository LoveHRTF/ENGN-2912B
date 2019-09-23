# ex13p2
Classroom example code from Lecture 13 [inline functions]

The `inline` keyword can be added to any function definition to request that the compiler directly copy the function implementation at the location where it is called.  This avoids the overhead of calling the function, storing existing variables on the stack, and entering the new function scope.

It is important to note that this keyword is only a request to the compiler, not an instruction.  Each compiler (e.g., GCC, CLang, Visual Studio) may implement its own set of rules for when to adhere to this inline guidance.  Furthermore, the optimization parameters used when compiling the program (e.g., Debug vs. Release, -O0 vs. -O3) will determine whether the function is actually "inlined."

In the `src/main.cpp` file, the function `func` can be prepended with the keyword `inline` as follows:

```c++
inline int func(int){
  return i*i;
}
```

The syntax and semantics of this function are exactly the same, whether it is inlined or not.  The real difference is in the performance overhead required for changing scope with each function call and return.  Excessive inlined functions may lead to "code bloat" and cause the program file size to become very large.  Every inline function, in theory, is a replica of that function.

To see what impact the inline function has on the program, we can inspect the output of the assembler.  In the CMake build environment, there is a Makefile that is generated for the GCC enviroment.  Typing `make help` after generation will display all of the available make targets.

```
gaudetteje@macbookpro:~/ex13p2/build$ make help
The following are some of the valid targets for this Makefile:
... all (the default if no target is provided)
... clean
... depend
... rebuild_cache
... edit_cache
... ex13p2
... src/main.o
... src/main.i
... src/main.s
```

Notice that the preprocessor, assembler, and object files (`src/main.i`, `src/main.s`, `src/main.o`) can be build exclusively.  By typing `make src/main.s`, we can view the assembly output and see the changes using a `diff` tool, such as `xxdiff`, `gdiff`, or `diffmerge`.  A copy of these files (with and without inlining) is in the main directory of this repository.
