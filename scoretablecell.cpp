#include "scoretablecell.h"

ScoreTableCell::ScoreTableCell(int pos, int x, int y, Player *player1, Player* player2, Turn* turn, CountScore* count)
{
    this->pos = pos;

    this->count = count;

    this->cell.x = x;
    this->cell.y = y;
    this->cell.w = 90;
    this->cell.h = 30;

    this->player1 = player1;
    this->player2 = player2;
}

void ScoreTableCell::click()
{
    int val = count->countScore(pos);
    if (this->turn->getTurnCount() % 2 == 1) {
        this->player1->setScoreTable(pos, val);
    }
    else {
        this->player2->setScoreTable(pos, val);
    }
}
