#include "player.h"

Player::Player()
{
    for(int i = 0; i < 14; i++) {
        this->scoreTable[i] = -1;
    }
}

void Player::resetScore()
{
    for(int i = 0; i < 14; i++) {
        this->scoreTable[i] = -1;
    }

    this->score = 0;
}

int Player::getScoreTable(int i)
{
    return this->scoreTable[i];
}

int Player::getScore()
{
    return this->score;
}

