#include <SFML/Graphics.hpp>
#include <iostream>

// Define o caminho da fonte como uma constante
const std::string FONT_PATH = "/usr/share/fonts/truetype/dejavu/DejaVuSans.ttf";

// Função para verificar se o mouse está sobre um retângulo 
bool isMouseOver(const sf::RectangleShape& rect, const sf::RenderWindow& window) {

     // Posição do mouse na janela
    sf::Vector2i mousePos = sf::Mouse::getPosition(window);

    // Posição do retângulo que será o botão
    sf::Vector2f rectPos = rect.getPosition();

    // Pegar o tamanho do botão
    sf::Vector2f rectSize = rect.getSize();

    // Retornamos a posição do mouse | em um bool
    return mousePos.x >= rectPos.x && mousePos.x <= rectPos.x + rectSize.x &&
       mousePos.y >= rectPos.y && mousePos.y <= rectPos.y + rectSize.y;
}

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

    // Cria o botão (retângulo)
    sf::RectangleShape button(sf::Vector2f(200.f, 60.f)); // Tamanho do botão 

    // Posição do botão
    button.setPosition(300.f, 250.f);

    // Cor do botão
    button.setFillColor(sf::Color::Blue);

    // Rótulo do botão
    sf::Text buttonText;
    sf::Text secondText; 

    // Definições da FONT do botão
    buttonText.setFont(font);
    buttonText.setString("Botão");
    buttonText.setCharacterSize(30);
    buttonText.setFillColor(sf::Color::White);
    buttonText.setStyle(sf::Text::Bold);
    
    // secondText.setFont(font);
    // secondText.setString("Botão");
    // secondText.setCharacterSize(30);
    // secondText.setFillColor(sf::Color::White);
    // secondText.setStyle(sf::Text::Bold);


    // Centraliza o botão
    sf::FloatRect textBounds = buttonText.getLocalBounds();

    // Colocar o botão centralizado 
    buttonText.setPosition(
        button.getPosition().x + (button.getSize().x - textBounds.width) / 2.f,
        button.getPosition().y + (button.getSize().y - textBounds.height) / 2.f - 5.f
    );


    // Configura o texto que aparece na tela.
    sf::Text text;
    text.setFont(font);                   // Define a fonte
    text.setString("Hello, World!");      // Define o texto a ser exibido
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

