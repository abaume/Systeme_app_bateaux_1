#include <iostream>
#include <cstring>
#include <unistd.h>
#include <cstdlib>

#include "make-sockaddr.h"

using namespace std;

int main(int argc,  char* argv[])
{
  if (argc != 3) {
    std::cerr << "Usage: " << argv[0] << " port portConsultation" << std::endl;
    return EXIT_FAILURE;
  }

  auto adresse_locale = local_socket_address(SOCK_DGRAM, argv[1]);
  int fd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

  bind(fd, (sockaddr *) & adresse_locale, sizeof(adresse_locale));
  std::cout << "** Serveur Téléthon TCP port " << argv[1] << std::endl;

  int identifiant;
  int x, y;
  char cap;
  //connexion
  auto adresse_consultation = remote_socket_address("localhost", SOCK_DGRAM, argv[2]);


  while (true) {
    serveur m (identifiant, x, y, cap);

      int n = sendto(fd, &m, sizeof m,
             0,
             (sockaddr *) &adresse_consultation, sizeof adresse_consultation);
      if (n == sizeof m) {
        std::cout << "Envoi à consultation" << std::endl;
      } else {
        std::cout << "Il y a un problème d'envoi" << std::endl;
      }
      close (fd);

  }
}



if (read(fd, &m, sizeof m) == sizeof m) {
    // on récupère le montant envoyé par le client
int montant = m.montant();
