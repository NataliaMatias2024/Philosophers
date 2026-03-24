_This project has been created as part of the 42 curriculum by namatias._

# Philosophers
## Description
This project is a multithreaded implementation of the classic Dining Philosophers Problem.  
Developed in C, using threads (pthreads) and mutexes, as part of the 42 School curriculum. 
The main objective is to work with concurrent programming, while avoiding data races, deadlocks, and undefined behavior.  

# 📂 Project Structure
```bash
philo/
├── include/
│   └── philo.h
├── src/
│   ├── clean.c
│   ├── init.c
│   ├── main.c
│   ├── monitoring.c
│   ├── parse.c
│   ├── routine.c
│   ├── threads.c
│   ├── time.c
│   └── utils.c
└── Makefile
```
## 🧩 Architecture Overview

- **`main.c`**: Entry point of the program. Orchestrates argument validation, initialization, thread creation, and cleanup.
- **`parse.c`**: Handles parsing and validation of command-line arguments, ensuring input is strictly numeric and within safe bounds.
- **`init.c`**: Initializes the main data structures (`t_info`, `t_philo`) and all required mutexes (forks, write lock, death lock).
- **`routine.c`**: The core of the simulation. Contains the main thread routine where philosophers execute their life cycle (take forks, eat, sleep, think) and the critical initial staggering logic.
- **`monitoring.c`**: A dedicated observer routine that constantly checks for philosopher deaths or if the required meal count has been reached to safely stop the simulation.
- **`time.c`**: Custom time manipulation functions, including a precise `custom_usleep` to avoid the inaccuracies of the standard `usleep` function.
- **`threads.c`**: Manages the creation (`pthread_create`) and synchronization (`pthread_join`) of all philosopher threads.
- **`utils.c`**: Utility functions, most notably the synchronized `print_action` to log state changes without data races or garbled output.
- **`clean.c`**: Ensures proper destruction of all initialized mutexes to prevent resource leaks upon program termination.

# Instructions
## ⚙️ Compilation
To compile the mandatory part of the project, run:
```bash
make
```
To clean object files:
```bash
make clean
```
To clean everything (including the executable):
```bash
make fclean
```
To recompile the project:
```bash
make re
```

## ▶️ Usage
```bash
  ./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]
```
###  Arguments
- **number_of_philosophers**: Number of philosophers and forks (1 to 200).

- **time_to_die**: Time (ms) until a philosopher dies without starting a meal.

- **time_to_eat**: Time (ms) it takes to eat (holding two forks).

- **time_to_sleep**: Time (ms) spent sleeping.

- **[number_of_times_each_philosopher_must_eat]** (Optional): Simulation stops when everyone eats this many times.

### 🚨 Checking leak and data races - Extra Rules
I have included custom rules in the Makefile to facilitate testing with Valgrind tools:  

To check for memory leaks (Valgrind):  
```bash
# Default case (5 800 200 200)
make val

# Custom case
make val ARGS="Arg1 Arg2 Arg3 Arg4 Arg5(optional)"
```

To check for data races (Helgrind):  
```bash
# Default case (5 800 200 200)
make hel

# Custom case
make hel ARGS="Arg1 Arg2 Arg3 Arg4 Arg5(optional)"
```

# 🤖 Resources & AI Usage
## Resources

- [Multithreading in C](https://www.geeksforgeeks.org/c/multithreading-in-c/)
- [Video - Thread synchronization with mutexes in C](https://www.youtube.com/watch?v=nlHIuG3RQ0g)
- [Threads, Mutexes and Concurrent Programming in C](https://www.codequoi.com/en/threads-mutexes-and-concurrent-programming-in-c/)
- [Como destacar texto (mudar cor) em C ANSI](https://pt.stackoverflow.com/questions/157898/como-destacar-texto-mudar-cor-em-c-ansi)
## AI Usage
- As per 42 School rules (Chapter III and VII), AI tools (Gemini) were used.
- Architecture Design: Discussion of the project structure and shared data logic in philo.h.
- Concurrency Logic: Analysis of the "Thundering Herd" problem and implementation of the small delay in routine.c (thinking state) to stabilize the simulation.
- Validation: No code was directly copy-pasted. The AI assisted in explaining pthread functions and validating the logical flow of mutex locking/unlocking to prevent deadlocks.

# 🧪 Tested Environment
- OS: Linux (Ubuntu) / WSL2
- Compiler: cc
- Flags: -Wall -Wextra -Werror
