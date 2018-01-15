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



    //en deux thread client et balise



    map<string,EnvoiBalise> listeBalise;
    struct sockaddr_in information_sur_la_source;

    // on définit l’adresse locale
    auto adresse_locale = local_socket_address(SOCK_DGRAM, argv[1]);
    int socket_UDP = socket(AF_INET, SOCK_DGRAM, 0);
    bind(socket_UDP, (sockaddr *) & adresse_locale, sizeof(adresse_locale));


    //lancement du serveur
    while (true) {
        EnvoiBalise message;
        //BALISES en UDP
        // reception des coordonées GPS et enregistrement
        //si recois messages de balise
        if (read(socket_UDP, &message, sizeof message) == sizeof message) {
            //sauvegarde de la nouvelle coordonnées GPS
            listeBalise[message.id()]= message;
        }

        std::cout << "** Serveur Balises UDP port " << argv[1] << std::endl;







        //  ECOUTE ET ENVOIE CLIENT en TCP
        int socket_TCP = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
        bind(socket_TCP, (sockaddr *) & adresse_locale, sizeof(adresse_locale));
              std::cout << "** Serveur Client TCP port " << argv[1] << std::endl;

        //écoute
        if (listen(socket_TCP, 0) == 0){
            //acceptation de la connection
            socklen_t tempo = sizeof(information_sur_la_source);
            int id_de_la_nouvelle_socket=accept(socket_TCP,(struct sockaddr*)&information_sur_la_source,&tempo);
            if(id_de_la_nouvelle_socket<0)
                cout << "Desole, je ne peux pas accepter la session TCP" << endl;
            else
                cout << "naccept      : OK" << endl;
            //CONNECTE !!!

            //ENVOIS DES DONNEES
            //transmission des positions avec sendto()
            auto adresse_consultation = remote_socket_address("localhost", SOCK_DGRAM, argv[2]);

            //envoyer la liste de Bateau

            int n = sendto(socket_TCP, &listeBalise, sizeof listeBalise,
                           0,
                           (sockaddr *) &adresse_consultation, sizeof adresse_consultation);
            if (n == sizeof listeBalise) {
                std::cout << "Envoi à consultation de la Balise" << std::endl;
            } else {
                std::cout << "Il y a un problème d'envoi pour Balise" << std::endl;
            }

            close (socket_TCP);
            //END IF
        }
    }
    return 0;
}

