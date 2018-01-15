#ifndef ENVOI_BALISE_H
#define ENVOI_BALISE_H

#include <string>
#include <arpa/inet.h>
#include <cstring>

class EnvoiBalise
{
  static const int TAILLE_MAX = 10;
  char m_id[TAILLE_MAX];  // tableau de caractères
  int m_x;
  int m_y;
  int m_cap;

 public:
  // constructeurs
  EnvoiBalise ()                                   = default;
  EnvoiBalise (const std::string & id, int x, int y, int cap);

  // accesseurs
  std::string   id()     ;
  int  x() const;
  int  y() const;
  int  cap() const;
};

#endif
