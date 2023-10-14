#ifndef NODECONCEPTS_HPP
#define NODECONCEPTS_HPP
#include <concepts>
// #include "InternalNode.hpp"

// class InternalNode;
template <class T>
concept isSolidNode = std::same_as<SolidNode, T>;

template <class T>
concept isOpNode = std::same_as<OpNode, T>;

template <class T>
concept isTransNode = std::same_as<TransNode, T>;

#endif // NODECONCEPTS_HPP
