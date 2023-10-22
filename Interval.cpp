#include "Interval.hpp"

Interval::Interval(Vertex *p_initial, Vertex *p_final, State state)
{
    this->p_initial = p_initial;
    this->p_final = p_final;
    this->state = state;
}
void Interval::setFinal(Vertex *_final)
{
    p_final = _final;
}

void Interval::setInitial(Vertex *_initial)
{
    p_initial = _initial;
}

void Interval::setState(State _state)
{
    state = _state;
}

Vertex *Interval::getFinal()
{
    return p_final;
}

Vertex *Interval::getInitial()
{
    return p_initial;
}

State Interval::getState()
{
    return state;
}

bool Interval::isIncludedIn(Interval *interval)
{
    return (this->getInitial() >= interval->getInitial() && this->getFinal() <= interval->getFinal());
}
