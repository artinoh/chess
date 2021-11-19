#ifndef CHESS_V2_STATEMACHINE_H
#define CHESS_V2_STATEMACHINE_H

#include <memory>
#include <deque>
#include "State.h"

using stateRef = std::unique_ptr<State>;


class StateMachine {

private:
    std::deque<stateRef> states;
    stateRef newState;
    bool isRemoving;
    bool isAdding;
    bool isReplacing;

public:
    StateMachine() = default;
    ~StateMachine() = default;

    void addState(stateRef newState, bool isReplacing = true);
    void removeState();
    void processChanges();

    stateRef& getActiveState();


};


#endif //CHESS_V2_STATEMACHINE_H
