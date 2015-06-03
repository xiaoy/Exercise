# this program use socket to get web content

from socket import *

HOST = "www.python.org"
PORT = 80
BUFFSIZE = 2048
ADDR = (HOST, PORT)

http_sock = socket(AF_INET, SOCK_STREAM)
http_sock.connect(ADDR)

http_sock.send("GET/\n")
data = http_sock.recv(BUFFSIZE)

if data:
    print data
else:
    print "the %s is empty" % HOST

http_sock.close()
