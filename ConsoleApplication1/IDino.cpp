#include "IDino.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
using namespace sf;
using namespace std;
#include <cmath>

IDino::IDino(string s, double x, double y)
{
	reset = false;
	candoublejump = false;
	dinodown.loadFromFile("DuckSprite.png");
	velocity.x = 0;
	velocity.y = 0;
	t.loadFromFile(s);
	d.setTexture(t);
	d.scale(6, 6);
	d.setPosition(x, y);
	dinojumpBuffer.loadFromFile("Audio/jumping.wav");
	dinojumpSound.setBuffer(dinojumpBuffer);
	dinoducksBuffer.loadFromFile("Audio/jumping.wav");
	dinoducksSound.setBuffer(dinoducksBuffer);
}

IDino::IDino()
{
}

bool IDino::isHoveredOver(int x, int y)
{
	if (Mouse::getPosition().x >= x + d.getPosition().x && Mouse::getPosition().x <= x + d.getPosition().x + t.getSize().x * 6.0 && Mouse::getPosition().y >= y + d.getPosition().y && Mouse::getPosition().y <= y + d.getPosition().y + t.getSize().y * 6.0) {
		return true;
	}
	else {
		return false;
	}
}

void IDino::jump(Event event)
{
	if (event.type == Event::KeyReleased && event.key.code == Keyboard::W && d.getPosition().y > 635 && !Keyboard::isKeyPressed(Keyboard::S)) {
	    velocity.y = -sqrt(2.0f * 981.0f * 200.0);
	    candoublejump = true;
		dinojumpSound.play();
		dinojumpSound.setVolume(100);
		
	}   //200=  jumpheight
	else if (event.type == Event::KeyReleased && event.key.code == Keyboard::W && candoublejump)
	{
		dinojumpSound.play();
		dinojumpSound.setVolume(100);
	    velocity.y = -sqrt(2.0f * 981.0f * 200.0);
	    candoublejump = false;
	}
}


void IDino::update(float dt) {
	if (this->d.getPosition().y < 640)
	{
		velocity.y += 981.0f * dt;
	}
	this->d.move(0, velocity.y * dt);
	if (this->d.getPosition().y > (640) && !Keyboard::isKeyPressed(Keyboard::S))
	{
		this->d.setPosition(50, 640);
	}
	if (Keyboard::isKeyPressed(Keyboard::S) && d.getPosition().y > 630) {
		dinoducksSound.play();
		dinoducksSound.setVolume(100);
		d.setTexture(dinodown);
		d.setPosition(47, 640);
		reset = 1;
	}

	if (reset && !Keyboard::isKeyPressed(Keyboard::S)) {
		d.setPosition(50, 640);
		d.setTexture(t);
		reset = 0;
	}

}