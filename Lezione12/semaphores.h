/*
* Semaphores are a resource used for "signaling".
* If a process is waiting for a <signal>, it is suspended until that <signal> is sent.
* <wait> and <signal> operations cannot be interrupted (they are atomic).
* Queue is used to hold processes waiting on semaphores.
*/

//DO NOT USE POSIX SEMAPHORES. Use the systemfiles semaphores we study in class!

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