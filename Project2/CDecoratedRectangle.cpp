#include "CDecoratedRectangle.h"
#include "Header.h"

inline float CDecoratedRectangle::perimeter() const
{
	return (2 * height()) + (2 * width());
}

inline float CDecoratedRectangle::square() const
{
	return height() * width();
}

inline float CDecoratedRectangle::height() const
{
	return m_shapePointer->getSize().y;
}

inline float CDecoratedRectangle::width() const
{
	return m_shapePointer->getSize().x;
}

inline std::shared_ptr<sf::RectangleShape> CDecoratedRectangle::createShape(const sf::Vector2f& p1, const sf::Vector2f& p2)
{
	if ((p1.x == p2.x) && (p1.y == p2.y))
	{
		throw std::invalid_argument("points of rectangle cannot be in the same coordinate");
	}
	sf::RectangleShape rectangle;
	rectangle.setPosition(p1);
	rectangle.setSize(sf::Vector2f(p2.x - p1.x, p2.y - p1.y));
	rectangle.setFillColor(CShapeColors::randomColor()); // CShapeColors::randomColor()
	return std::make_shared<sf::RectangleShape>(rectangle);
}

inline std::string CDecoratedRectangle::toString() const
{
	return "RECTANGLE: P=" + std::to_string(perimeter()) + "; S=" + std::to_string(square());
}

inline size_t CDecoratedRectangle::getPointCount() const
{
	return m_shapePointer->getPointCount();
}

inline sf::Vector2f CDecoratedRectangle::getPoint(size_t size) const
{
	return m_shapePointer->getPoint(size);
}

inline std::shared_ptr<sf::Shape> CDecoratedRectangle::getShape() const
{
	return m_shapePointer;
}

inline std::shared_ptr<CShapeDecorator> CDecoratedRectangle::getShapeDecorator()
{
	return std::make_shared<CDecoratedRectangle>(*this);
}
