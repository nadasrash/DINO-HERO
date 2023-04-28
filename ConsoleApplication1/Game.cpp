#define _CRT_SECURE_NO_WARNINGS
#include "Game.h"
//#include "Credits.h"
#include <iostream>
#include <ctime>

using namespace std;
RenderWindow window(VideoMode(1200, 800), "SFML Works!");
void Game::run()
{
    
    window.setFramerateLimit(60); // to not burn out your graphics card
    IDino dino("DinoSprite.png", 100, 500);
    IDino dinoII("DinoSprite.png", 700, 500);
    // vectors
    Vector2f circle1pos = Vector2f(100.f, 100.f);

    // shapes and properties
    CircleShape circle1(100.f);
    circle1.setFillColor(Color::Green);
    circle1.setPosition(circle1pos);

    //jumping feature


    Texture tex;
    tex.loadFromFile("newproject.png");
    Sprite createdbutton;
    createdbutton.setTexture(tex);
    createdbutton.scale(.5, .5);
    createdbutton.setPosition(600, 500);
    


	Text timee;
    Font f;
    timee.setCharacterSize(20);
    timee.setPosition(900, 00);
    f.loadFromFile("Fonts/Minecraft.ttf");
    timee.setFont(f);
    //ctime() returns given time
    
    //nada
    Backgroundn rect1;
    Backgroundn rect2;
    Backgroundn rect3;

    RectangleShape dino1(Vector2f(200.f, 120.f));
    dino1.setPosition(300.f, 500.f);
    Texture dino1Texture;
    dino1Texture.loadFromFile("DinoSprites4.png");

    dino1.setTexture(&dino1Texture);
    Dino dino1Player(&dino1Texture, Vector2u(13, 1), 3.0f);

    RectangleShape dino2(Vector2f(200.f, 120.f));
    dino2.setPosition(500.f, 500.f);
    Texture dino2Texture;
    dino2Texture.loadFromFile("DinoSprites2.png");

    dino2.setTexture(&dino2Texture);
    Dino dino2Player(&dino2Texture, Vector2u(15, 1), 0.5f);

    RectangleShape dino3(Vector2f(200.f, 120.f));
    dino3.setPosition(700.f, 500.f);
    Texture dino3Texture;
    dino3Texture.loadFromFile("DinoSprites3.png");

    dino3.setTexture(&dino3Texture);
    Dino dino3Player(&dino3Texture, Vector2u(15, 1), 3.0f);
    float deltaTime = 0.0f;
    Clock clock;

    // Arrows Feature
   /* RectangleShape arrow(Vector2f(100.f, 100.f));
    arrow.setPosition(1200.f, 800.f);
    Texture arrowTexture;
    arrowTexture.loadFromFile("arrows.png");

    arrow.setTexture(&arrowTexture);
    Dino arrowPlayer(&arrowTexture, Vector2u(8, 1), 3.0f);*/

    //

    //backgounds
    Background back1("0.png", 60, 80, .25, .25);
    Background back2("1.png", 650, 80, .25, .25);
    Background back3("3.png", 60, 500, .25, .25);
    Background back4("4.png", 650, 500, .25, .25);
    Background generalbackground("0.png", 0, 0, 3.0, 4.0);



    //Game Sounds

    // Background music
    SoundBuffer backgroundmusicBuffer;
    Sound backgroundsound;
    bool firstMusic = true;
    if (!backgroundmusicBuffer.loadFromFile("Audio/supermusic.wav"))
        cout << ("AUDIO NOT FOUND!!");
    backgroundsound.setBuffer(backgroundmusicBuffer);


    ////main menu select music
    //SoundBuffer menuMusicBuffer;
    //Sound menuMusicSound;
    //bool secondmusic = true;
    //if (!menuMusicBuffer.loadFromFile("Audio/supermusic.wav"))
    //    cout << ("AUDIO NOT FOUND!!");
    //menuMusicSound.setBuffer(backgroundmusicBuffer);

    //play game music
    SoundBuffer gameplayBuffer;
    Sound gameplaySound;
    bool thirdmusic = true;
    gameplayBuffer.loadFromFile("Audio/playgame.wav");
    if (!gameplayBuffer.loadFromFile("Audio/playgame.wav"))
        cout << ("AUDIO NOT FOUND!!");
    gameplaySound.setBuffer(backgroundmusicBuffer);



    /// main loop game: 


    bool ismuted = false;
    bool reset = false;


    MainMenu button1(500, 200, 500, 200, "Play");
    button1.selectandunselect();
    MainMenu button2(500, 300, 500, 300, "About");
    MainMenu button3(500, 400, 500, 400, "Credits");
    MainMenu button4(500, 500, 500, 500, "Exit");
   
    MainMenu buttonE(500, 200, 500, 200, "Easy");
    buttonE.selectandunselect();
    MainMenu buttonH(500, 300, 500, 300, "Hard");


    //Credits creditgame(500, 200, 500, 200, "Credits go to Farah Elsayed 202100258, Arwa Aly 202100362, Nada AlRashidy 202101093");

    while (window.isOpen())
    {
		time_t givemetime = time(NULL);
		timee.setString(ctime(&givemetime));

        bool downpressed = true;

        sf::Event event;

        while (window.pollEvent(event))
        {

            processEvents(event, back1, back2, back3, back4, backgroundsound, button1, button2,button3, button4, buttonE, buttonH, ismuted, dino, dinoII);
            if (state == "play") {
				dino.jump(event);
            }

        }
        deltaTime = clock.restart().asSeconds();

        window.clear();
        Render(deltaTime, thirdmusic, gameplaySound, generalbackground, button1, button2, button3, button4,buttonE, buttonH, back1, back2, back3, back4, firstMusic, backgroundsound, dino1Player, dino2Player, dino3Player, dino1, dino2, dino3, rect1, rect2, rect3, dino, timee, dinoII, createdbutton);
     }
}

void Game::processEvents(Event event, Background& back1, Background& back2, Background& back3, Background& back4, Sound& backgroundsound, MainMenu& button1, MainMenu& button2, MainMenu& button3, MainMenu& button4, MainMenu& buttonE, MainMenu& buttonH, bool& ismuted, IDino& dino, IDino& dinoII)
{
    if (event.type == sf::Event::Closed)
        window.close();

    if (state == "initial") {
        if (event.type == Event::KeyReleased && event.key.code == Keyboard::M && !ismuted) // to Mute
        {
            backgroundsound.setVolume(0);
            ismuted = true;
        }
        else  if (ismuted && event.type == Event::KeyReleased && event.key.code == Keyboard::M) //to Play
        {
            ismuted = false;
            backgroundsound.setVolume(100);
        }
        if (event.type == Event::KeyReleased && event.key.code == Keyboard::Enter)
        {
            state = "mainmenu";
            backgroundsound.stop();
        }
    }
    else if (state == "mainmenu") {

        if (button1.isselected && event.type == Event::KeyReleased && event.key.code == Keyboard::Down)
        {
            button1.selectandunselect();
            button2.selectandunselect();
        }
        else if (button2.isselected && event.type == Event::KeyReleased && event.key.code == Keyboard::Down)
        {
            button2.selectandunselect();
            button3.selectandunselect();
        }
        else if (button3.isselected && event.type == Event::KeyReleased && event.key.code == Keyboard::Down)
        {
            button3.selectandunselect();
            button4.selectandunselect();
        }
        else if (button4.isselected && event.type == Event::KeyReleased && event.key.code == Keyboard::Up)
        {
            button4.selectandunselect();
            button3.selectandunselect();
        }
        else if (button3.isselected && event.type == Event::KeyReleased && event.key.code == Keyboard::Up)
        {
            button3.selectandunselect();
            button2.selectandunselect();
        }
        else if (button2.isselected && event.type == Event::KeyReleased && event.key.code == Keyboard::Up)
        {
            button2.selectandunselect();
            button1.selectandunselect();
        }
        if (event.type == Event::KeyReleased && event.key.code == Keyboard::BackSpace)
        {
            state = "initial";
        }

        if (button1.isselected && event.type == Event::KeyReleased && event.key.code == Keyboard::Enter) {
            state = "difficultyselection";
        }

        if (button2.isselected && event.type == Event::KeyReleased && event.key.code == Keyboard::Enter) {
            state = "About";
        }
        if (button3.isselected && event.type == Event::KeyReleased && event.key.code == Keyboard::Enter) {
            state = "Credits";
        }
        if (button4.isselected && event.type == Event::KeyReleased && event.key.code == Keyboard::Enter) {
            window.close();
        }

    }
    else if (state == "Credits")
    {
        if (event.type == Event::KeyReleased && event.key.code == Keyboard::BackSpace)
        {
            state = "mainmenu";
        }

    }
    else if (state == "About")
    {
        if (event.type == Event::KeyReleased && event.key.code == Keyboard::BackSpace)
        {
            state = "mainmenu";
        }

    }

    else if (state == "play")
    {
        //dino.jump(event);
        if (state == "play" && event.type == Event::KeyReleased && event.key.code == Keyboard::BackSpace)
        {
            state = "backgroundselect";
        }
    }

    else if (state == "difficultyselection")
    {
        if (buttonE.isselected && event.type == Event::KeyReleased && event.key.code == Keyboard::Down)
        {
            buttonE.selectandunselect();
            buttonH.selectandunselect();
        }

        else if (buttonH.isselected && event.type == Event::KeyReleased && event.key.code == Keyboard::Up)
        {

            buttonH.selectandunselect();
            buttonE.selectandunselect();
        }
        if (buttonH.isselected && event.type == Event::KeyReleased && event.key.code == Keyboard::Enter) {
            Difficulty = "Hard";
            state = "backgroundselect";
        }

        if (buttonE.isselected && event.type == Event::KeyReleased && event.key.code == Keyboard::Enter) {
            Difficulty = "Easy";
            state = "backgroundselect";
        }

        if (event.type == Event::KeyReleased && event.key.code == Keyboard::BackSpace)
        {
            state = "mainmenu";

        }
        if (event.type == Event::KeyReleased && event.key.code == Keyboard::Enter)
        {
            state = "backgroundselect";
        }

    }
    else if (state == "Dinoselection") {
        if (dino.isHoveredOver(window.getPosition().x, window.getPosition().x) && Mouse::isButtonPressed(Mouse::Left)) {
            dinoGame = dino;
            state = "play";
        }
        else if (dinoII.isHoveredOver(window.getPosition().x, window.getPosition().x) && Mouse::isButtonPressed(Mouse::Left)) {
            dinoGame = dinoII;
            state = "play";
        }
        else if(Mouse::isButtonPressed(Mouse::Left)){
			dinoGame = dinoII;
			state = "play";
        }
		if (event.type == Event::KeyReleased && event.key.code == Keyboard::BackSpace)
		{
			state = "backgroundselect";
		}
    }
    else if (state == "backgroundselect")
    {

        if (event.type == Event::KeyReleased && event.key.code == Keyboard::BackSpace)
        {
            state = "difficultyselection";
        }


        if (back1.ishoveredover(window.getPosition().x, window.getPosition().x) && Mouse::isButtonPressed(Mouse::Left))
        {
            /*back1.getsprite().scale(1.0/, 1.0);
            back1.getsprite().setPosition(0, 0);*/
            backgound = back1.getsprite();
            state = "Dinoselection";
            if (event.type == Event::KeyReleased && event.key.code == Keyboard::BackSpace)
                state = "mainmenu";
        }
        if (back2.ishoveredover(window.getPosition().x, window.getPosition().x) && Mouse::isButtonPressed(Mouse::Left))
        {
            /*back2.getsprite().scale(1.0 / .25, 1.0 / .25);
            back2.getsprite().setPosition(0, 0);*/
            backgound = back2.getsprite();
            state = "Dinoselection";
            if (event.type == Event::KeyReleased && event.key.code == Keyboard::BackSpace)
                state = "mainmenu";

        }
        if (back3.ishoveredover(window.getPosition().x, window.getPosition().x) && Mouse::isButtonPressed(Mouse::Left))
        {
            /*back3.getsprite().scale(1.0 / .25, 1.0 / .25);
            back3.getsprite().setPosition(0, 0);*/
            backgound = back3.getsprite();
            state = "Dinoselection";
            if (event.type == Event::KeyReleased && event.key.code == Keyboard::BackSpace)
                state = "mainmenu";
        }
        if (back4.ishoveredover(window.getPosition().x, window.getPosition().x) && Mouse::isButtonPressed(Mouse::Left))
        {
            /*back4.getsprite().scale(1.0 / .25, 1.0 / .25);
            back4.getsprite().setPosition(0, 0);*/
            backgound = back4.getsprite();
            state = "Dinoselection";
            if (event.type == Event::KeyReleased && event.key.code == Keyboard::BackSpace)
                state = "mainmenu";
        }
        backgound.scale(2.5, 3);
    }
}
         /*if (state == "mainmenu") {

              if (event.type == Event::KeyReleased && event.key.code == Keyboard::BackSpace) {
                  state = "initial";
              }*/
     
     //mute feature
 
    
    
 
   
    Game::Game()
    {
        state = "initial";
        //window.create
		
    }

    void Game::Render(float& deltaTime, bool& thirdmusic, Sound& gameplaySound, Background& generalbackground, MainMenu& button1, MainMenu& button2, MainMenu& button3, MainMenu& button4,MainMenu& buttonE, MainMenu& buttonH, Background& back1, Background& back2, Background& back3, Background& back4, bool& firstMusic, Sound& backgroundsound, Dino& dino1Player, Dino& dino2Player, Dino& dino3Player, RectangleShape& dino1, RectangleShape& dino2, RectangleShape& dino3, Backgroundn& rect1, Backgroundn& rect2, Backgroundn& rect3, IDino& dino
  , Text& time, IDino& dinoII, Sprite createdbutton)
    {
		if (state == "play")
		{
			backgound.setPosition(0, 0);
			window.draw(backgound);
			window.draw(dino.d);
			dino.update(deltaTime);
		}
		else if (state == "mainmenu")
		{
			window.draw(generalbackground.getsprite());
			window.draw(button1.getshape());
			window.draw(button1.getText());
			window.draw(button2.getshape());
			window.draw(button2.getText());
			window.draw(button3.getshape());
			window.draw(button3.getText());
			window.draw(button4.getshape());
			window.draw(button4.getText());
            window.draw(time);
            window.draw(createdbutton);
		}
		else if (state == "backgroundselect")
		{
			window.draw(back1.getsprite());
			window.draw(back2.getsprite());
			window.draw(back3.getsprite());
			window.draw(back4.getsprite());
		}
		else if (state == "initial")
		{
			if (firstMusic) {
				backgroundsound.play();

				backgroundsound.setVolume(50);
				firstMusic = false;
			}
			dino1Player.Update(0, deltaTime);
			dino1.setTextureRect(dino2Player.uvRect);

			dino2Player.Update(0, deltaTime);
			dino2.setTextureRect(dino2Player.uvRect);
			dino3Player.Update(0, deltaTime);
			dino3.setTextureRect(dino2Player.uvRect);

			rect1.setRectColor(260, 270, 105);
			rect1.setPose(0, 0);
			rect2.setRectColor(240, 210, 100);
			rect2.setPose(400, 0);
			rect3.setRectColor(240, 280, 107);
			rect3.setPose(800, 0);
			rect1.draw(window);
			rect2.draw(window);
			rect3.draw(window);
			rect1.displayText(window);
			window.draw(dino1);
			window.draw(dino2);
			window.draw(dino3);
		}
		else if (state == "Credits")
		{
			Text credittext;
			Font creditfont;
			creditfont.loadFromFile("Fonts/Minecraft.ttf");
			credittext.setFont(creditfont);
			//credittext.setColor(Color::Black);
			credittext.setString("Farah 202100258\nNada 202101093\nArwa 202100362");
			credittext.setPosition(400, 280);
			window.draw(credittext);
		}
		else if (state == "About")
		{
			Text credittext;
			Font creditfont;
			creditfont.loadFromFile("Fonts/Minecraft.ttf");
			credittext.setFont(creditfont);
			//credittext.setColor(Color::Black);
			credittext.setString("press enter to procedd and backspace to go back");
			credittext.setPosition(300, 280);
			window.draw(credittext);
		}
        else if (state == "difficultyselection")
        {
            window.draw(generalbackground.getsprite());
            window.draw(buttonE.getshape());
            window.draw(buttonE.getText());
            window.draw(buttonH.getshape());
            window.draw(buttonH.getText());
        }

        else if (state == "Dinoselection")
        {
            
            window.draw(dino.d);
            window.draw(dinoII.d);
        }

		window.display();
    
    }