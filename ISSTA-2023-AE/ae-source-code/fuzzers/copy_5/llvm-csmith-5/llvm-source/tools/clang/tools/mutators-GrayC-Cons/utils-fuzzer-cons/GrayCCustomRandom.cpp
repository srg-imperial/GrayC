#include "GrayCCustomRandom.h"

GrayCCustomRandom *GrayCCustomRandom::m_instance = NULL;

void GrayCCustomRandom::DeleteInstance(const unsigned long _seed) {
  assert(m_instance);
  assert(_seed == m_seed);
  delete m_instance;
  m_instance = NULL;
}
