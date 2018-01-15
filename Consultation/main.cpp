#include <iostream>
#include <cstring>
#include <unistd.h>
#include "make-sockaddr.h"
#include <string>
#include "EnvoiBalise.h"

using namespace std;

int main(int argc,  char* argv[])
{
  if (argc != 3) {
    std::cerr << "Usage: " << argv[0]
          << " serveur port" << std::endl;
    return EXIT_FAILURE;
  }
  auto adresse_serveur = remote_socket_address(argv[1], SOCK_DGRAM, argv[2]);

//-family définit la famille du socket. Les valeurs principales sont AF_INET pour un socket IPv4, AF_INET6 pour un support IPv6.
//-type spécifie le type de socket. Les valeurs principales utilisées sont SOCK_STREAM pour TCP, SOCK_DGRAM pour UDP.
//-protocol définit le protocole à utiliser. Il sera dépendant du type de socket et de sa famille. Les valeurs principales sont IPPROTO_TCP pour un socket TCP, IPPROTO_UDP pour un socket UDP.

  int connect(int sockfd, struct sockaddr *serv_addr, socklen_t addrlen);
  int fd = socket(AF_INET, SOCK_STREAM, 0);
  EnvoiBalise m;

  if (read(fd, &m, sizeof m) == sizeof m) {
        std:string identifiant = m.id();
        int x = m.x();
        int y = m.y();
        int cap = m.cap();
        std::cout << "Bateau " << identifiant
          << " se trouve en " <<  x << " x "
          << y << " y " << cap
          << std::endl;
      }


  close (fd);
}
