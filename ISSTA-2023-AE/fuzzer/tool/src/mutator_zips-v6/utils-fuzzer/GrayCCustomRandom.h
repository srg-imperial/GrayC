/* ******************************************************************

Class: GrayCCustomRandom
Random generator for the mutators of the fuzzers and main.
We use Libfuzzer's seed and std::mt19937 32-bit pseudo-random number
generator (Mersenne twister algorithm) to uniformly random real and
integer (dice) numbers. We use randomization when deciding which
mutation to activate each cycle and how to apply a mutation.
We run the fuzzer with different seeds each time via Libfuzzer's
--seed options.

Use constants in GrayCAggressivenessConsts.h to control the
aggressiveness of mutators

Methods:

CreateInstance -
GetInstance -
DeleteInstance -

rnd_probability -
rnd_yes_no -
rnd_dice -
rnd_dice(unsigned dice_size) -

******************************************************************/

#ifndef GRAYC_CUSTOM_RANDOM_H
#define GRAYC_CUSTOM_RANDOM_H

#include "GrayCAggressivenessConsts.h"
#include <cassert>
#include <random>

using namespace std;

class GrayCCustomRandom {
public:
  static GrayCCustomRandom *GetInstance(void) {
    assert(m_instance);
    return m_instance;
  }
  static void CreateInstance(const unsigned long _seed,
                             const unsigned int _DICE_SIZE) {
    assert(!m_instance);
    m_instance = new GrayCCustomRandom(_seed, _DICE_SIZE);
  }

  static void DeleteInstance(const unsigned long _seed);
  virtual ~GrayCCustomRandom(void) {}

  virtual double rnd_probability() {
    double val = m_dist(m_rng);
    assert(val >= 0.0 && val <= 1.0);
    return val;
  }
  virtual bool rnd_yes_no(const double cut_prob) {
    return (m_dist(m_rng) < cut_prob);
  }
  virtual unsigned rnd_dice() {
    return (m_dice_generator(m_rng) % m_DICE_SIZE);
  }
  virtual unsigned rnd_dice(unsigned dice_size) {
    return (m_dice_generator(m_rng) % dice_size);
  }

private:
  static GrayCCustomRandom *m_instance;
  const unsigned long m_seed;
  const unsigned m_DICE_SIZE;

  std::mt19937 m_rng; // mersenne twister
  std::uniform_real_distribution<> m_dist;
  std::uniform_int_distribution<> m_dice_generator;

  explicit GrayCCustomRandom(const unsigned long _seed,
                             const unsigned int _DICE_SIZE)
      : m_seed(_seed), m_DICE_SIZE(_DICE_SIZE), m_rng(m_seed), m_dist(0.0, 1.0),
        m_dice_generator(0, _DICE_SIZE - 1) {}

  // Don't implement them
  GrayCCustomRandom(GrayCCustomRandom const &) = delete;
  void operator=(GrayCCustomRandom const &) = delete;
};
#endif // End of GRAYC_CUSTOM_RANDOM_H
