#pragma once

#include <SFML/Graphics.hpp>
#include "state.hpp" 
#include "GameLoop.hpp"

namespace Aldo {
	class SplashState : public State
	{
	public: 
		SplashState(GameDataRef data);

		void Init();
		void HandleInput();
		void Update(float dt);
		void Draw(float dt);

	private:
		GameDataRef _data;
		sf::Clock _clock;

		sf::Texture _backgroundTexture;
		sf::Sprite _background;
	}
}