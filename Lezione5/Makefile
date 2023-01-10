FILES = make.c
CONDITIONALS = conditionals.c
LOOP = loops.c

compile: $(FILES)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@.out $(FILES)

conditionals: $(CONDITIONALS)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@.out $(CONDITIONALS)

loop: $(LOOP)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@.out $(LOOP)
	./$@.out