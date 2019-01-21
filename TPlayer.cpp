#include "TPlayer.hpp"

namespace Lesson{
    TPlayer::TPlayer(int aX, int aY):
    X(aX),
    Y(aY),
    PlayerTexture(){
        //PlayerTexture.create(50, 50);
        //PlayerTexture.setRepeated(true);
        PlayerTexture.loadFromFile("MainCharacter.png");
    }

    TPlayer::~TPlayer(){

    }

    void TPlayer::Draw(sf::RenderWindow *Window, int time){
    sf::Sprite PlayerSprite;
    PlayerSprite.setTexture(TPlayer::PlayerTexture);
    PlayerSprite.setPosition(TPlayer::X, TPlayer::Y);
    int CurrentFrame = (time%1000)/100;
    if (CurrentFrame > 9)
        CurrentFrame = 0;
    PlayerSprite.setTextureRect(sf::IntRect(35 * int(CurrentFrame), 0, 35, 50));
    Window->draw(PlayerSprite);
    }
}
