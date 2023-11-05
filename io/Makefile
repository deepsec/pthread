CC := gcc
CFLAGS := -Wall -g -D__DEEPDBG__ -D_FILE_OFFSET_BITS=64
INCLUDE := -I. -I../common
LIBS := -L/usr/local/lib -L/usr/lib -L. -L../common -pthread

COMMON_SRCS := ../common/error.c
COMMON_OBJS := $(subst .c,.o, $(COMMON_SRCS))

EXEC := fcopy

all: $(EXEC)
	
copy: copy.o $(COMMON_OBJS)
	$(CC) $(CFLAGS) $(INCLUDE) -o $@ $^ $(LIBS)

fcopy: fcopy.o $(COMMON_OBJS)
	$(CC) $(CFLAGS) $(INCLUDE) -o $@ $^ $(LIBS)

testso: test.o
	$(CC) $(CFLAGS) $(INCLUDE) -o $@ $^ $(LIBS) -ldeepcommon

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@ 





.PHONY: all clean
clean:
	@rm -f *.o lib*.so lib*.a $(EXEC) $(COMMON_OBJS)


## file dependency
../common/error.o: ../common/error.c ../common/error.h
