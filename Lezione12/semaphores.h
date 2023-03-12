/*
* Semaphores are a resource used for "signaling".
* If a process is waiting for a <signal>, it is suspended until that <signal> is sent.
* <wait> and <signal> operations cannot be interrupted (they are atomic).
* Queue is used to hold processes waiting on semaphores.
*/

//DO NOT USE POSIX SEMAPHORES. Use the System V semaphores we study in class!

/*
* int semget(key_t key, int count, int flag)
* This returns the identifier of the semaphore in the set associated with the key.
* Infact, you do not have only one semaphore, but you have a set of semaphores.
* count is the number of semaphores in the <set>.
* key can be IPC_PRIVATE
* flag can be IPC_CREAT etc...
*/

/*
* Once you have a semaphore set, you can do operations on the semaphores set
* and you can do these operations on one or more semaphore at the same time.
* A system file semaphore can have a value which can be incremented or decremented
* which allows for much more customization than just a set/unset value.
* These operations are ATOMIC, even if they are operations executed on a group of semaphores.
*/

/*
* The function semget returns the identifier of the samephore associated to the key
* and then this id can be used with the funciton semop and pass an array of structure
* and the number of entries in the array, and this array of structures, contains all the operations
* to be executed on this semaphore. Operations can be successful or fail. No in between.
* You can UNDO operations when the process exits via the IPC_UNDO flag!
*/

/*
* Make sure to lock and release semaphores correctly as they can cause deadlocks.
*/

/*
* System V semaphores all have:
*   - Key: resource ID, used to create shared memory segment. You need the key to read/write the source if you have permission to do so.
*   - Creator: UID/GID
*   - Owner: UID/GID
*   - Permissions: r/w/x for owner/group/others
* Resources are persistent, you must explicitly destroy them when you're done!
*/

/*
* Semaphores are used as sync mechanism between co-operating processes.
* They can be used by different processes without any kind of relation.
* You have two ATOMIC operations: <wait> and <signal>.
* A process can wait for a semaphore and another process can signal.
* When a signal arrives, the processes waiting get revived.
*/

/**
 * To manage processes waiting on a semaphore, the OS has multiple keys, one for
 * each semaphore and a process waits on a specific resource with a specific key.
*/

/**
 * To use a semaphore, you need to use semget(key_t key, int count, int flag)
 * You need to specify the key to the semaphore and it returns the ID of the
 * semaphore <set> associated with that key. You need to reuse the ID if you need to request multiple operations.
 * The count tells you the amount of semaphores in the set. You can request multiple semaphores.
 * The flag field allows to specify permissions, like IPC_CREAT etc...
 * The IPC_PRIVATE as flag for key,always gives you a new key.
*/

/**
 * The semop(int semid, struct sembuf *sops, unsigned nsops) call allows you to
 * execute operations on the specified semaphore.
 * The sembuf structure is defined as:
 * struct sembuf {
 *     unsigned short sem_num;
 *     short sem_op;
 *     short sem_flg;
 * }
 * When you put multiple items in the array of operations, all the operations are done
 * atomically following the order in the array. They are completed or nothing is done.
 * If you put IPC_NOWAIT in the sem_flg field, the operation goes on regardless of what happens.
 * This flag can be used to check whether a semaphore is available or not since if you try to get a lock, the nowait just returns instantly in negative case.
 * The flag IPC_UNDO undos the operations when process exits,
 * The sem_op is a short integer which can be positive, negative or zero.
 * If it is positive, the value of sem_op is added to the semaphore's current value.
 * If you try to decrement that value, if the decrementation makes the semaphore go below zero, the operation
 * is blocking since operations aren't allowed to make it go sub zero.
 * If you put 0, the process waits exactly when the value is EXACTLY 0.
*/

/**
 * The semctl(int semid, int snum, int cmd, ...) is the control operation.
 * It allows to destroy a semaphores' set.
 * This performs the operation specified by cmd on the set identified by semid.
 * semctl is NOT atomic.
*/

/**
 * A deadlock is a situation where we have two processes waiting on resources
 * held by the other process. Therefore both processes will keep waiting forever.
 * The only solution is killing one of the two processes.
*/

/**
 * Check the DiningPhilosophers problem with semaphores.
 * Check the Sleeping Barber problem with semaphores.
 * Check the Producer/Consumer problem with semaphores.
 * TIP think of semaphores in the opposite way, where 0 is the "bad" and 1 is the "good"
*/