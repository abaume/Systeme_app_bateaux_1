#include "EnvoiDon.h"
#include <arpa/inet.h>
#include <cstring>

EnvoiDon::EnvoiDon (const std::string & id, int x, int y, int cap)
  : m_x {x},
  m_y {y},
  m_cap {cap}
  {
    strncpy(m_id, id.c_str(), TAILLE_MAX);
  }

std::string EnvoiDon::id() const {
  return { m_id };
}

int  EnvoiDon::x() const {
  return  ntohl(m_x) ;
}

int  EnvoiDon::y() const {
  return  ntohl(m_y) ;
}

int  EnvoiDon::cap() const {
  return  ntohl(m_cap) ;
}
