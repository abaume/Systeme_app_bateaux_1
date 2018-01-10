#include <iostream>
#include <cstring>
#include <unistd.h>
#include <cstdlib>
#include <map>
#include "make-sockaddr.h"
#include "EnvoiBalise.h"


using namespace std;

int main(int argc,  char* argv[])
{
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " port" << std::endl;
        return EXIT_FAILURE;
    }

    auto adresse_locale = local_socket_address(SOCK_DGRAM, argv[1]);

    if(fork() == 0) {
        //BALISES en UDP
        // reception des coordonées GPS et enregistrement


        int socket_UDP = socket(AF_INET, SOCK_DGRAM, 0);

        bind(socket_UDP, (sockaddr *) & adresse_locale, sizeof(adresse_locale));

        std::cout << "** Serveur Balises UDP port " << argv[1] << std::endl;
        map listeBalise<string,EnvoiBalise>= new map<string,EnvoiBalise>;
        //lancement du serveur
        while (true) {
            EnvoiBalise message;
            if (read(socket_UDP, &message, sizeof message) == sizeof message) {
                //lecture du mesage  //sauvegarde de la nouvelle coordonnées GPS
                listeBalise.insert(message.nom(),message);


            }
        }
    }

    if(fork() == 0) {
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




                //IF connection OK

                //transmission des position avec sendto()
                auto adresse_consultation = remote_socket_address("localhost", SOCK_DGRAM, argv[2]);

                //envoyer la liste de Bateau

                int n = sendto(socket_TCP, &m, sizeof m,
                               0,
                               (sockaddr *) &adresse_consultation, sizeof adresse_consultation);
                if (n == sizeof m) {
                    std::cout << "Envoi à consultation" << std::endl;
                } else {
                    std::cout << "Il y a un problème d'envoi" << std::endl;
                }
                close (socket_TCP);
                //END IF
            }


        }
    }


    return 0;
}

