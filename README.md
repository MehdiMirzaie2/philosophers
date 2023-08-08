<h1 align="center">42-Philosophers 🤔 </h1>

# :pushpin: Index

* [What's this Repo?](#sparkles-What-is-philosophers?)
* [Technologies](#computer-Technologies)
* [How to Run](#construction_worker-How-to-Run)
* [Find a Bug? Or something needs to change?](#bug-Issues)

# :sparkles: What is Philosophers?

"Philosopher's" is a program that simulates the classic Dining Philosophers problem, teaching concepts of multi-threading and synchronization. In this scenario, a group of philosophers sits around a circular table, and each philosopher represents a thread. There are multiple forks placed between the philosophers, and each fork is shared by two adjacent philosophers.

To ensure that the philosophers can eat without encountering issues like deadlock, I have designed a custom algorithm that promotes safe resource sharing:

Each philosopher (thread) must pick up two forks to eat a meal.
When a philosopher is hungry and wants to eat, they will follow these steps:
* a. If the philosopher doesn't have the right fork and it is available (not in use by the adjacent philosopher), they will pick it up.
* b. If the philosopher already has their own fork and the right fork is available, they will pick it up.
* c. If the philosopher has the right fork but the left fork is available, they will pick it up.
("I" refers to the philosopher that is attempting to pick up forks.)

In the implementation, we use mutexes to represent each fork, ensuring that only one philosopher can access a fork at a time. Proper synchronization techniques are employed to avoid race conditions and guarantee thread safety.

The "Philosopher's" program offers a valuable learning experience in multi-threading and synchronization concepts and serves as an illustrative example of resource-sharing scenarios in concurrent programming.

---

# :computer: Technologies

This Project was made with:

* [C](https://devdocs.io/)
* [pthread](https://www.cs.cmu.edu/afs/cs/academic/class/15492-f07/www/pthreads.html)
* [Makefile](https://www.gnu.org/software/make/manual/make.html)
* [Shell](https://unixguide.readthedocs.io/en/latest/unixcheatsheet/)
* [gcc](https://terminaldeinformacao.com/2015/10/08/como-instalar-e-configurar-o-gcc-no-windows-mingw/)

# :construction_worker: How to Run
```bash
# *************COMMANDS************ #
$ make all
# clean - remove the .o and .c files 
$ make clean
# fclean - remove the .o and .c files and the exe
$ make fclean
# re - remove all files and remake all
$ make re

$ ./philo <num_philo time_to_die time_to_eat time_to_sleep> [optional num_times_to_eat]

```


# :bug: Issues

Please feel free **to create a new issue** with its title and description on the issues page of the [philosophers](https://github.com/MehdiMirzaie2/philosophers/issues) Repository. If you have already found the solution to the problem, **I would love to review your pull request**!


To help me out, and if you think this repo is helpful give ⭐️
