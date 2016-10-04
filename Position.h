#ifndef POSITION_H_
#define POSITION_H_



class Position{
	int column,row;
public:
	Position(int rowNew,int columNew);
	Position();
	Position relativityPosition(Position& position);
	Position sum(Position& position);
	int getColumn() const;
	int getRow() const;
	void setColumn(int columnNew);
	void setRow(int rowNew);
	void set(int columnNew,int rowNew);
	void print();
	~Position();
};
#endif /* POSITION_H_ */
