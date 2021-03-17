#pragma once

#include <sstream>
#include "SplashState.hpp"
#include "DEFINITIONS.hpp"

#include <iostream>

namespace Aldo
{
	SplashState::SplashState(GameDataRef data) : _data(data) 
	{

	}
	void SplashState::Init() {
		_data->assets.LoadTexture("Splash State Background",
			SPLASH_SCENE_BACKGROUND_FILEPATH);
		_background.setTexture(this->_data->assets.GetTexture("Splash State Background"));
	}
	void SplashState::HandleInput() {/*only handle and check whether the X button to close the window is pressed or not*/
		sf::Event event;

		while (_data->window.pollEvent(event))
		{
			if (sf::Event::Closed == event.type) {
				_data->window.close();
			}
		}
	}
	void SplashState::Update(float dt) {
		if (_clock.getElapsedTime().asSeconds() > SPLASH_STATE_SHOW_TIME) {
			std::cout << "go to main menu" << std::endl;
		}
	}
	void SplashState::Draw(float dt) {
		_data->window.clear();
		_data->window.draw(_background);
		_data->window.display();
	}
}