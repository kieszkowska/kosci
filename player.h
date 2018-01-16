#ifndef PLAYER_H
#define PLAYER_H


class Player
{
protected:
    int score = 0;
    unsigned int scoreTable[14];
    enum cell {
        sum1,
        sum2,
        sum3,
        sum4,
        sum5,
        sum6,
        bonus,
        x3,
        x4,
        full,
        sstr,
        lstr,
        x5,
        chance
    };

public:
    Player();
    void resetScore();
    void newGame();
    int setScoreTable(int i, int val);
    int getScoreTable(int i);
    int getScore();
};

#endif // PLAYER_H
