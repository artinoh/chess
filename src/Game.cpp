#include "Game.h"
#include "MainMenuState.h"


Game::Game() {
    data->window.create(sf::VideoMode(SCREEN_WIDTH,SCREEN_HEIGHT),"Chess",sf::Style::Close | sf::Style::Titlebar);
    data->machine.addState(stateRef(new MainMenuState(data)));

    init();
    run();
}

void Game::run() {
    while(data->window.isOpen()) {
        data->machine.processChanges();
        data->machine.getActiveState()->handleInput();
        data->machine.getActiveState()->update();
        data->machine.getActiveState()->draw();
    }
}

void Game::init() {
    loadMainMenuAssets();
    loadPieceAssets();
    loadOtherAssets();
}

void Game::loadMainMenuAssets() {
    //Load Main Menu Assets
    this->data->assets.loadTexture("Title", MAIN_MENU_TITLE_PATH);
    this->data->assets.loadTexture("Background", MAIN_BACKGROUND);
    this->data->assets.loadTexture("Play Button", MAIN_MENU_PLAY_BUTTON);
    this->data->assets.loadTexture("Exit Button", EXIT_BUTTON_FILE_PATH);
}

void Game::loadPieceAssets() {
    //Load White Pieces
    data->assets.loadTexture("White King", WHITE_KING_PATH);
    data->assets.loadTexture("White Queen", WHITE_QUEEN_PATH);
    data->assets.loadTexture("White Rook", WHITE_ROOK_PATH);
    data->assets.loadTexture("White Bishop", WHITE_BISHOP_PATH);
    data->assets.loadTexture("White Knight", WHITE_KNIGHT_PATH);
    data->assets.loadTexture("White Pawn", WHITE_PAWN_PATH);

    //Load Black Pieces
    data->assets.loadTexture("Black King", BLACK_KING_PATH);
    data->assets.loadTexture("Black Queen", BLACK_QUEEN_PATH);
    data->assets.loadTexture("Black Rook", BLACK_ROOK_PATH);
    data->assets.loadTexture("Black Bishop", BLACK_BISHOP_PATH);
    data->assets.loadTexture("Black Knight", BLACK_KNIGHT_PATH);
    data->assets.loadTexture("Black Pawn", BLACK_PAWN_PATH);
}

void Game::loadOtherAssets() {
    //Create Empty Tile
    sf::Texture emptySquare;
    emptySquare.create(100,100);
    this->data->assets.loadTexture("Empty Square", emptySquare);
}
