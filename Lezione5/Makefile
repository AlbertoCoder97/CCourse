FILES = files.c
CONDITIONALS = conditionals.c
LOOP = loops.c

conditionals: $(CONDITIONALS)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@.out $(CONDITIONALS)

loop: $(LOOP)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@.out $(LOOP)
	./$@.out

files: $(FILES)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@.out $(FILES)
	./$@.out