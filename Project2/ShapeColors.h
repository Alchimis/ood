#pragma once
#include <SFML/Graphics.hpp>
#include <Time.h>
#include <array>
#include <random>

class CShapeColors
{
public:
	static sf::Color randomColor()
	{
		return sf::Color::Green;
		srand(time(nullptr));
		std::array colors{ sf::Color::Magenta, sf::Color::Blue, sf::Color::Cyan, sf::Color::Green, sf::Color::Red };
		return colors[rand() % colors.size()];
	};
};
