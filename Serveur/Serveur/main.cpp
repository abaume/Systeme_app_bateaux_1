#include <iostream>
#include <cstring>
#include <unistd.h>
#include <cstdlib>
#include "make-sockaddr.h"

using namespace std;

int main(int argc,  char* argv[])
{
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " port" << std::endl;
        return EXIT_FAILURE;
    }

    //BALISES en UDP
    // reception des coordonées GPS et enregistrement

    auto adresse_locale = local_socket_address(SOCK_DGRAM, argv[1]);
    int socket_UDP = socket(AF_INET, SOCK_DGRAM, 0);

    bind(socket_UDP, (sockaddr *) & adresse_locale, sizeof(adresse_locale));

    std::cout << "** Serveur Balises UDP port " << argv[1] << std::endl;
    //lancement du serveur
    while (true) {
        if (read(socket_UDP, &message, sizeof message) == sizeof message) {
            //lecture du mesage

        }
        //sauvegarde de la nouvelle coordonnées GPS


    }

    //CLIENT en TCP
    // lancement du serveur
    int socket_TCP = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

    bind(socket_TCP, (sockaddr *) & adresse_locale, sizeof(adresse_locale));
    std::cout << "** Serveur Client TCP port " << argv[1] << std::endl;

    while (true) {

        //connection
        if (read(socket_TCP, &connection, sizeof connection) == sizeof connection)
        {
            //reception de tentative de connection

        }


        //transmission des position avec sendto()


    }



    return 0;
}

