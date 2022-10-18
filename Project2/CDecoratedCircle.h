#pragma once
#include "Header.h"
#include <SFML/Graphics.hpp>

class CDecoratedCircle : public CShapeDecorator
{
private:
	std::shared_ptr<sf::CircleShape> m_shapePointer;

public:
	CDecoratedCircle(const std::shared_ptr<sf::CircleShape>& shapePointer)
		: m_shapePointer(shapePointer)
	{
	}
	~CDecoratedCircle() {}
	float perimeter() const override;
	float square() const override;
	float radius() const;
	sf::Vector2f center() const;
	static std::shared_ptr<sf::CircleShape> createShape(const double& /*radius*/, const sf::Vector2f& /*center*/);
	std::string toString() const override;
	size_t getPointCount() const override;
	sf::Vector2f getPoint(size_t) const override;
	std::shared_ptr<sf::Shape> getShape() const override;
	std::shared_ptr<CShapeDecorator> getShapeDecorator() override;
};
