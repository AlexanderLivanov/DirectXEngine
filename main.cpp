#include "SFML/Graphics.hpp"
#include "GLFW/glfw3.h"

using namespace std;

int main(){
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "3D Engine", sf::Style::Titlebar | sf::Style::Close);
    window.setFramerateLimit(60);
    getchar();
    return 0;
}