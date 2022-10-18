#include "CDecoratedCircle.h"
#define _USE_MATH_DEFINES
#include "Header.h"
#include <format>
#include <iostream>
#include <math.h>
#include <string>
#include <string_view>

inline float CDecoratedCircle::perimeter() const
{
	auto radius = this->radius();
	return radius * 2 * M_PI;
}

inline float CDecoratedCircle::square() const
{
	auto radius = this->radius();
	return radius * radius * M_PI;
}

inline float CDecoratedCircle::radius() const
{
	return m_shapePointer->getRadius();
}

inline sf::Vector2f CDecoratedCircle::center() const
{
	return m_shapePointer->getPosition();
}

inline std::shared_ptr<sf::CircleShape> CDecoratedCircle::createShape(const double& radius, const sf::Vector2f& center)
{
	if (radius <= 0)
	{
		throw std::invalid_argument("radius cant be negative or zero");
	}
	sf::CircleShape shape;
	shape.setPosition(center);
	shape.setRadius(radius);
	shape.setFillColor(CShapeColors::randomColor()); // CShapeColors::randomColor()
	return std::make_shared<sf::CircleShape>(shape);
}

inline std::string CDecoratedCircle::toString() const
{
	return "CIRCLE: P=" + std::to_string(perimeter()) + "; S=" + std::to_string(square());
}

inline size_t CDecoratedCircle::getPointCount() const
{
	return m_shapePointer->getPointCount();
}

inline sf::Vector2f CDecoratedCircle::getPoint(size_t size) const
{
	return m_shapePointer->getPoint(size);
}

inline std::shared_ptr<sf::Shape> CDecoratedCircle::getShape() const
{
	return m_shapePointer;
}

inline std::shared_ptr<CShapeDecorator> CDecoratedCircle::getShapeDecorator()
{
	return std::make_shared<CDecoratedCircle>(*this);
}
