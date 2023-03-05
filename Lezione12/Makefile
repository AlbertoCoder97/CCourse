#Change LINUX to false when on Windows.
LINUX = "true"
#LINUX = "false"
SEMAPHORES = semaphores.c

semaphores: $(SEMAPHORES)
ifeq ($(LINUX), "true")
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@.out $(SEMAPHORES)
	./$@.out
else
	gcc $(CFLAGS) $(LDFLAGS) -o $@.exe $(SEMAPHORES)
	./$@.exe
endif

clear:
	rm -rf semaphores.out