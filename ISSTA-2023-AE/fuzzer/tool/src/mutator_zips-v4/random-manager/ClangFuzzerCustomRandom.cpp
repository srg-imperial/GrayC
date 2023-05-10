#include "ClangFuzzerCustomRandom.h"

ClangFuzzerCustomRandom *ClangFuzzerCustomRandom::m_instance = NULL;

void ClangFuzzerCustomRandom::DeleteInstance(const unsigned long _seed) {
	assert(m_instance);
	assert(_seed == m_seed);
	delete m_instance;
	m_instance = NULL;
}
