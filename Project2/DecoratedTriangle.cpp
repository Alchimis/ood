#include "DecoratedTriangle.h"

inline float CDecoratedTriangle::perimeter() const
{
	return a() + b() + c();
}

inline float CDecoratedTriangle::square() const
{
	float d = perimeter() / 2;
	return std::sqrt(d * (d - a()) * (d - b()) * (d - c()));
}

inline float CDecoratedTriangle::a() const
{
	return distanceBetweenPoints(m_shapePointer->getPoint(0), m_shapePointer->getPoint(1));
}

inline float CDecoratedTriangle::b() const
{
	return distanceBetweenPoints(m_shapePointer->getPoint(1), m_shapePointer->getPoint(2));
}

inline float CDecoratedTriangle::c() const
{
	return distanceBetweenPoints(m_shapePointer->getPoint(0), m_shapePointer->getPoint(2));
}

inline std::shared_ptr<sf::ConvexShape> CDecoratedTriangle::createShape(const sf::Vector2f& p1, const sf::Vector2f& p2, const sf::Vector2f& p3)
{
	if ((p1 == p2) || (p2 == p3))
	{
		throw std::invalid_argument("points can't be in same coordinate");
	}
	auto a = distanceBetweenPoints(p1, p2);
	auto b = distanceBetweenPoints(p2, p3);
	auto c = distanceBetweenPoints(p1, p3);
	if ((a + b <= c) || (b + c <= a) || (c + a <= b))
	{
		throw std::invalid_argument("triangle are incorect");
	}
	sf::ConvexShape triangle;
	triangle.setPointCount(3);
	triangle.setPoint(0, p1);
	triangle.setPoint(1, p2);
	triangle.setPoint(2, p3);
	triangle.setFillColor(CShapeColors::randomColor());
	return std::make_shared<sf::ConvexShape>(triangle);
}

inline double CDecoratedTriangle::distanceBetweenPoints(const sf::Vector2f& p1, const sf::Vector2f& p2)
{
	return std::sqrt(((p1.x - p2.x) * (p1.x - p2.x)) + ((p1.y - p2.y) * (p1.y - p2.y)));
}

inline std::string CDecoratedTriangle::toString() const
{
	return "TRIANGLE: P=" + std::to_string(perimeter()) + "; S=" + std::to_string(square());
}

inline size_t CDecoratedTriangle::getPointCount() const
{
	return m_shapePointer->getPointCount();
}

inline sf::Vector2f CDecoratedTriangle::getPoint(size_t size) const
{
	return m_shapePointer->getPoint(size);
}

inline std::shared_ptr<CShapeDecorator> CDecoratedTriangle::getShapeDecorator()
{
	return std::make_shared<CDecoratedTriangle>(*this);
}

inline std::shared_ptr<sf::Shape> CDecoratedTriangle::getShape() const
{
	return m_shapePointer;
}
/*
CIRCLE: C=100,100;R=50
TRIANGLE: P1=300,300;P2=400,400;P3=400,300;
RECTANGLE: P1= 700,700;P2 =600,600;
*/