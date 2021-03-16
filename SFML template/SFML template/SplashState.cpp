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
		_data->input.IsSpriteClicked()
	}
}