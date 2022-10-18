#pragma once
#include <SFML/Graphics.hpp>
class CShapeDecorator : public sf::Shape
{
public:
	virtual std::string toString() const { return ""; };
	virtual float perimeter() const { return 0, 0; };
	virtual float square() const { return 0, 0; };
	virtual std::shared_ptr<sf::Shape> getShape() const { throw std::invalid_argument("unimplemented"); };
	virtual std::shared_ptr<CShapeDecorator> getShapeDecorator() { throw std::invalid_argument("method get shape unimplemented"); }
};
