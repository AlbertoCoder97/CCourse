#Change LINUX to false when on Windows.
LINUX = "false"
#LINUX = "false"
FILESYSTEM = filesystemImpl.c

filesystem: $(FILESYSTEM)
ifeq ($(LINUX), "true")
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@.out $(FILESYSTEM)
	./$@.out
else
	gcc $(CFLAGS) $(LDFLAGS) -o $@.exe $(FILESYSTEM)
	./$@.exe
endif