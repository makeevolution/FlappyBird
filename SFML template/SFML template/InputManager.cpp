#include "InputManager.hpp"

namespace Aldo {
	bool InputManager::IsSpriteClicked(sf::Sprite object, sf::Mouse::Button button,
		sf::RenderWindow& window) /* Checks if sprite is clicked or not!*/
	{
		if (sf::Mouse::isButtonPressed(button))
		{
			sf::IntRect tempRect(object.getPosition().x, 
								 object.getPosition().y, 
								 object.getGlobalBounds().width,
								 object.getGlobalBounds().height); /*Gets positional info about current sprite*/

			if (tempRect.contains(sf::Mouse::getPosition(window))) /*If mouse position is inside the tempRect*/
			{
				return true;/*Sprite is clicked*/
			}
		}
		return false;
	}

	sf::Vector2i InputManager::GetMousePosition(sf::RenderWindow& window)/*Generic function to check mouse position*/
	{
		return sf::Mouse::getPosition(window);
	}
}