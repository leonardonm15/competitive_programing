# Competitive Programing

# Setup
```bash
" at /bin create a run file
#!/bin/bash 
g++ -std=c++21 -O2 -fsanitize=address,undefined -Wall -Wextra -Wconversion -Wfatal-errors -o /tmp/out $1 && /tmp/out
```
- then run 
    ```sudo chmod +x /bin/run``` to create an executable, now you have a command
- this command do not generate visible ```./a.out``` executables in the directory
# Compile Flags
The run script sets the following compile flags:

- `-std=c++20`: Compile with C++20 standard.
- `-O2`: Optimize code for performance.
- `-fsanitize=address,undefined`: Enable AddressSanitizer and UndefinedBehaviorSanitizer for runtime error detection.
- `-Wall -Wextra -Wconversion -Wfatal-errors`: Enable various warnings and treat warnings as errors to catch potential issues during compilation
