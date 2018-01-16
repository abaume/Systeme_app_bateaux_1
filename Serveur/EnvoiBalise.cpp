#include "EnvoiBalise.h"

EnvoiBalise::EnvoiBalise (const std::string & id, int x, int y, int cap)
  : m_x {x},
  m_y {y},
  m_cap {cap}
  {
    strncpy(m_id, id.c_str(), TAILLE_MAX);
  }

std::string EnvoiBalise::id() const{
  return { m_id };
}

int  EnvoiBalise::x() const {
  return  m_x ;
}

int  EnvoiBalise::y() const {
  return  m_y ;
}

int  EnvoiBalise::cap() const {
  return  m_cap ;
}
