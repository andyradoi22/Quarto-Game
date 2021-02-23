#include "UnusedPieces.h"

#include <sstream>
#include <array>
#include <algorithm>

UnusedPieces::UnusedPieces()
{
	GenerateUnusedPieces();
}

Piece UnusedPieces::PickPiece(const std::string& pieceName)
{
	auto piece = m_unusedPieces.extract(pieceName);
	if (piece)
		return std::move(piece.mapped());
	else
		throw "Piece not found";
}

void UnusedPieces::GenerateUnusedPieces()
{
	//const uint8_t kPermutationPoolSize = 8;
	std::array<uint8_t, 8> permutationPool = { 1, 1, 1, 1, 2, 2, 2, 2 };
	//const uint8_t kMaxPermutations = 5;
	//const uint8_t kPermutationSize = 4;

	for (uint8_t currentPermutation = 0; currentPermutation < 5; ++currentPermutation)
	{
		auto itPoolBegin = permutationPool.begin() + currentPermutation;
		//auto itPoolEnd = permutationPool.begin() + currentPermutation + 4;

		do
		{
			Piece piece(
				static_cast<Piece::Body>(*itPoolBegin),
				static_cast<Piece::Color>(*(itPoolBegin + 1)),
				static_cast<Piece::Height>(*(itPoolBegin + 2)),
				static_cast<Piece::Shape>(*(itPoolBegin + 3))
			);

			InsertPiece(piece);
			std::cout << piece << std::endl;

		} while (std::next_permutation(itPoolBegin, itPoolBegin + 4));

		std::cout << "end of loop " << std::endl;
	}

	/*InsertPiece(Piece(Piece::Body::Full, Piece::Color::Dark, Piece::Height::Short, Piece::Shape::Square));
	InsertPiece(Piece(Piece::Body::Full, Piece::Color::Dark, Piece::Height::Short, Piece::Shape::Round));
	InsertPiece(Piece(Piece::Body::Full, Piece::Color::Dark, Piece::Height::Tall, Piece::Shape::Square));
	InsertPiece(Piece(Piece::Body::Full, Piece::Color::Dark, Piece::Height::Tall, Piece::Shape::Round));
	InsertPiece(Piece(Piece::Body::Full, Piece::Color::Light, Piece::Height::Short, Piece::Shape::Square));
	InsertPiece(Piece(Piece::Body::Full, Piece::Color::Light, Piece::Height::Short, Piece::Shape::Round));
	InsertPiece(Piece(Piece::Body::Full, Piece::Color::Light, Piece::Height::Tall, Piece::Shape::Square));
	InsertPiece(Piece(Piece::Body::Full, Piece::Color::Light, Piece::Height::Tall, Piece::Shape::Round));

	InsertPiece(Piece(Piece::Body::Hollow, Piece::Color::Dark, Piece::Height::Short, Piece::Shape::Square));
	InsertPiece(Piece(Piece::Body::Hollow, Piece::Color::Dark, Piece::Height::Short, Piece::Shape::Round));
	InsertPiece(Piece(Piece::Body::Hollow, Piece::Color::Dark, Piece::Height::Tall, Piece::Shape::Square));
	InsertPiece(Piece(Piece::Body::Hollow, Piece::Color::Dark, Piece::Height::Tall, Piece::Shape::Round));
	InsertPiece(Piece(Piece::Body::Hollow, Piece::Color::Light, Piece::Height::Short, Piece::Shape::Square));
	InsertPiece(Piece(Piece::Body::Hollow, Piece::Color::Light, Piece::Height::Short, Piece::Shape::Round));
	InsertPiece(Piece(Piece::Body::Hollow, Piece::Color::Light, Piece::Height::Tall, Piece::Shape::Square));
	InsertPiece(Piece(Piece::Body::Hollow, Piece::Color::Light, Piece::Height::Tall, Piece::Shape::Round));*/
}

void UnusedPieces::InsertPiece(const Piece& piece)
{
	std::stringstream stringStream;
	stringStream << piece;
	m_unusedPieces.insert(std::make_pair(stringStream.str(), piece));
}

std::ostream& operator<<(std::ostream& os, const UnusedPieces& unusedPieces)
{
	os << "Unused pieces : ";
	for (auto it : unusedPieces.m_unusedPieces)
	{
		os << it.first << " ";
	}
	os << std::endl;

	return os;
}
