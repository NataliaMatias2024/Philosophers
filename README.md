_This project has been created as part of the 42 curriculum by namatias._

# Philosophers
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

# ⚙️ Compilation
To compile the mandatory part of the project, run:
```bash
make
  ```
To clean object files:
```bash
make clean
  ```
To clean everything:
```bash
make fclean
  ```
To recompile:
```bash
make re
  ```

# ▶️ Usage
```bash
  ./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]
  ```
##  Arguments
 . number_of_philosophers - Number of philosophers (and forks) [0 - 200]
 . time_to_die - Time in milliseconds until a philosopher dies without eating
 . time_to_eat - Time in milliseconds it takes to eat
 . time_to_sleep - Time in milliseconds spent sleeping
 . [number_of_times_each_philosopher_must_eat] - (Optional) Simulation stops when all philosophers have eaten this many times

## 🚨 Checking leak and data races - Extra Rules
Extra rules:
To compile with valgrind (cheking leaks)
```bash
#Test case of ./philo 5 800 200 200
make val
#Expected: run -> valgrind -q --leak-check=full --show-leak-kinds=all ./philo 5 800 200 200

#Test with custom cases
make val ARGS="Arg1 Arg2 Arg3 Arg4 Arg5(optional)"
#Expected: run -> valgrind -q --leak-check=full --show-leak-kinds=all ./philo Arg1 Arg2 Arg3 Arg4 Arg5(optional)
  ```

  To compile with helgrind (cheking data races)
```bash
#Test case of ./philo 5 800 200 200
make hel
#Expected: run -> valgrind -q --tool=helgrind ./philo 5 800 200 200

#Test with custom cases
make hel ARGS="Arg1 Arg2 Arg3 Arg4 Arg5(optional)"
#Expected: run -> valgrind -q --tool=helgrind ./philo Arg1 Arg2 Arg3 Arg4 Arg5(optional)
  ```

# 🤖 Resources & AI Usage
Documentation: Valgrind & Helgrind Manual
AI Usage: AI tools were used during this project strictly for brainstorming architecture logic, discussing concurrency concepts, and validating the logical flow of mutexes. No code was directly generated or copy-pasted; AI acted as a pair-programming partner to refine understanding and debug complex timing issues.

# 🧪 Tested Environment
Linux and WSL
Flags: -Wall -Wextra -Werror
