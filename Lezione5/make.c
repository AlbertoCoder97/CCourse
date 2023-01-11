/* Make is a very useful tool in order to compile big projects. */
/* Tip for project: do multiple files instead 
* of one file and use multiple .h files */

/* If you split your program in multiple files, you will have
* multiple dependencies. If you change one, you need to recompile
* everything. This becomes very annoying rather quickly. */

/* make maintains dependency graphs, based on modification times.
* The command make [-f makefile] [target] will look for the
* file "Makefile" (or the file specified in the -f flag) 
* which contains rules/commands.
* IMPORTANT: make uses TABS, NOT SPACES. */

/* $(CC) contains the default compiler's name.
* $(CFLAGS) contain the common flags for compilations.
* $(LDFLAGS) Extra flags to give to compilers when they are supposed to invoke the linker.
* $@ The file name of the target of the rule.
* $(OBJ)/$(<NAME>) is a variable that can expand in multiple elements. */

/* Environment variables can be used in make. 
* You can also create variables.*/

int main()
{
    return 0;
}