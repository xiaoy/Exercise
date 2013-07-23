include ../Make.defines

PROGS = tcpserv1 tcpcli1
all:	${PROGS}

tcpserv1 : tcpserv1.o
	${CC} ${CFLAGS} -o $@ $< ${LIBS}
tcpcli1: tcpcli1.o
	${CC} ${CFLAGS} -o $@ $< ${LIBS}

clean:
	rm -f ${PROGS} ${CLEANFILES}
