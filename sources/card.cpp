#include "../headers/card.h"

Card::Card(std::string animal, sf::Texture& frontTexture, sf::Texture& backTexture, int questionIndex) :
    animal(animal), matched(false), isFlipped(false), questionIndex(questionIndex)
{
    frontSprite.setTexture(frontTexture);
    backSprite.setTexture(backTexture);

    frontSprite.setScale(0.4f, 0.6f);
    backSprite.setScale(0.4f, 0.6f);
}

std::string Card::getAnimal() const {
    return animal;
}

void Card::draw(sf::RenderWindow& window) {
    if (isFlipped) {
        window.draw(frontSprite);
    } else {
        window.draw(backSprite);
    }
}

bool Card::isMatched() const {
    return matched;
}

void Card::setMatched(bool matched) {
    this->matched = matched;
}

void Card::flip() {
    isFlipped = !isFlipped;
}
void Card::setPosition(float x, float y) {
    frontSprite.setPosition(x, y);
    backSprite.setPosition(x, y);
}
sf::FloatRect Card::getGlobalBounds() const {
    return frontSprite.getGlobalBounds();
}

int Card::getQuestionIndex() const {
    return questionIndex;
}

sf::Vector2f Card::getOriginalSize() const{
    return sf::Vector2f(80.0f, 160.0f);
}
void Card::setScale(float scaleX, float scaleY) {
    frontSprite.setScale(scaleX, scaleY);
    backSprite.setScale(scaleX, scaleY);
}