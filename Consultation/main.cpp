#include <iostream>
#include <cstring>
#include <unistd.h>
#include "make-sockaddr.h"
#include <vector>
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

        auto adresse_serveur = remote_socket_address(argv[1], SOCK_STREAM, argv[2]);

        //-family définit la famille du socket. Les valeurs principales sont AF_INET pour un socket IPv4, AF_INET6 pour un support IPv6.
        //-type spécifie le type de socket. Les valeurs principales utilisées sont SOCK_STREAM pour TCP, SOCK_DGRAM pour UDP.
        //-protocol définit le protocole à utiliser. Il sera dépendant du type de socket et de sa famille. Les valeurs principales sont IPPROTO_TCP pour un socket TCP, IPPROTO_UDP pour un socket UDP.

        int connect(int sockfd, struct sockaddr *adresse_serveur, socklen_t addrlen);
        int sockfd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

        vector<EnvoiBalise> liste_bateaux;
        EnvoiBalise balise;
        while (read(sockfd, &balise, sizeof balise) == sizeof balise) {
            liste_bateaux.push_back(balise);
        }

        for(auto m:liste_bateaux)
        {
            std::cout << "Bateau " << m.id()
                      << " se trouve en " <<  m.x() << " x "
                      << m.y() << " y et va dans la direction " << m.cap()
                      << std::endl;
        }

        close (sockfd);

}
