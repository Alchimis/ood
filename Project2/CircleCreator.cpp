#include "CircleCreator.h"
#include "CDecoratedCircle.h"
#include "Canvas.h"
#include <SFML/Graphics.hpp>
#include <fstream>
#include <iostream>
#include <regex>

 inline std::shared_ptr<CShapeDecorator> CCircleCreator::createShape(std::istream& args, CCanvas& canvas) const
{

	std::string string;
	std::getline(args, string);
	std::cmatch cma;
	std::regex regex("[Cc][ ]*[=:][ ]*(\\w*)[ ]*,(\\w*)[ ]*;[ ]*[Rr][ ]*[=:][ ]*(\\w*)");
	if (std::regex_search(string.c_str(), cma, regex))
	{
		double centerX = std::stof(cma[1]);
		double centerY = std::stof(cma[2]);
		double radius = std::stof(cma[3]);
		CDecoratedCircle circle(CDecoratedCircle::createShape(radius, sf::Vector2f(centerX, centerY)));
		canvas.addShape(circle.getShape());
		return circle.getShapeDecorator();
	}
	throw std::invalid_argument("circle incorect: must be like CIRCLE: C=100,100;R=50");
 }
