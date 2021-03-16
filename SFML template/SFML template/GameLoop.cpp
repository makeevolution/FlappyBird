
#include "GameLoop.hpp"
#include "SplashState.hpp"

namespace Aldo {

	Game::Game(int width, int height, std::string gametitle) {
		_data->window.create(sf::videomode(width, height),
			title, sf::Style::Close | sf::Style::Titlebar);
		_data->machine.AddState(StateRef(new SplashState(this->_data)));

		this->Run();
	}

	void Game::Run() {
		float newTime, frameTime, interpolation;
		float currentTime = this->_clock.getElapsedTime().asSeconds();
		float accumulator = 0.0f;

		while (this->_data->window.isOpen()) {
			this->_data->machine.ProcessStateChanges();

			newTime = this->_clock.getElapsedTime.asSeconds();
			frameTime = newTime - currentTime; /* How long it takes between frames*/
			if (frameTime > 0.25f) {
				frameTime = 0.25f;
			}

			currentTime = newTime;
			accumulator += frameTime;/*Go to the "future" */
			while (accumulator >= dt) {/*When we want to supply the next frame*/
				this->_data->machine.GetActiveState()->HandleInput();/*Check if there isany input, no need to use this->dt since dt is a constant*/
				this->_data->machine.GetActiveState()->Update(dt);/*Incorporate consequences of this input in the new frame*/
				accumulator -= dt;
			}
			/*Now that we have walked from the "future" to now, we draw the frame*/
			/*So the frameTime is also the time window in which user can give in inputs*/
			interpolation = accumulator / dt;
			this->_data->machine.GetActiveState()->Draw(interpolation);
		}
	}
	
}