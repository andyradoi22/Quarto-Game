#include "pch.h"
#include "CppUnitTest.h"

#include "../Quarto/Piece.h"
//#include "../Quarto/Piece.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace QuartoTests
{
	TEST_CLASS(PieceTests)
	{
	public:
		
		TEST_METHOD(Constructor)
		{
			Piece piece(Piece::Body::Hollow, Piece::Color::Dark, Piece::Height::Short, Piece::Shape::Square);

			Assert::IsTrue(Piece::Body::Hollow == piece.GetBody());
			Assert::IsTrue(Piece::Color::Dark == piece.GetColor());
			Assert::IsTrue(Piece::Height::Short == piece.GetHeight());
			Assert::IsTrue(Piece::Shape::Square == piece.GetShape());
		}

		TEST_METHOD(Print)
		{
			Piece piece(Piece::Body::Full, Piece::Color::Dark, Piece::Height::Short, Piece::Shape::Square);
			std::stringstream stream;
			stream << piece;
			Assert::AreEqual<std::string>("1112", stream.str(), L"If you see this message, piece name is not the same!");
		}
	};
}
