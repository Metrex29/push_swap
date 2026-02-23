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
