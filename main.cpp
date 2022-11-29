#include "SFML/Graphics.hpp"

using namespace sf;
const float SC_WIDTH = 800.f;
const float SC_HEIGHT = 600.f;
const int size = 5;

float radius = 200.f;

int main()
{
	// Объект, который, собственно, является главным окном приложения
	RenderWindow window(VideoMode(SC_WIDTH, SC_HEIGHT), "SFML Works!");


	RectangleShape arr_rect[size];
	float dx = 100.f;
	for (int i = 0; i < size; i++) {
		arr_rect[i].setSize(Vector2f(50.f, 50.f));
		arr_rect[i].move(750, 0);
		arr_rect[i].move(0, dx * i);
		arr_rect[i].setFillColor(Color{ (Uint8)(100 * i+50), (Uint8)(70 * i), (Uint8)(40 * i) });
	}


	// Главный цикл приложения. Выполняется, пока открыто окно
	while (window.isOpen())
	{
		// Обрабатываем очередь событий в цикле
		Event event;
		while (window.pollEvent(event))
		{
			// Пользователь нажал на «крестик» и хочет закрыть окно?
			if (event.type == Event::Closed)
				// тогда закрываем его
				window.close();
		}
		// Отрисовка окна 
		window.clear();
		for (int i = 0; i < size; i++) {
			window.draw(arr_rect[i]);
		}

		window.display();
	}

	return 0;
}