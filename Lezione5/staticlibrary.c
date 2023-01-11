/* in order to create a dynamic library you can use
* the command ar command in gcc/cc. After that you need
* to create an index for your lib using the command ranlib. */

/* Example: */
/* gcc -c *.c
* ar rlv libsomething.a *.o (means that all .o files are all
* joined in "libsomething.a")
* ranlib libsomething.a (creates the index) */

/* To use the library we just created, we just need to use
* the following parameter in gcc:
* gcc -L/your/dir -lsomething */ //-l allows to match any string with something

