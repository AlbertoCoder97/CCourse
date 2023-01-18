#Change LINUX to false when on Windows.
LINUX = "true"
#LINUX = "false"
TEST = test.c

test: $(TEST)
ifeq ($(LINUX), "true")
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@.out $(TEST)
	./$@.out
else
	g++ $(CFLAGS) $(LDFLAGS) -o $@.exe $(TEST)
	./$@.exe
endif