
#pragma once
#include "Header.h"
#include <SFML/Graphics.hpp>

class CDecoratedRectangle : public CShapeDecorator
{
private:
	std::shared_ptr<sf::RectangleShape> m_shapePointer;

public:
	CDecoratedRectangle(const std::shared_ptr<sf::RectangleShape>& shapePointer)
		: m_shapePointer(shapePointer)
	{
	}
	~CDecoratedRectangle()
	{
	}
	float perimeter() const override;
	float square() const override;
	float height() const;
	float width() const;
	static std::shared_ptr<sf::RectangleShape> createShape(const sf::Vector2f& /*p1*/, const sf::Vector2f& /*p2*/);
	std::string toString() const override;
	size_t getPointCount() const override;
	sf::Vector2f getPoint(size_t) const override;
	std::shared_ptr<sf::Shape> getShape() const override;
	std::shared_ptr<CShapeDecorator> getShapeDecorator() override;
};
