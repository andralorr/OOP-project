#ifndef CARD_H
#define CARD_H

#include <SFML/Graphics.hpp>

class Card {
private:
    std::string animal;
    sf::Sprite frontSprite;
    sf::Sprite backSprite;
    bool matched;
    bool isFlipped;
    int questionIndex;

public:
    Card(std::string animal, sf::Texture& frontTexture, sf::Texture& backTexture, int questionIndex);
    std::string getAnimal() const;
    void draw(sf::RenderWindow& window);
    bool isMatched() const;
    void setMatched(bool matched);
    void flip();
    void setPosition(float x, float y);
    sf::FloatRect getGlobalBounds() const;
    int getQuestionIndex() const;
};

#endif
