#ifndef NODECONCEPTS_HPP
#define NODECONCEPTS_HPP
#include <concepts>

class SolidNode;
class OpNode;
class TransNode;
class World;

template <class T>
concept isWorld = std::same_as<World, T>;

template <class T>
concept isSolidNode = std::same_as<SolidNode, T>;

template <class T>
concept isOpNode = std::same_as<OpNode, T>;

template <class T>
concept isTransNode = std::same_as<TransNode, T>;

#endif // NODECONCEPTS_HPP
