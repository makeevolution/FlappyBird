#pragma once

#include <memory>
#include <string>
#include <SFML/Graphics.hpp>
#include "StateMachine.hpp"
#include "AssetManager.hpp"
#include "InputManager.hpp"

namespace Aldo {
	struct GameData
	{
		StateMachine machine;
		sf::RenderWindow window;
		AssetManager assets;
		InputManager input;
	};
	typedef std::shared_ptr<GameData> GameDataRef;

	class Game {
	public:
		Game(int width, int height, std::string gametitle);
	private:
		const float dt = 1.0f / 60.0f; /*Frame rate*/
		sf::Clock _clock;/*For handling frame rate*/
		GameDataRef _data = std::make_shared<GameData>();

		void Run();
	};
}