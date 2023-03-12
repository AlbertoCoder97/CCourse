#Change LINUX to false when on Windows.
LINUX = "true"
#LINUX = "false"
SHAREDMEM = sharedMemory.c

sharedmem: $(SEMAPHORES)
ifeq ($(LINUX), "true")
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@.out $(SHAREDMEM)
	./$@.out
else
	gcc $(CFLAGS) $(LDFLAGS) -o $@.exe $(SHAREDMEM)
	./$@.exe
endif

clear:
	rm -rf *.out