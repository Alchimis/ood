#pragma once
#include "Canvas.h"
#include "Header.h"
#include "Creator.h"
#include <SFML/Graphics.hpp>
#include <functional>
#include <iostream>
#include <map>
#include <string>

class CController
{
public:
	using Handler = std::function<std::shared_ptr<CShapeDecorator>(std::istream& args)>;
	using Setter = std::function<std::shared_ptr<CShapeDecorator>(int value)>;
	using ActionMap = std::map<std::string, Handler>;
	using Fabricator = std::function<std::shared_ptr<CShapeDecorator>(std::istream& args, CCanvas& canvas)>;
	using FabricatorMap = std::map<std::string, Fabricator>;

	bool HandleCommand();
	void SideEffect();
	void WriteInOutput(std::string);
	std::string GetLine();
	CController(std::ifstream& input, std::ofstream& output);

	bool m_isOver;

private:
	std::ifstream& m_input;
	std::ofstream& m_output;
	const ActionMap m_map;
	const FabricatorMap m_creatorMap;
	const std::map<std::string, CCreator> m_factoryMap;

	CCanvas m_canvas;
	std::vector<ShapePointer> m_shapes;
};
