#include <SFML/Graphics.hpp>
#include <iostream>

// Define o caminho da fonte como uma constante
const std::string FONT_PATH = "/usr/share/fonts/truetype/dejavu/DejaVuSans.ttf";

int main() {
    // Cria a janela
    sf::RenderWindow window(sf::VideoMode(800, 600), "Escrevendo Texto com SFML");
    window.setFramerateLimit(60);

    // Carrega uma fonte
    sf::Font font;
    if (!font.loadFromFile(FONT_PATH)) { // Usa a constante FONT_PATH
        std::cerr << "Erro ao carregar a fonte em: " << FONT_PATH << std::endl;
        return -1;
    }

    // Configura o texto
    sf::Text text;
    text.setFont(font);                   // Define a fonte
    text.setString("Olá, SFML!");         // Define o texto a ser exibido
    text.setCharacterSize(50);            // Tamanho da fonte
    text.setFillColor(sf::Color::White);  // Cor do texto
    text.setStyle(sf::Text::Bold);        // Estilo do texto (negrito)
    text.setPosition(200.f, 250.f);       // Posição do texto na tela

    // Loop principal
    while (window.isOpen()) {
        sf::Event event;

        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Limpa a tela
        window.clear(sf::Color::Black);

        // Desenha o texto
        window.draw(text);

        // Atualiza a tela
        window.display();
    }

    return 0;
}

