
#include "Intersection.hpp"

void Intersection::apply(VertexList &vlist1, VertexList &vlist2, VertexList &result)
{
    int i = 1;
    int j = 1;

    while (i < vlist1.getVertexList()->size() && j < vlist2.getVertexList()->size())
    {
        if (vlist1.getVertexList()->at(i) < vlist2.getVertexList()->at(j))
        {
            result.addVertex(vlist1.getVertexList()->at(i));
            i++;
        }
        else if (vlist1.getVertexList()->at(i) > vlist2.getVertexList()->at(j))
        {
            result.addVertex(vlist2.getVertexList()->at(j));
            j++;
        }
        else
        {
            result.addVertex(vlist1.getVertexList()->at(i));
            result.addVertex(vlist2.getVertexList()->at(j));
            i++;
            j++;
        }
    }

    if (i < vlist1.getVertexList()->size())
    {
        for (int k = i; k < vlist1.getVertexList()->size(); k++)
        {
            result.addVertex(vlist1.getVertexList()->at(k));
        }
    }

    else
    {
        for (int k = j; k < vlist2.getVertexList()->size(); k++)
        {
            result.addVertex(vlist2.getVertexList()->at(k));
        }
    }

    for (int k = 0; k < result.getVertexList()->size() - 1; k++)
    {
        if (result.getVertexList()->at(k).getSmsPair()->second != State::ON && result.getVertexList()->at(k + 1).getSmsPair()->first != State::ON)
        {
            State finalState = classify(result.getVertexList()->at(k).getSmsPair()->second, result.getVertexList()->at(k + 1).getSmsPair()->first, result.getVertexList()->at(k).getSolid(), result.getVertexList()->at(k + 1).getSolid());
            result.getVertexList()->at(k).updateSmsPair(2, finalState);
            result.getVertexList()->at(k + 1).updateSmsPair(1, finalState);
        }
    }
}

State Intersection::classify(State &s1, State &s2, Solid *l1, Solid *l2)
{
    if (l1 == l2)
    {
        return State::OUT;
    }
    if (s1 == State::IN && s2 == State::IN)
    {
        return State::IN;
    }
    return State::OUT;
}
