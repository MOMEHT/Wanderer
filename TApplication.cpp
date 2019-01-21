#include "TApplication.hpp"
#include <iostream>

namespace Lesson {
	TApplication::TApplication():
		Window(nullptr),
		MapWidget(nullptr),
		Player(nullptr) {

	}

	TApplication::~TApplication() {

	}

	void TApplication::Init() {
        Window = new sf::RenderWindow(sf::VideoMode(400, 400), "4X TBS Lessons");
        Window->setVerticalSyncEnabled(true);
        MapWidget = new TMapWidget(0,0,400,400);
        Player = new TPlayer(50, 50);
	}

	void TApplication::Run() {
	    unsigned short int ElapsedTime = 0;
		while (Window->isOpen()) {
            if (ElapsedTime > 64000)
            ElapsedTime = 0;
            sf::Clock clock;
			sf::Event event;
			while (Window->pollEvent(event)) {
				if (event.type == sf::Event::Closed)
               	          Window->close();
			}
			ElapsedTime += clock.getElapsedTime().asMilliseconds();

			Window->clear(sf::Color::Black);
			MapWidget->Draw(Window);
            Player->Draw(Window, ElapsedTime);
			Window->display();
            std::cout << ElapsedTime << std::endl;

		}
	}

	void TApplication::End() {
          if (Window != nullptr){
              delete Window;
              Window = nullptr;
          }
          if (MapWidget != nullptr){
            delete MapWidget;
            MapWidget = nullptr;
          }

	}
}
