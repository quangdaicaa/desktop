from twisted.internet import reactor, protocol
from twisted.internet.protocol import ServerFactory
from twisted.internet.endpoints import TCP4ServerEndpoint

class Server(protocol.Protocol):
  def __init__(self, users):
    self.users = users

  def connectionMade(self):
    print('New connection')
    self.transport.write('Hello from server'.encode('utf-8'))

  def dataReceived(self, data:bytes):
    self.transport.write(data)


class ServFac(ServerFactory):
  def __init__(self):
    self.users = []

  def buildProtocol(self, addr):
    return Server(self.users)

if __name__ == '__main__':
  endpoint = TCP4ServerEndpoint(reactor, 2000)
  endpoint.listen(ServFac())
  reactor.run()