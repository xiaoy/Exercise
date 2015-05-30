# this program is used to send and receive info from server

from socket import *

HOST = 'localhost'
PORT = 21567
BUFFSIZE = 1024
ADDR = (HOST, PORT)

tcp_c_socket = socket(AF_INET, SOCK_STREAM)
tcp_c_socket.connect(ADDR)

while True:
    data = raw_input('> ')
    if not data:
        break

    tcp_c_socket.send(data)
    data = tcp_c_socket.recv(BUFFSIZE)
    if not data:
        break

    print data

tcp_c_socket.close()
