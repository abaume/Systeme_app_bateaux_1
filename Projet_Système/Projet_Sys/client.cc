#include <iostream>
#include <cstring>
#include <unistd.h>

#include "make-sockaddr.h"
#include "EnvoiBalise.h"

int main(int argc,  char* argv[])
{
  if (argc != 7) {
    std::cerr << "Usage: " << argv[0]
	      << " serveur, port, idbalise, position X et Y, et cap" << std::endl;
    return EXIT_FAILURE;
  }
  auto adresse_serveur = remote_socket_address(argv[1], SOCK_DGRAM, argv[2]);
  int fd = socket(AF_INET, SOCK_DGRAM, 0);

  EnvoiBalise m (argv[4], atoi(argv[5]), atoi(argv[6]), atoi(argv[7]));

  // on n'envoie qu'un message, le plus simple est d'utiliser sendto()

  int n = sendto(fd, &m, sizeof m,
		 0,
		 (sockaddr *) &adresse_serveur, sizeof adresse_serveur);
  if (n == sizeof m) {
    std::cout << "C'est parti" << std::endl;
  } else {
    std::cout << "problème d'envoi" << std::endl;
  }
  close (fd);
}
