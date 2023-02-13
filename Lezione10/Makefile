#Change LINUX to false when on Windows.
LINUX = "true"
#LINUX = "false"
PROCESSES = processes.c

processes: $(PROCESSES)
ifeq ($(LINUX), "true")
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@.out $(PROCESSES)
	./$@.out
else
	gcc $(CFLAGS) $(LDFLAGS) -o $@.exe $(PROCESSES)
	./$@.exe
endif