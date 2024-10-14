#pragma once
#include "Game.h"
#include "Square.h"

//
// the classic game of tic tac toe
//

//
// this is the AI class
// we use a small clone here so we can recursively call minimax
//
struct TicTacToeAI
{
    int   _grid[3][3];
    bool isBoardFull() const;
    int evaluateBoard();
    int evaluateBoardMinimax();
    int minimax(TicTacToeAI* state, int depth, bool isMaximizingPlayer);
    int negamax(TicTacToeAI* state, int depth, int playerColor);
    int ownerAt(int index ) const;
    int AICheckForWinner();
};

//
// the main game class
//
class TicTacToe : public Game
{
public:
    TicTacToe();
    ~TicTacToe();

    // set up the board
    void        setUpBoard() override;
    void        drawFrame() override;

    Player*     checkForWinner() override;
    bool        checkForDraw() override;
    std::string initialStateString() override;
    std::string stateString() const override;
    void        setStateString(const std::string &s) override;
    bool        actionForEmptyHolder(BitHolder *holder) override;
    bool        canBitMoveFrom(Bit*bit, BitHolder *src) override;
    bool        canBitMoveFromTo(Bit* bit, BitHolder*src, BitHolder*dst) override;
    void        stopGame() override;

    TicTacToeAI* clone();
	void        updateAI() override;
    bool        gameHasAI() override { return true; }
private:
    Bit *       PieceForPlayer(const int playerNumber);
    Player*     ownerAt(int index ) const;

    void        scanForMouse();
    Square      _grid[3][3];
};

