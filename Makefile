#
# This is free and unencumbered software released into the public domain.
# For details see the UNLICENSE file at the root of the source tree.
#

CC := gcc
TARGET = angry-purple-tiger

INCLUDES = -I.
CSRCS = main.c md5.c

OBJS := $(addsuffix .o, $(basename $(CSRCS)))

all: ${OBJS}
	${CC} ${CCFLAGS} ${OBJS} -o ${TARGET}
	@rm ${OBJS}

clean:
	@rm ${TARGET}

# $@: target files
# $^: all dependence files
# $<: first dependence file
%.o: %.c
	$(CC) $(CCFLAGS) $(INCLUDES) -o $@ -c $<
