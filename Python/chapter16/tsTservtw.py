# this program is write a tcp server use Twisted

from twisted.internet import protocol, reactor
from time import ctime


PORT = 21567


class TSServerProtocol(protocol.Protocol):
    def connectionMade(self):
        clnt = self.clnt = self.transport.getPeer().host
        print '...connected from:', clnt

    def dataReceived(self, data):
        self.transport.write('[%s] %s' % (ctime(), data))

factory = protocol.Factory()
factory.protocol = TSServerProtocol
print 'wating for connection..'
reactor.listenTCP(PORT, factory)
reactor.run()
