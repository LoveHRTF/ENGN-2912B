# Classroom examples from Lectures 04 & 05

The following are the build commands used to demonstrate debugging with GDB and DDD

## generate executable with debugger information and all warnings included (manual G++ compilation)

This method allows us to add warnings and debugging information for each program we want to compile.

```
g++ -Wall -g -o main main.cpp
g++ -Wall -g -o main2 main2.cpp
g++ -Wall -g -o main3 main3.cpp
g++ -Wall -g -o main4 main4.cpp
```

## generate executable with debugger information and all warnings included (CMake compilation)

An alternative to manually compiling with g++ for each file is to use CMake.  The commands below will setup an "out of source" build directory where we can generate all the executables in a separate directory.  Note that this 'build' directory should never be included in the Git repository.  In fact, the entire directory can be deleted and regenerated without losing any source code.

```
mkdir build
cd build
cmake ..
make
```

## see CMake's default options (using Curses display) in Debug (-g) vs. Release mode (-O3)
`ccmake ..`

## set the release mode to Debug and start debugging
`ccmake -DCMAKE_BUILD_TYPE=Debug ..`

This will launch the Curses text-based display of CMake.  You can type 'c' to configure (may need to be run twice), then 'g' to generate the Makefile(s).

Typing 't' will show the advanced flags, which allows you to view and edit the various CMAKE flags.

`gdb main`

This launches the GNU debugger, gdb, in command line mode.  You can run through the commands using the cheatsheet on Canvas.

`ddd main &`

This command launches the GUI interface to gdb.  The `&` tells bash to execute the command and return to the command line.  DDD has all of the same features as gdb, but uses a graphical interface.

Note:  If you are running from the command line, you may need to use the -X or -Y flag to invoke X11 forwarding from the terminal to your X11 client.

