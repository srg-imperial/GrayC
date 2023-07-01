#include "GrayCRandomManager.h"

GrayCRandomManager *GrayCRandomManager::m_instance = NULL;

void GrayCRandomManager::DeleteInstance(const unsigned long _seed) {
  assert(m_instance);
  delete m_instance;
  m_instance = NULL;
}
