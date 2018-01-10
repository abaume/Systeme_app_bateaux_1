#include "EnvoiBalise.h"
#include <arpa/inet.h>
#include <cstring>

EnvoiBalise::EnvoiBalise (const std::string & id, int x, int y, int cap)
  : m_x {x},
  m_y {y},
  m_cap {cap}
  {
    strncpy(m_id, id.c_str(), TAILLE_MAX);
  }

std::string EnvoiBalise::id() const {
  return { m_id };
}

int  EnvoiBalise::x() const {
  return  ntohl(m_x) ;
}

int  EnvoiBalise::y() const {
  return  ntohl(m_y) ;
}

int  EnvoiBalise::cap() const {
  return  ntohl(m_cap) ;
}
