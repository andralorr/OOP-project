#ifndef GAME_H
#define GAME_H

#include "gameboard.h"
#include "gameboardquiz.h"
#include "question.h"
#include "card.h"
#include <SFML/Graphics.hpp>

class Game {
private:
    GameBoard gameBoard;
    GameBoardQuiz gameBoardQuiz;
    Question question;
    Question* currentQuestion;
    Card* firstFlippedCard = nullptr;
    Card* secondFlippedCard = nullptr;
    sf::Clock matchTimer;
    bool isCheckingMatch = false;
    bool isQuizActive = false;
    const float matchDelay = 0.3f;

public:
    Game();
    void run();
    void processEvents();
    void update();
    void render();

    void processGameBoardEvents();
    void processQuizEvents();

    static void handleWindowClose(sf::RenderWindow& window);
    void handleCardSelection(sf::Event::MouseButtonEvent mouseButton);
    void handleQuizWindowClose();
    void handleQuizOptionSelection(sf::Event::MouseButtonEvent);

    void handleMatch();
    void openQuestionWindow();
    void handleCorrectAnswer();
    void resetGameAfterWrongAnswer();

    friend std::ostream& operator<<(std::ostream& os, const Game& game);
};

#endif // GAME_H
