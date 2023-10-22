#ifndef SAMPLER_H
#define SAMPLER_H
#include <random>

static std::random_device rd;
static std::mt19937 rng{rd()};

namespace Sampler
{
    float getSample(float begin, float end)
    {
        static std::uniform_real_distribution<float> uid(begin, end); // random dice
        return uid(rng);                                              // use rng as a generator
    }
}

#endif // SAMPLER_H
