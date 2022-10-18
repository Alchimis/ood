#pragma once
#include "Header.h"
#include <Vector>

class CCanvas
{
private:
	std::vector<std::shared_ptr<sf::Shape>> m_shapes;
	unsigned int m_canvasHeight;
	unsigned int m_canvasWidth;

public:
	CCanvas(unsigned int height, unsigned int width)
		: m_canvasHeight(height)
		, m_canvasWidth(width){};
	void addShape(std::shared_ptr<sf::Shape> const&);
	void draw();
};
