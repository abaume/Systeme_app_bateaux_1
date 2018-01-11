#ifndef ENVOI_DON_H
#define ENVOI_DON_H

#include <string>
using namespace std;

class EnvoiBalise
{
  string m_id;
  int m_y;
  int m_cap;

 public:
  // constructeurs
  EnvoiBalise ()                                   = default;
  EnvoiBalise (const std::string & id, int x, int y, int cap);

  // accesseurs
  std::string   id()     const;
  int  x() const;
  int  y() const;
  int  cap() const;
};

#endif
