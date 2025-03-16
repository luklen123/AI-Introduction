
# Tic-Tac-Toe with AI (Minimax & Alpha-Beta Pruning)

## Overview
This is a Tic-Tac-Toe game implemented in C++ that features an AI opponent using the **Minimax algorithm with Alpha-Beta Pruning**. The program allows players to choose different game modes, including:
- **Two human players** (PvP)
- **Human vs AI** (Player starts first)
- **AI vs Human** (AI starts first)
- **AI vs AI** (Watch two bots play against each other)

## Features
- **Minimax Algorithm**: Ensures the AI makes the best possible moves.
- **Alpha-Beta Pruning**: Optimizes the Minimax algorithm by eliminating unnecessary branches, significantly improving efficiency (with pruning: 14,853 computations, without pruning: 286,949 computations).
- **Flexible Game Modes**: Choose to play against another player, an AI, or watch two AIs compete.
- **Simple Console Interface**: The game runs in the terminal with easy-to-follow prompts.

## How to Run
1. Clone the repository:
   ```sh
   git clone https://github.com/yourusername/tic-tac-toe-ai.git
   cd tic-tac-toe-ai
   ```
2. Compile the program:
   ```sh
   g++ -o tictactoe main.cpp
   ```
3. Run the program:
   ```sh
   ./tictactoe
   ```
4. Follow the on-screen instructions to select the game mode and play.

## Controls
- Players input their moves using **X, Y coordinates** (1-based index).
- The AI will automatically make its move after the player's turn.

## Future Improvements
- Implement a GUI version.
- Support for larger board sizes (e.g., 4x4, 5x5).

---
Enjoy the game and have fun playing Tic-Tac-Toe with AI! 😊

