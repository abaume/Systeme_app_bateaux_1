#include <iostream>
#include <cstring>
#include <unistd.h>
#include <cstdlib>
#include <map>
#include <thread>
#include <mutex>
#include "make-sockaddr.h"
#include "EnvoiBalise.h"

using namespace std;

map<string,EnvoiBalise> listeBalise;
struct sockaddr_in information_sur_la_source;

void reception(std::string port){

    // on définit l’adresse locale
    auto adresse_locale = local_socket_address(SOCK_DGRAM, port);

    int socket_UDP = socket(AF_INET, SOCK_DGRAM, 0);
    bind(socket_UDP, (sockaddr *) & adresse_locale, sizeof(adresse_locale));

    //lancement du serveur
    while (true) {
        std::cout << "** Serveur Balises UDP port " << port << std::endl << std::endl;
        EnvoiBalise message;
        //BALISES en UDP
        // reception des coordonées GPS et enregistrement
        //si recois messages de balise
        if (read(socket_UDP, &message, sizeof message) == sizeof message) {
            //sauvegarde de la nouvelle coordonnées GPS
            listeBalise[message.id()]= message;
            std::cout << "** Serveur Balises UDP a receptionné le message de " << message.id() << " en position " << message.x() << " " << message.y() << " et en cap " << message.cap() << std::endl;
        }
    }
}

void envoi(char* argv){

    auto adresse_locale = local_socket_address(SOCK_STREAM, argv);

    //  ECOUTE ET ENVOIE CLIENT en TCP
    int socket_TCP = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    bind(socket_TCP, (sockaddr *) & adresse_locale, sizeof(adresse_locale));
          std::cout << std::endl << "** Serveur Client TCP port " << argv << std::endl;

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
        auto adresse_consultation = remote_socket_address("localhost", SOCK_DGRAM, argv);

        //envoyer la liste de Bateau

        for(auto x : listeBalise){

            int n = sendto(socket_TCP, &x, sizeof x,
                           0,
                           (sockaddr *) &adresse_consultation, sizeof adresse_consultation);
            if (n == sizeof x) {
                std::cout << "Envoi à consultation de la Balise" << std::endl;
            } else {
                std::cout << "Il y a un problème d'envoi pour Balise" << std::endl;
            }

        }

        close (socket_TCP);
        //END IF
    }
}


int main(int argc,  char* argv[])
{
    if (argc != 3) {
        std::cerr << "Usage: " << argv[0] << " port balise, port envoi" << std::endl;
        return EXIT_FAILURE;
    }
    //en deux thread client et balise

    thread recep (reception, argv[1]);
    thread env (envoi, argv[2]);
    recep.join();
    env.join();

    return 0;
}
