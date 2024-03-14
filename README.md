# competitive_programing

- flags de compilação no comando run em /bin

#!/bin/bash
g++ -std=c++20 -O2 -fsanitize=address,undefined -Wall -Wextra -Wconversion -Wfatal-errors -o /tmp/out $1 && /tmp/out
