#pragma once

#include "Piece.h"

#include <unordered_map>

class UnusedPieces
{
public:
	UnusedPieces();

	Piece PickPiece(const std::string& pieceName);

	friend std::ostream& operator << (std::ostream& os, const UnusedPieces& board);

private:
	void GenerateUnusedPieces();
	void InsertPiece(const Piece& piece);

private:
	std::unordered_map<std::string, Piece> m_unusedPieces;
};
