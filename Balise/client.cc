#include <iostream>
#include <cstring>
#include <unistd.h>

#include "make-sockaddr.h"
#include "EnvoiDon.h"

int myrand(int a, int b)
{
    return a + random() % (b-a+1);
}

string nomBateau()
{
    string nomBateau;
    switch (getpid()%7){
    case 0:
        nomBateau = "La Teste de Buch";
        break;
    case 1:
        nomBateau = "Bordeaux";
        break;
    case 2:
        nomBateau = "Villenave d'Ornon";
        break;
    return nomBateau;
}

int main(int argc,  char* argv[])
{
  int PosX1 = 0;
  int PosX2 = 0;
  int PosX3 = 0;
  int PosY1 = 0;
  int PosY2 = 0;
  int PosY3 = 0;

  if (argc != 7) {
    std::cerr << "Usage: " << argv[0]
	      << " serveur, port, idbalise, position X et Y, et cap" << std::endl;
    return EXIT_FAILURE;
  }
  auto adresse_serveur = remote_socket_address(argv[1], SOCK_DGRAM, argv[2]);
  int fd = socket(AF_INET, SOCK_DGRAM, 0);

  for (int j=1 ; j<3 ; j++)
    {
        pid_t p = fork();
        srandom(getpid());
        if (p == 0) {
                b.nom = nomBateau();
                cout << "le bateau de " << nomBateau() << " est parti" << endl;
                for (int )
                PosX1 += myrand(1,4);
                PosY1 += myrand(1,4);
                EnvoiBalise m (argv[4], atoi(PosX), atoi(PosY), atoi(argv[7]));
                sleep(myrand(1,3));
            int status;
            pid_t p = wait(&status);
            if (!WEXITSTATUS(status))
                cout << "le bateau de " << nomBateau() << " est arrivé !"<< endl;
            exit(EXIT_SUCCESS);
        }
    }

  // on n'envoie qu'un message, le plus simple est d'utiliser sendto()

  int n = sendto(fd, &m, sizeof m,
		 (sockaddr *) &adresse_serveur, sizeof adresse_serveur);
  if (n == sizeof m) {
    std::cout << "C'est parti" << std::endl;
  } else {
    std::cout << "problème d'envoi" << std::endl;
  }
  close (fd);
}
