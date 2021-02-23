#pragma once

#include "Board.h"
#include "UnusedPieces.h"

#include <string>

class Player
{
public:
	Player(const std::string& name);

	Piece PickPiece(std::istream& in, UnusedPieces& unusedPieces) const;
	void PlacePiece(std::istream& in, Piece&& piece, Board& board) const;

	friend std::ostream& operator << (std::ostream& os, const Player& player);

private:
	std::string m_name;
};
