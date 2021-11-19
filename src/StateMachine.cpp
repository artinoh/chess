#include "StateMachine.h"

void StateMachine::addState(stateRef newState, bool isReplacing) {
    this->isAdding = true;
    this->isReplacing = isReplacing;
    this->newState = std::move(newState);
}

void StateMachine::removeState() {
    this->isRemoving = true;
}

void StateMachine::processChanges() {
    if (this->isRemoving && !this->states.empty()) {
        this->states.pop_front();
        this->isRemoving = false;
    }
    if (this->isAdding) {
        if (!this->states.empty()) {
            if (this->isReplacing) {
                this->states.pop_front();
            }
        }
        this->states.push_front(std::move(this->newState));
        this->states.front()->init();
        this->isAdding = false;
    }
}

stateRef &StateMachine::getActiveState() {
    return this->states.front();
}
