#pragma once
#include "Board.h"
class ChessGame : public Board{
public:
	Position WhiteKingPosition;
	Position BlackKingPosition;

	/* Setup the chess board with its initial pieces. */
	virtual void setupBoard();

	/* Perform a move from the start Position to the end Position.
	The method returns an integer with the status
	>= 0 is success, < 0 is failure. */
	virtual int makeMove(Position start, Position end) override;

	void run() override;
	/* Return 0 if White is checked, 1 if Black is checked, -1 if neither. */
	int check();
	/* Return 1 if a stalemate is reached, 0 if not. */
	int Stalemate();
	/* Return 1 if a checkmate is reached, 0 if not. */
	bool checkMate(int status);
	/* Display the chessboard in terminal. */
	void printBoard();
protected:
	/* 1 if Black is checked, 0 if White is checked, -1 if neither. */
	int m_status;

};

