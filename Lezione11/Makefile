#Change LINUX to false when on Windows.
LINUX = "true"

PIPES = pipes.c

pipes: $(PIPES)
ifeq ($(LINUX), "true")
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@.out $(PIPES)
	./$@.out
else
	gcc $(CFLAGS) $(LDFLAGS) -o $@.exe $(PIPES)
	./$@.exe
endif