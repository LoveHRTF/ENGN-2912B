# Classroom examples from Lectures 06

## Generate executable in Debug mode, test, and clean (using CMake)
```
mkdir build
cd build
cmake -DCMAKE_BUILD_TYPE=Debug ..
make
./ex06
make clean
```

What happens for N=50? N=100?  Can you find and fix the bug in main.cpp?  Try using Valgrind:

```
valgrind --tool=memcheck ./ex06
```

## Generate executable in Release mode, test, and install to ~/bin (using CMake)

```
ls -l ~/bin
```

From the "build" directory...

```
cmake -DCMAKE_BUILD_TYPE=Release ..
make
./ex06
```

After compiling and testing your source code, you can "install" it to a directory that is on your `PATH` environment variable (`echo $PATH`).  By default, the CCV includes the standard Unix locations, such as `/usr/bin/`, `/usr/sbin`, `/usr/local/bin`.  It also checks your local user account for a `/users/guestXXX/bin` directory.  You do not have permission on the CCV to add executables to the system directories (e.g., `/usr/bin`), because these directories are used by everyone on the CCV. Instead, you can install your executables in your local user directory (e.g., `~/bin`, where `~` is a symbolic link to your home directory `/users/guestXXX`).

The following command will install the executable to your local user bin directory.  Everything after `make install` is used to verify it was installed correctly.

```
make install
make clean
ls -l ~/bin
ex06
which ex06
```

To remove this executable from your path, you simply need to delete it from your `~/bin` directory using `rm ~/bin/ex06`.

Note:  Installing the executable to your user 'bin' directory will create the directory, if it doesn't already exist.

## Debugging the CMake-generated Makefile

Sometimes the output of CMake (i.e., the Makefile for a GCC build environment) doesn't produce the desired behavior.  You can see what the CMake-generated Makefile is running by using the following command during the build process.

```
make clean
make -n
```

Using `ccmake` insted of `cmake`  allows you to have more control over the CMake configuration and generation to fix any build environment issues.

