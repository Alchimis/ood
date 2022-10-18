#include "TriangleCreator.h"
#include "Canvas.h"
#include "DecoratedTriangle.h"
#include <fstream>
#include <iostream>
#include <regex>

 inline std::shared_ptr<CShapeDecorator> CTriangleShapeCreator::createShape(std::istream& args, CCanvas& canvas) const
{
	std::string string;
	std::getline(args, string);
	std::cmatch cma;
	std::regex regex("[Pp]1[ ]*[=:][ ]*(\\w+)[ ]*,[ ]*(\\w+)[ ]*;[ ]*[Pp]2[ ]*[=:][ ]*(\\w+)[ ]*,[ ]*(\\w+);[ ]*[Pp]3[ ]*[=:][ ]*(\\w+)[ ]*,[ ]*(\\w+)");
	if (std::regex_search(string.c_str(), cma, regex))
	{
		CDecoratedTriangle triangle(CDecoratedTriangle::createShape(
			{ std::stof(cma[1]), std::stof(cma[2]) },
			{ std::stof(cma[3]), std::stof(cma[4]) },
			{ std::stof(cma[5]), std::stof(cma[6]) }));
		canvas.addShape(triangle.getShape()); /*
		 m_shapes.push_back(std::make_shared<CDecoratedTriangle>(triangle));*/
		return triangle.getShapeDecorator();
	}
	throw std::invalid_argument("triangle incorect: must be like TRIANGLER: P1=100,100;P2=200,200;P3:450,300");
 }

// std::shared_ptr<CShapeDecorator> createTriangleShape(std::istream& args, CCanvas& canvas)
//{
//	std::string string;
//	std::getline(args, string);
//	std::cmatch cma;
//	std::regex regex("[Pp]1[ ]*[=:][ ]*(\\w+)[ ]*,[ ]*(\\w+)[ ]*;[ ]*[Pp]2[ ]*[=:][ ]*(\\w+)[ ]*,[ ]*(\\w+);[ ]*[Pp]3[ ]*[=:][ ]*(\\w+)[ ]*,[ ]*(\\w+)");
//	if (std::regex_search(string.c_str(), cma, regex))
//	{
//		CDecoratedTriangle triangle(CDecoratedTriangle::createShape(
//			{ std::stof(cma[1]), std::stof(cma[2]) },
//			{ std::stof(cma[3]), std::stof(cma[4]) },
//			{ std::stof(cma[5]), std::stof(cma[6]) }));
//		canvas.addShape(triangle.getShape()); /*
//		 m_shapes.push_back(std::make_shared<CDecoratedTriangle>(triangle));*/
//		return triangle.getShapeDecorator();
//	}
//	throw std::invalid_argument("triangle incorect: must be like TRIANGLER: P1=100,100;P2=200,200;P3:450,300");
// }