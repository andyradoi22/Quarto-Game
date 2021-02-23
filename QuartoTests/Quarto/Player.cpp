#include "Player.h"

Player::Player(const std::string& name)
	: m_name(name)
{
}

Piece Player::PickPiece(std::istream& in, UnusedPieces& unusedPieces) const
{
	std::string pickedPieceName;
	in >> pickedPieceName;
	Piece pickedPiece = unusedPieces.PickPiece(pickedPieceName);
	return pickedPiece;
}

void Player::PlacePiece(std::istream& in, Piece&& piece, Board& board) const
{
	uint16_t line = UINT16_MAX;
	uint16_t column = UINT16_MAX;

	if (in >> line)
	{
		if (in >> column)
		{
			board[{line, column}] = std::move(piece);

			return;
			//we could also return the position, if we need it outside, instead of void;
		}
	}

	throw "Please enter only two numbers from 0 to 3.";
}

std::ostream& operator<<(std::ostream& os, const Player& player)
{
	return os << player.m_name;
}
