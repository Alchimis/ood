#include "Canvas.h"

inline void CCanvas::addShape(std::shared_ptr<sf::Shape> const& shape)
{
	m_shapes.push_back(shape);
}

inline void CCanvas::draw()
{
	sf::RenderWindow window(sf::VideoMode(m_canvasWidth, m_canvasHeight), "OpenGL");
	window.setFramerateLimit(60);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
			{
				window.close();
			}
		}
		window.clear();

		for (auto shape : m_shapes)
		{
			window.draw(*shape);
		}

		window.display();
	}
}
