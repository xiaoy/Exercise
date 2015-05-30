# this is time server

from socket import *
from time import ctime


HOST = ''
PORT = 21567
BUFFSIZE = 1024
ADDR = (HOST, PORT)

tcp_s_socket = socket(AF_INET, SOCK_STREAM)
tcp_s_socket.bind(ADDR)
tcp_s_socket.listen(5)

while True:
    print 'waiting for connection...'
    tcp_c_socket, addr = tcp_s_socket.accept()
    print '...connect from:', addr

    while True:
        data = tcp_c_socket.recv(BUFFSIZE)

        if not data:
            break
        tcp_c_socket.send('[%s] %s' % (ctime(), data))

    tcp_c_socket.close()

tcp_socket.close()
