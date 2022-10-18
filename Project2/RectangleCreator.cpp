#include "RectangleCreator.h"
#include "CDecoratedRectangle.h"
#include "Canvas.h"
#include <regex>

 inline std::shared_ptr<CShapeDecorator> CRectangleCreator::createShape(std::istream& args, CCanvas& canvas) const
{
	std::string string;
	std::getline(args, string);
	std::cmatch cma;
	std::regex regex("[Pp]1[ ]*[=:][ ]*(\\w+)[ ]*,[ ]*(\\w+)[ ]*;[ ]*[Pp]2[ ]*[=:][ ]*(\\w+)[ ]*,[ ]*(\\w+);");
	if (std::regex_search(string.c_str(), cma, regex))
	{
		CDecoratedRectangle rectangle(CDecoratedRectangle::createShape(
			{ std::stof(cma[1]), std::stof(cma[2]) },
			{ std::stof(cma[3]), std::stof(cma[4]) }));
		canvas.addShape(rectangle.getShape()); /*
		 m_shapes.push_back(std::make_shared<CDecoratedRectangle>(rectangle));*/
		return rectangle.getShapeDecorator();
	}
	throw std::invalid_argument("rectangle incorect: must be like RECTANGLE: P1=100,100;P2=200,200;");
 }

// std::shared_ptr<CShapeDecorator> createRectangleShape(std::istream& args, CCanvas& canvas)
//{
//	std::string string;
//	std::getline(args, string);
//	std::cmatch cma;
//	std::regex regex("[Pp]1[ ]*[=:][ ]*(\\w+)[ ]*,[ ]*(\\w+)[ ]*;[ ]*[Pp]2[ ]*[=:][ ]*(\\w+)[ ]*,[ ]*(\\w+);");
//	if (std::regex_search(string.c_str(), cma, regex))
//	{
//		CDecoratedRectangle rectangle(CDecoratedRectangle::createShape(
//			{ std::stof(cma[1]), std::stof(cma[2]) },
//			{ std::stof(cma[3]), std::stof(cma[4]) }));
//		canvas.addShape(rectangle.getShape()); /*
//		 m_shapes.push_back(std::make_shared<CDecoratedRectangle>(rectangle));*/
//		return rectangle.getShapeDecorator();
//	}
//	throw std::invalid_argument("rectangle incorect: must be like RECTANGLE: P1=100,100;P2=200,200;");
// }
