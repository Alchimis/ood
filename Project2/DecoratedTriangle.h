#pragma once
#include "Header.h"
#include <SFML/Graphics.hpp>

class CDecoratedTriangle : public CShapeDecorator
{
private:
	std::shared_ptr<sf::ConvexShape> m_shapePointer;

public:
	CDecoratedTriangle(const std::shared_ptr<sf::ConvexShape>& shapePointer)
		: m_shapePointer(shapePointer){};
	~CDecoratedTriangle(){};

	float perimeter() const;
	float square() const;
	float a() const;
	float b() const;
	float c() const;
	static std::shared_ptr<sf::ConvexShape> createShape(const sf::Vector2f& /*p1*/, const sf::Vector2f& /*p2*/, const sf::Vector2f& /*p3*/);
	static double distanceBetweenPoints(const sf::Vector2f& /*p1*/, const sf::Vector2f& /*p2*/);
	std::string toString() const override;
	size_t getPointCount() const override;
	sf::Vector2f getPoint(size_t) const override;
	std::shared_ptr<CShapeDecorator> getShapeDecorator() override;
	std::shared_ptr<sf::Shape> getShape() const override;
};
