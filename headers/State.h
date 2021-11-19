#ifndef CHESS_V2_STATE_H
#define CHESS_V2_STATE_H


class State {

private:

public:
    virtual void init() = 0;
    virtual void handleInput() = 0;
    virtual void update() = 0;
    virtual void draw() = 0;

};

#endif //CHESS_V2_STATE_H
