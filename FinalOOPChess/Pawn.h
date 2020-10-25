#include "Piece.h"
#include "Player.h"
#include <iostream>
class Pawn : public Piece
{
	Player p_owner;
	int p_id;
	Pawn(Player ownert, int id) : Piece{ ownert, id } {
	};
};
