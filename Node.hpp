#ifndef NODE_H
#define NODE_H
#include <concepts>

template <class T>
concept GenericNode = requires(T obj) {
    {
        obj.accessChildren()
    } -> std::same_as<GenericNode>;
    {
        *(obj.parent)
    } -> std::same_as<GenericNode>;
};

template <GenericNode T>
class Node
{
};

#endif // NODE_H