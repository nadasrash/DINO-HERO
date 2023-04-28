#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include "menu.h"
#include "IDino.h"
#include "Dino.h"
#include "MainMenu.h"
#include "Background.h"
#include "Backgroundn.h"
using namespace sf;
using namespace std;


class Game {
	string state;
	Sprite backgound;
	string Difficulty; 
	IDino dinoGame;
public:
	void run();
	Game();
	void processEvents(Event event, Background& back1, Background& back2, Background& back3, Background& back4, Sound& backgroundsound, MainMenu& button1, MainMenu& button2, MainMenu& button3, MainMenu& button4,MainMenu& buttonE, MainMenu& buttonH, bool& ismuted, IDino& dino, IDino& dinoII);
	void Update();
	void Render(float& deltaTime, bool& thirdmusic, Sound& gameplaySound, Background& generalbackground, MainMenu& button1, MainMenu& button2, MainMenu& button3, MainMenu& button4, MainMenu& buttonE, MainMenu& buttonH, Background& back1, Background& back2, Background& back3, Background& back4, bool& firstMusic, Sound& backgroundsound, Dino& dino1Player, Dino& dino2Player, Dino& dino3Player, RectangleShape& dino1, RectangleShape& dino2, RectangleShape& dino3, Backgroundn& rect1, Backgroundn& rect2, Backgroundn& rect3, IDino& dino, Text&, IDino& dinoII, Sprite createdbutton);
};