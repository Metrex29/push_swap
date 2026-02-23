*This project has been created as part of the 42 curriculum by cpicon-m.*

# 📊 Push_swap: Optimized Stack Sorting

## 📝 Overview
`push_swap` is an algorithmic optimization challenge. The objective is simple: sort a set of integers using two stacks (`a` and `b`) and a restricted set of operations, generating the shortest possible sequence of commands.

In this project, efficiency is key: every move counts toward meeting the strict complexity limits required by the 42 benchmarks.

---

## 🛠️ The Sorting Toolkit
The program manipulates data using the following permitted operations:

| Category | Operation | Action |
| :--- | :--- | :--- |
| **Swaps** | `sa`, `sb`, `ss` | Swap the first two elements at the top of stack `a`, `b`, or both. |
| **Pushes** | `pa`, `pb` | Take the top element from one stack and put it on top of the other. |
| **Rotations** | `ra`, `rb`, `rr` | Shift up all elements by 1; the first becomes the last. |
| **Rev Rotations**| `rra`, `rrb`, `rrr`| Shift down all elements by 1; the last becomes the first. |

---

## 💡 Algorithm Strategy
To solve the problem, I implemented two distinct approaches:
1. **Small Sort (2-5 elements)**: Specific decision logic designed to sort small sets in the absolute minimum number of steps.
2. **Large Sort (K-Sort / Chunks)**: For larger volumes (100 and 500 numbers), I use a block-based pre-sorting strategy (K-sort) to reduce moves during the final sorting phase in stack `a`.

### 🤖 AI Disclosure & Resources
In accordance with the project's AI instructions:
- **Resources**: I relied on technical blogs and visualizers to understand the mechanics of "Chunk" algorithms.
- **AI Usage**: I used AI tools to optimize mathematical ranges for the blocks and to perform memory stress tests (Valgrind), ensuring a robust, leak-free execution.
- **Documentation**: I used AI assistance to structure and format this `README.md` to ensure clarity and professional presentation.

### 🛠️ Visualizing the Algorithm
To debug and optimize the "Hourglass" (K-Sort) effect, I used visual tools to monitor the stack's behavior in real-time:
- **[push_swap_visualizer](https://github.com/o-reo/push_swap_visualizer)**: Used to verify the efficiency of the `range` and ensure the stacks were being pre-sorted correctly before the final `push_to_a` phase.
---

## 🚀 Get Started

### Compilation
Compile the project using the provided `Makefile`:
```bash
make
```
🧪 Evaluation Checklist
1. Error Management

Every command in this section must print Error to the standard error (stderr), except for the empty argument which should return the prompt.
Bash

# Non-numeric arguments
./push_swap 1 2 three 4

# Duplicate arguments
./push_swap 1 2 3 1

# Out of integer range (INT_MAX / INT_MIN)
./push_swap 2147483648
./push_swap -2147483649

# Empty string (Should NOT display anything)
./push_swap ""

2. Memory Leaks (Valgrind)

Run these commands to ensure there are no memory leaks in any scenario.
Bash

# Normal execution leak check
ARG=$(shuf -i 0-1000 -n 100 | tr '\n' ' '); valgrind --leak-check=full ./push_swap $ARG

# Error handling leak check
valgrind --leak-check=full ./push_swap 1 2 3 1

3. Benchmarks & Correctness

The score depends on the number of instructions. Use these commands to check the count and verify sorting.
🔢 Small Sets (Score based on logic)
Bash

# 3 numbers (Should be < 3 instructions)
ARG="1 3 2"; ./push_swap $ARG | wc -l
./push_swap $ARG | ./checker_linux $ARG

# 5 numbers (Should be < 12 instructions)
ARG="5 2 4 1 3"; ./push_swap $ARG | wc -l
./push_swap $ARG | ./checker_linux $ARG

🔢 Large Sets (Score based on efficiency)
Bash

# 100 numbers (Max score < 700)
ARG=$(shuf -i 0-1000 -n 100 | tr '\n' ' '); ./push_swap $ARG | wc -l
./push_swap $ARG | ./checker_linux $ARG

# 500 numbers (Max score < 5500)
ARG=$(shuf -i 0-5000 -n 500 | tr '\n' ' '); ./push_swap $ARG | wc -l
./push_swap $ARG | ./checker_linux $ARG

4. Already Sorted / Identity

If the stack is already sorted, the program should display nothing.
Bash

./push_swap 1 2 3
./push_swap 0 1 2 3 4 5