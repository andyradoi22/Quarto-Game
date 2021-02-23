#include "Piece.h"

Piece::Piece() :
	Piece(Body::None, Color::None, Height::None, Shape::None)
{
	// Empty
}

Piece::Piece(Body body, Color color, Height height, Shape shape) :
	m_body(body),
	m_color(color),
	m_height(height),
	m_shape(shape)
{
	// Empty
	static_assert(sizeof(*this) <= 1, "This class should be 1 byte in size");
}

Piece::Body Piece::GetBody() const
{
	return m_body;
}

Piece::Color Piece::GetColor() const
{
	return m_color;
}

Piece::Height Piece::GetHeight() const
{
	return m_height;
}

Piece::Shape Piece::GetShape() const
{
	return m_shape;
}

Piece Piece::Intersection(const Piece& other) const
{
	Piece piece = *this;

	if (piece.m_body != other.m_body)
		piece.m_body = Body::None;

	if (piece.m_color != other.m_color)
		piece.m_color = Color::None;

	if (piece.m_height != other.m_height)
		piece.m_height = Height::None;

	if (piece.m_shape != other.m_shape)
		piece.m_shape = Shape::None;

	return piece;
}

bool Piece::HasAnyFeatureSet() const
{
	return
		GetBody() != Piece::Body::None ||
		GetColor() != Piece::Color::None ||
		GetHeight() != Piece::Height::None ||
		GetShape() != Piece::Shape::None;
}

std::ostream& operator<<(std::ostream& os, const Piece& piece)
{
	return os <<
		static_cast<int>(piece.m_body) <<
		static_cast<int>(piece.m_color) <<
		static_cast<int>(piece.m_height) <<
		static_cast<int>(piece.m_shape);
}
