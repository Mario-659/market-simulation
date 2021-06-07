#include "Map.h"

Position* Map::getPosition(unsigned int x, unsigned int y)
{
    unsigned i = this->size * y + x;
    return (this -> board[i]);
}

Map::Map(unsigned int size) : size(size)
{
    unsigned boardSize = this->size * this->size;

    this->board.resize(boardSize);


    for (unsigned i = 0; i < boardSize; ++i)
    {
        unsigned x, y;
        x = i % size;
        y = i / size;

        this->board[i] = new Position(x, y);
    }
}

Position::Position(unsigned X, unsigned Y)
{
    this->x = X;
    this->y = Y;
    this->ptr = nullptr;
}

void Position::setPointer(Person *newPtr){ this->ptr = newPtr; }

unsigned int Position::getX(){ return this->x; }

unsigned int Position::getY(){ return this->y; }

Person * Position::getPerson(){ return this->ptr; }

unsigned int Map::getSize(){ return this->size; }

Position* Map::getPosition(unsigned int i){ return board[i]; }

Position::~Position(){ delete this->ptr; }

Map::~Map(){ for(auto pos: this->board) delete pos; }
