#include "Controller.h"
#include "CDecoratedCircle.cpp"
#include "CDecoratedRectangle.cpp"
#include "DecoratedTriangle.cpp"
#include "Canvas.cpp"
#include "CircleCreator.cpp"
#include "RectangleCreator.cpp"
#include "TriangleCreator.cpp"
#include <SFML/Graphics.hpp>
#include <fstream>
#include <regex>
#include <sstream>


//std::shared_ptr<CShapeDecorator> fabricTriangleShape(std::istream& args, CCanvas& canvas)
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
//		canvas.addShape(triangle.getShape());
//		return triangle.getShapeDecorator();
//	}
//	throw std::invalid_argument("triangle incorect: must be like TRIANGLER: P1=100,100;P2=200,200;P3:450,300");
//}
//
//std::shared_ptr<CShapeDecorator> fabricCircleShape(std::istream& args, CCanvas& canvas)
//{
//
//	std::string string;
//	std::getline(args, string);
//	std::cmatch cma;
//	std::regex regex("[Cc][ ]*[=:][ ]*(\\w*)[ ]*,(\\w*)[ ]*;[ ]*[Rr][ ]*[=:][ ]*(\\w*)");
//	if (std::regex_search(string.c_str(), cma, regex))
//	{
//		double centerX = std::stof(cma[1]);
//		double centerY = std::stof(cma[2]);
//		double radius = std::stof(cma[3]);
//		CDecoratedCircle circle(CDecoratedCircle::createShape(radius, sf::Vector2f(centerX, centerY)));
//		canvas.addShape(circle.getShape());
//		return circle.getShapeDecorator();
//	}
//	throw std::invalid_argument("circle incorect: must be like CIRCLE: C=100,100;R=50");
//}
//
//std::shared_ptr<CShapeDecorator> fabricRectangleShape(std::istream& args, CCanvas& canvas)
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
//}


inline bool CController::HandleCommand()
{
	auto s = m_map.find("");
	std::istringstream strm(GetLine());
	std::string action;
	strm >> action;
	if (action == "...")
	{
		m_isOver = true;
	}
	auto it = m_factoryMap.find(action);
	if (it != m_factoryMap.end())
	{
		try
		{
			m_shapes.push_back(it->second.createShape(strm, m_canvas));
			return true;
		}
		catch (const std::invalid_argument& e)
		{
			WriteInOutput(e.what());
			return true;
		}
		catch (const std::out_of_range& e)
		{
			WriteInOutput(e.what());
			return true;
		}
	}
	WriteInOutput("Unknown command!");
	return true;
}

inline void CController::SideEffect()
{
	for (auto& pointer : m_shapes)
	{
		m_output << pointer->toString() << std::endl;
	}
	m_canvas.draw();
}

inline void CController::WriteInOutput(std::string message)
{
	m_output << message << std::endl;
}

inline std::string CController::GetLine()
{
	std::string line = "";
	std::getline(m_input, line);
	return line;
}

inline CController::CController(std::ifstream& input, std::ofstream& output)
	: m_input(input)
	, m_output(output)
	, m_map({})
	, m_canvas(800, 800)
	, m_isOver(false)
	, m_creatorMap({/* { "CIRCLE:",fabricCircleShape },
		  { "RECTANGLE:", fabricRectangleShape },
		  { "TRIANGLE:",fabricTriangleShape },
		  { "...", [&](std::istream& args, CCanvas& canvas) {
			   m_isOver = true;
			   return fabricTriangleShape(args, canvas);
		   } } */})
	, m_factoryMap({ 
		{ "CIRCLE:", CCircleCreator() }, 
		{ "RECTANGLE:", CRectangleCreator() }, 
		{ "TRIANGLE:", CTriangleShapeCreator() },
	  }) /*
		{ "...", [&](std::istream& args, CCanvas& canvas) {
																																		  m_isOver = true;
																																		  return fabricTriangleShape(args, canvas);
																																	  } } })*/

{
}