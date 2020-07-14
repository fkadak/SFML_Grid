#include <SFML/Graphics.hpp>
#include <vector>
#include <cstring> 
using namespace std;

int main(){
    sf::RenderWindow window(sf::VideoMode(1200, 1000), "test");
    
    sf::Color DarkGray(44, 47, 51);
    sf::Color LightGray(153, 170, 181);

    sf::Font font;
    font.loadFromFile("Inter-Regular.ttf");
    sf::Text text;
    text.setFont(font);
    text.setCharacterSize(24);
    text.setFillColor(LightGray);
    text.move(sf::Vector2f(1100.f, 50.f));
    
    sf::RectangleShape minus(sf::Vector2f(25.f, 25.f));
    sf::RectangleShape plus(sf::Vector2f(25.f, 25.f));
    sf::RectangleShape plusV(sf::Vector2f(5.f, 25.f));
    sf::RectangleShape plusH(sf::Vector2f(25.f, 5.f));
    sf::RectangleShape minusH(sf::Vector2f(25.f, 5.f));
    plusV.setFillColor(LightGray);
    plusH.setFillColor(LightGray);
    minusH.setFillColor(LightGray);
    
    minus.move(sf::Vector2f(1070.f, 80.f));
    plus.move(sf::Vector2f(1130.f, 80.f));
    plusV.move(sf::Vector2f(1140.f, 80.f));
    plusH.move(sf::Vector2f(1130.f, 90.f));
    minusH.move(sf::Vector2f(1070.f, 90.f));
        
    int cells;
    cells = 20;
    int cellSize;
    cellSize = 1000 / cells;

    vector <vector<bool>> gridFill(cells);
    for(int i = 0; i < cells; i++)
        for(int j = 0; j < cells; j++)
            gridFill[i].push_back(false);

    while(window.isOpen()){
        sf::Event event;
        while(window.pollEvent(event)){
            if(event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::MouseButtonPressed){
                sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
                int x = mousePosition.x;
                int y = mousePosition.y;
                
                if(x < 1000 && x >= 0 && y < 1000 && y >= 0)
                    gridFill[x / cellSize][y / cellSize] = !gridFill[x / cellSize][y / cellSize];

                if(x >= 1130 && x <= 1155 && y >= 80 && y <= 105){
                    cells++;
                    cellSize = 1000 / cells;
                    vector<bool> tmp(cells, 0);
                    gridFill.push_back(tmp);
                    for(int i = 0; i < cells - 1; i++)
                        gridFill[i].push_back(false);
                }

                if(x >= 1070 && x <= 1095 && y >= 80 && y <= 105){
                    if(cells == 1) continue;
                    cells--;
                    cellSize = 1000 / cells;
                    vector<bool> tmp(cells);
                    for(int i = 0; i < cells; i++)
                        gridFill[i].resize(cells);
                    gridFill.resize(cells);
                }
            }
        }
        window.clear(DarkGray);

        string s = to_string(cells);
        text.setString(s);
        
        vector <vector <sf::RectangleShape>> pieces(cells);
        for(int i = 0; i < cells; i++){
            for(int j = 0; j < cells; j++){
                sf::RectangleShape curr(sf::Vector2f(cellSize - 1, cellSize - 1));
                pieces[i].push_back(curr);
                if(gridFill[i][j]) continue;
                
                pieces[i][j].setFillColor(sf::Color::White);

                pieces[i][j].move(sf::Vector2f(i * cellSize, j * cellSize));
                window.draw(pieces[i][j]);
            }
        }
        window.draw(plusV);
        window.draw(plusH);
        window.draw(minusH);
        window.draw(text);
        window.display();
    }
    return 0;
}
