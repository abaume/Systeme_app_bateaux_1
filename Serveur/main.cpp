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
    // on définit l’adresse locale
    auto adresse_locale = local_socket_address(SOCK_DGRAM, argv[1]);
    int socket_UDP = socket(AF_INET, SOCK_DGRAM, 0);
    bind(socket_UDP, (sockaddr *) & adresse_locale, sizeof(adresse_locale));

    map<string,EnvoiBalise> listeBalise1;
    map<string,EnvoiBalise> listeBalise2;
    map<string,EnvoiBalise> listeBalise3;

    //lancement du serveur
    while (true) {
        EnvoiBalise message;
        //BALISES en UDP
        // reception des coordonées GPS et enregistrement
        //si recois messages de balise
        if (read(socket_UDP, &message, sizeof message) == sizeof message) {
            //sauvegarde de la nouvelle coordonnées GPS
            EnvoiBalise identifiant = message.id();
        }
        switch (identifiant)
        {
        case "1":
            listeBalise1.insert(message.id(),message.x(),message.y(),message.cap());
            break;
        case "2":
            listeBalise2.insert(message.id(),message.x(),message.y(),message.cap());
            break;
        case "3":
            listeBalise3.insert(message.id(),message.x(),message.y(),message.cap());
            break;
        }


        //  ECOUTE ET ENVOIE CLIENT en TCP
        int socket_TCP = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
        bind(socket_TCP, (sockaddr *) & adresse_locale, sizeof(adresse_locale));
        //      std::cout << "** Serveur Client TCP port " << argv[1] << std::endl;
        //      std::cout << "** Serveur Balises UDP port " << argv[1] << std::endl;

        //écoute
        if (listen(socket_TCP, 0) = 0){
            //acceptation de la connection
            id_de_la_nouvelle_socket=accept(id_de_la_socket,(struct sockaddr*)&information_sur_la_source,&tempo);
            if(id_de_la_nouvelle_socket==INVALID_SOCKET)
                printf("\nDesole, je ne peux pas accepter la session TCP du a l'erreur : %d",WSAGetLastError());
            else
                printf("\naccept      : OK");
            //CONNECTE !!!

            //ENVOIS DES DONNEES
            //transmission des positions avec sendto()
            auto adresse_consultation = remote_socket_address("localhost", SOCK_DGRAM, argv[2]);

            //envoyer la liste de Bateau

            int n = sendto(socket_TCP, &listeBalise1, sizeof listeBalise1,
                           0,
                           (sockaddr *) &adresse_consultation, sizeof adresse_consultation);
            if (n == sizeof listeBalise1) {
                std::cout << "Envoi à consultation de la Balise 1" << std::endl;
            } else {
                std::cout << "Il y a un problème d'envoi pour Balise 1" << std::endl;
            }

            n = sendto(socket_TCP, &listeBalise2, sizeof listeBalise2,
                           0,
                           (sockaddr *) &adresse_consultation, sizeof adresse_consultation);
            if (n == sizeof listeBalise2) {
                std::cout << "Envoi à consultation de la Balise 2" << std::endl;
            } else {
                std::cout << "Il y a un problème d'envoi pour Balise 2" << std::endl;
            }

            n = sendto(socket_TCP, &listeBalise3, sizeof listeBalise3,
                           0,
                           (sockaddr *) &adresse_consultation, sizeof adresse_consultation);
            if (n == sizeof listeBalise3) {
                std::cout << "Envoi à consultation de la Balise 3" << std::endl;
            } else {
                std::cout << "Il y a un problème d'envoi pour Balise 3" << std::endl;
            }
            close (socket_TCP);
            //END IF
        }
    }
    return 0;
}

