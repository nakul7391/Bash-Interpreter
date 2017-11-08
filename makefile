TARGET=test.out
SOURCES = bash.c extra.c

all:
		gcc ${SOURCES} -o ${TARGET}

clean:
		rm ${TARGET}
