# this is a chat server

import socket
import time

HOST = ''
PORT = 21567
BUFFSIZE = 2048
ADDR = (HOST, PORT)

s_sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s_sock.bind(ADDR)
s_sock.listen(5)

while True:
    print "waiting connect..."
    c_sock, addr = s_sock.accept()

    while True:
        data = c_sock.recv(BUFFSIZE)
        if not data:
            break
        c_sock.send("[%s] %s" % (time.ctime(), data))
    c_sock.close()

s_sock.close()
