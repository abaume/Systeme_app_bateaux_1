#ifndef ENVOI_DON_H
#define ENVOI_DON_H

using namespace std;

#include <cstring>
#include <string>

class EnvoiBalise
{
  static const int TAILLE_MAX = 30;
  char m_id[TAILLE_MAX];
  int m_x;
  int m_y;
  int m_cap;

 public:
  // constructeurs
  EnvoiBalise ()                                   = default;
  EnvoiBalise (const std::string & id, int x, int y, int cap);

  // accesseurs
  string   id()     const;
  int  x() const;
  int  y() const;
  int  cap() const;
};

#endif
