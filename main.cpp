#include <SFML/Graphics.hpp>
#include <iostream>
#include <stdio.h>
#include <string>
#include <sstream>
#include <windows.h>
#include <stdlib.h>
#include <time.h>
#define RAND_MAX 30


 int GAMEOVER(int);
int main(){
    unsigned int GG = 0;
    unsigned char Speed = 20;
    srand(time(NULL));
    char KeyPressed;
    char LastKeyPressed;
    float FPS;
    int x = 15;
    int y = 15;
    int lenght = 5;
    int food_x, food_y;
    sf::Clock Clock;
    std::ostringstream oss;
    sf::String sFPS;
sf::RenderWindow window(sf::VideoMode(510,510),"Snake Prototype", sf::Style::Close);
window.setFramerateLimit(Speed);
window.display();
static sf::RectangleShape rect(sf::Vector2f(15, 15));
class Tile {
    public:
unsigned int x;
unsigned int y;
unsigned char state = 0;
unsigned char lenght = 0;


};
        Tile tileArray[31][31];
        int i = 1;
        int t = 1;
while(t <= 30){
    while(i <= 30){
            tileArray[i][t].x = (i*17)-16;
            tileArray[i][t].y = (t*17)-16;
            std::cout<<"x:  " << tileArray[i][t].x << "   y:  " << tileArray[i][t].y << std::endl;
            i++;
    }
    i = 1;
    t++;
}




t = 1;
i = 1;
KeyPressed = 1;
LastKeyPressed = 3;
            FOODGEN:
            food_x = (rand() % 29)+1; food_y = (rand() % 29)+1;
            if(tileArray[food_x][food_y].state == 1){goto FOODGEN;}
            if(tileArray[food_x][food_y].state != 1){tileArray[food_x][food_y].state = 2;}
            tileArray[x][y].state = 1;tileArray[x][y].lenght = lenght;
    while(window.isOpen()){


            window.clear();
            sf::Event event;
            while(window.pollEvent(event)){
                if(event.type == sf::Event::Closed){window.close();}
                if((event.type == sf::Event::KeyPressed)&&(event.key.code == sf::Keyboard::Escape)){window.close();}
                if((event.type == sf::Event::KeyPressed)&&(event.key.code == sf::Keyboard::Left)){KeyPressed = 4;}
                if((event.type == sf::Event::KeyPressed)&&(event.key.code == sf::Keyboard::Up)){KeyPressed = 3;}
                if((event.type == sf::Event::KeyPressed)&&(event.key.code == sf::Keyboard::Right)){KeyPressed = 2;}
                if((event.type == sf::Event::KeyPressed)&&(event.key.code == sf::Keyboard::Down)){KeyPressed = 1;}
                if((event.type == sf::Event::KeyPressed)&&(event.key.code == sf::Keyboard::Add)){Speed++;window.setFramerateLimit(Speed);}
                if((event.type == sf::Event::KeyPressed)&&(event.key.code == sf::Keyboard::Subtract)){Speed--;window.setFramerateLimit(Speed);}
            }



sf::RectangleShape rect(sf::Vector2f(15, 15));
while(t <= 30){
    while(i <= 30){

            if(tileArray[i][t].state == 1){rect.setPosition(tileArray[i][t].x, tileArray[i][t].y); rect.setFillColor(sf::Color(220, 40, 120)); tileArray[i][t].lenght--;
            if(tileArray[i][t].lenght < 1){tileArray[i][t].state = 0;} window.draw(rect);}
            if(tileArray[i][t].state == 2){rect.setPosition(tileArray[i][t].x, tileArray[i][t].y); rect.setFillColor(sf::Color(40, 255, 120)); window.draw(rect);}
            i++;
    }
    i = 1;
    t++;
}
t = 1;
i = 1;


////////////////////////////////////////////////////////
MOVE:
if(KeyPressed == 1 and LastKeyPressed != 3){if(y >= 30){y = 0;}LastKeyPressed = KeyPressed; y++;if(tileArray[x][y].state == 2){lenght++; goto FOODGEN;}if(tileArray[x][y].state == 1){GG = 1;}}
else if(KeyPressed == 2 and LastKeyPressed != 4){if(x >= 30){x = 0;}LastKeyPressed = KeyPressed; x++;if(tileArray[x][y].state == 2){lenght++; goto FOODGEN;}if(tileArray[x][y].state == 1){GG = 1;}}
else if(KeyPressed == 3 and LastKeyPressed != 1){if(y <= 1){y = 31;}LastKeyPressed = KeyPressed; y--;if(tileArray[x][y].state == 2){lenght++; goto FOODGEN;}if(tileArray[x][y].state == 1){GG = 1;}}
else if(KeyPressed == 4 and LastKeyPressed != 2){if(x <= 1){x = 31;}LastKeyPressed = KeyPressed; x--;if(tileArray[x][y].state == 2){lenght++; goto FOODGEN;}if(tileArray[x][y].state == 1){GG = 1;}}
else{KeyPressed = LastKeyPressed; goto MOVE;}
tileArray[x][y].state = 1;
tileArray[x][y].lenght = lenght;




    //      FPS COUNT

        FPS = 1/Clock.restart().asSeconds();
        oss<< "Snake Game by Andrius "<<"  FPS: "<<(int)FPS<< " opengl "<<window.getSettings().majorVersion<<"."<<window.getSettings().minorVersion;
        sFPS = oss.str();
        oss.str("");
        window.setTitle(sFPS);

        if(GG != 0){
    sf::Font font;
    sf::Text gameover;
    sf::Text score;
    if(!font.loadFromFile("game_over.ttf")){std::cout<<"Error Loading font"; return -1;}
    gameover.setFont(font);
    score.setFont(font);
    oss.str("");
    sFPS = "";
    oss<<"Score: "<<lenght-5;
    sFPS=oss.str();
    score.setString(sFPS);
    gameover.setString("Game Over");
    score.setCharacterSize(100);
    score.setColor(sf::Color::Yellow);
    gameover.setCharacterSize(200);
    gameover.setColor(sf::Color::Yellow);
    gameover.setPosition(sf::Vector2f(50, 30));
    score.setPosition(sf::Vector2f(255, 200));
    window.draw(gameover);
    window.draw(score);
    window.display();
while(window.isOpen()){
        while(window.pollEvent(event)){
    if(event.type == sf::Event::Closed){window.close();}
    if((event.type == sf::Event::KeyPressed)&&(event.key.code == sf::Keyboard::Escape)){window.close();}
        }
    sf::sleep(sf::milliseconds(50));
}
        }
                window.display();
    }
return 1;
}
