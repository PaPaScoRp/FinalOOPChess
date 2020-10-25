#pragma once
#include <vector>
#include "Piece.h"
#include "Position.h"
#include "Player.h"
class Board {
public:
	/* Create a piece on the board.
		Returns true if the piece was successfully placed on the board. */
	bool initPiece(int id, Player owner, Position p);


 
	/* Return a pointer to the piece at the specified position,
		if the position is valid and occupied, nullptr otherwise. */
	Piece* getPiece(Position p) const;

	/* Perform a move from the start Position to the end Position.
		The method returns an integer with the status
		>= 0 is success, < 0 is failure.
		This method may handle the parts of moving pieces that
		generalize over different board games. */
	virtual int makeMove(Position start, Position end);

	/* The main gameplay loop. */
	virtual void run();

	/* Return true if the game is over. */
virtual bool gameOver() const = 0; 

Board(int height, int width) {
	m_width = width;
	m_height = height;
}
protected:
	int m_width = 8;
	int m_height = 8;
	/* Current game turn. */
	int m_turn;
	/* Vector containing all the Pieces of the board. */
	std::vector<Piece*> m_pieces;


	/* Functionality for creating a new piece (called by initPiece). */
	Piece* newPiece(int id, Player owner);
};
