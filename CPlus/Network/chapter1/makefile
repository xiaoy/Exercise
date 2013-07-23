include ../Make.defines
PROGS = tcpserv1 tcpclient1
all:	${PROGS}
tcpserv1:	tcpserv1.o
		${CC} ${CFLAGS} -o $@ tcpserv1.o ${LIBS}

tcpclient1:	tcpclient1.o
		${CC} ${CFLAGS} -o $@ tcpclient1.o ${LIBS}
clean:
		rm -f ${PROGS} ${CLEANFILES}

