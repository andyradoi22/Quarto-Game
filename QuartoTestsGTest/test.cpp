#include "pch.h"

#include "../Quarto/Piece.h"
#include "../Quarto/Piece.cpp"

TEST(TestCaseName, TestName) {
  //EXPECT_EQ(1, 1);
	Piece piece(Piece::Body::Hollow, Piece::Color::Dark, Piece::Height::Short, Piece::Shape::Square);

	EXPECT_EQ(Piece::Body::Hollow, piece.GetBody());
	EXPECT_TRUE(Piece::Color::Dark == piece.GetColor());
	EXPECT_TRUE(Piece::Height::Short == piece.GetHeight());
	EXPECT_TRUE(Piece::Shape::Square == piece.GetShape());
}