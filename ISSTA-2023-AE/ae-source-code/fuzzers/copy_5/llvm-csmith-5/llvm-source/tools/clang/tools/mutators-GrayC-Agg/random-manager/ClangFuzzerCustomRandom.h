#ifndef CLANG_FUZZER_CUSTOM_RANDOM_H
#define CLANG_FUZZER_CUSTOM_RANDOM_H

#include <random>
#include <cassert>

using namespace std;

class ClangFuzzerCustomRandom
{
public:
	static ClangFuzzerCustomRandom* GetInstance(void) { assert(m_instance); return m_instance; }
	static void CreateInstance(const unsigned long _seed, const unsigned int _DICE_SIZE) { assert(!m_instance); m_instance = new ClangFuzzerCustomRandom(_seed, _DICE_SIZE); }

	static void DeleteInstance(const unsigned long _seed);
	virtual ~ClangFuzzerCustomRandom(void) {}
   
	virtual double rnd_probability() { double val = m_dist(m_rng); assert(val >= 0.0 && val <= 1.0); return val; }
	virtual bool rnd_yes_no(const double cut_prob) { return (m_dist(m_rng) < cut_prob); }
	virtual unsigned rnd_dice() { return (m_dice_generator(m_rng) % m_DICE_SIZE); }
	virtual unsigned rnd_dice(unsigned dice_size) { return (m_dice_generator(m_rng) % dice_size); }
	
private:
	static ClangFuzzerCustomRandom *m_instance;
	const unsigned long m_seed;
	const unsigned m_DICE_SIZE;

	std::mt19937 m_rng; // mersenne twister 
	std::uniform_real_distribution<> m_dist;
	std::uniform_int_distribution<> m_dice_generator;

	explicit ClangFuzzerCustomRandom(const unsigned long _seed, const unsigned int _DICE_SIZE)
	: m_seed(_seed), m_DICE_SIZE(_DICE_SIZE), m_rng(m_seed), m_dist(0.0, 1.0), m_dice_generator(0, _DICE_SIZE - 1) { }

	// Don't implement them
	ClangFuzzerCustomRandom(ClangFuzzerCustomRandom const &) = delete;
	void operator=(ClangFuzzerCustomRandom const&) = delete;
};
#endif // End of CLANG_FUZZER_CUSTOM_RANDOM_H
