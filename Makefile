
CC=gcc
CFLAGS += -Wall -g3 -O0
CFLAGS += -MMD -MP

a.out :  IntQueue.o IntQueueTest.o
	$(CC) $(CFLAGS) $^ -o $@

.PHONY : clean
clean:
	rm -f a.out *.o *.d

-include *.d
