# this program is used to send and receive info from server

from socket import *

HOST = 'localhost'
PORT = 21567
BUFFSIZE = 1024
ADDR = (HOST, PORT)


while True:
    tcp_c_socket = socket(AF_INET, SOCK_STREAM)
    tcp_c_socket.connect(ADDR)
    data = raw_input('> ')
    if not data:
        break

    tcp_c_socket.send('%s\r\n' % data)
    data = tcp_c_socket.recv(BUFFSIZE)
    if not data:
        break

    print data.strip()
    tcp_c_socket.close()
