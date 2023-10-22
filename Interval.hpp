#ifndef INTERVAL_HPP
#define INTERVAL_HPP
#include "Vertex.hpp"
#include <glm/vec3.hpp>

// esse enum é relativo à aresta passada como argumento do setMembership
// pode mudar pra estar em outra classe caso necessario
enum State
{
    IN = 0,
    ON = 1,
    OUT = 2
};

class Interval
{
private:
    Vertex *p_final;
    Vertex *p_initial;
    State state;

public:
    Interval(Vertex *p_initial = new Vertex(), Vertex *p_final = new Vertex(), State state = State::OUT);
    void setFinal(Vertex *_final);
    void setInitial(Vertex *_initial);
    void setState(State _state);
    Vertex *getFinal();
    Vertex *getInitial();
    State getState();
    bool isIncludedIn(Interval *interval);
};
#endif // INTERVAL_HPP