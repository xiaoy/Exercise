# this program is used to udp server

from socket import *
from time import ctime

HOST = ""
PORT = 21567
BUFFSIZE = 1024
ADDR = (HOST, PORT)

udp_s_socket = socket(AF_INET, SOCK_DGRAM)
udp_s_socket.bind(ADDR)

while True:
    print 'waiting for message...'
    data, addr = udp_s_socket.recvfrom(BUFFSIZE)
    msg = str.format("[{0}] {1}", ctime(), data)
    udp_s_socket.sendto(msg, addr)

    print '...receive from and return to ', addr

udp_s_socket.close()
