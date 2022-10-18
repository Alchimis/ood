#include "CRectangle.cpp"
#include "Controller.cpp"
#include <SFML/Graphics.hpp>
#include <optional>
#include <Windows.h>
#include <regex>

template <typename T>
std::optional<T> OpenFile(std::string name)
{
	T output;
	output.open(name);
	if (!output.good())
	{
		return std::nullopt;
	}
	return output;
};

int main()
{
	//CCanvas canvas(800, 800);
	//sf::CircleShape shape;
	//shape.setPosition(100,100);
	//shape.setRadius(100);
	//shape.setFillColor(CShapeColors::randomColor());
	//auto m = std::make_shared<sf::CircleShape>(shape);
	//canvas.addShape(m);
	//canvas.draw();
	///*Sleep(10000);*/
	//m->move(200, 200);
	//canvas.draw();
	auto inFile = OpenFile<std::ifstream>("D:/cpluplus/repos/Project2/Project2/in.txt");
	auto outFile = OpenFile<std::ofstream>("D:/cpluplus/repos/Project2/Project2/out.txt");
	CController controler(inFile.value(), outFile.value()); // std::cin, std::cout
	while (!std::cin.eof() && !std::cin.fail() && !controler.m_isOver)
	{
		std::cout << "> ";
		controler.HandleCommand();
	}
	controler.SideEffect();
	return 0; // TODO: ןונגוסעט םא פאיכû
}