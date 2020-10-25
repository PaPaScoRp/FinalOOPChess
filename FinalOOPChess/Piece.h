#pragma once
#include "Board.h"
#include "Player.h"
#include "Position.h"
class Piece
{
public:
	/* Return the owner of the piece. */
	Player owner() const;

	/* Return the id of the piece. */
	int id() const;

	/* Return an integer representing move validity, >= 0 valid, < 0 invalid.
	This method implements generic logic to check for a valid move. */
	virtual int validMove(Position start, Position end, const Board& board) const;

	/* Return 1 if the move is blocked by other pieces, 0 if not. */
	int handleBlock(Position start, Position end, const Board& board) const;

protected:
	/* Owner of a piece. */
	Player m_owner;

	/* Id of a piece. */
	int m_id;

	/* Constructs a piece with a specified owner. */
	Piece(Player owner, int id) : m_owner(owner), m_id(id) {}
};

