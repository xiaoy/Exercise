# this client is use udp protocol to send data

from socket import *


HOST = "localhost"
PORT = 21567
BUFFSIZE = 1024
ADDR = (HOST, PORT)

udp_c_socket = socket(AF_INET, SOCK_DGRAM)

while True:
    data = raw_input(' >')
    if not data:
        break
    udp_c_socket.sendto(data, ADDR)

    data, ADDR = udp_c_socket.recvfrom(BUFFSIZE)
    if not data:
        break
    print data

udp_c_socket.close()
