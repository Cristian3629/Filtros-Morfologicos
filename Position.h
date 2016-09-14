#ifndef POSITION_H_
#define POSITION_H_

#include <iostream> //cout


class Position{
	int column,row;
public:
	Position(int rowNew,int columNew);
	Position relativityPosition(Position& position);
	Position sum(Position& position);
	int getColumn();
	int getRow();
	~Position();
};
#endif /* POSITION_H_ */
