# 42SP_philosophers
I never thought philosophy would be so deadly

<div align="center">
<a href="https://github.com/JaeSeoKim/badge42"><img src="https://badge42.vercel.app/api/v2/cli7l4sim001108mvngbgwmeh/project/3103991" alt="feralves's 42 Philosophers Score" /></a>
</div>
<br>

## Main goal
This project asks students to solve the famous Dijkstra's synchronization problem called The Dining Philosophers Problem. This is a introduction to multithreads, multiprocesses, mutexes and semaphores.

###The specific rules for the mandatory part are:

- Each philosopher should be a thread.
- There is one fork between each pair of philosophers. Therefore, if there are several philosophers, each philosopher has a fork on their left side and a fork on their right side. If there is only one philosopher, there should be only one fork on the table.
- To prevent philosophers from duplicating forks, you should protect the forks state with a mutex for each of them
