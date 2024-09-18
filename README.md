# Rock, Paper, Scissors Game in C++ [Procedural Programming]
This project is a console application of the classic **Rock, Paper, Scissors** game written in C++. It allows the player to compete against the computer in multiple rounds. The game is simple, intuitive, and displays detailed round-by-round results and final game outcomes.

## Table of Contents
- [Project Information](#Project-Information)
- [Live Demo](#Live-Demo)
- [Features](#features)
- [How It Works](#how-it-works)
- [Game Flow](#game-flow)

## Project Information
This math quiz game project was created at the end of the [5th course](https://programmingadvices.com/p/00316b1111) from the Roadmap for General Foundation in Programming @ [Programming Advices](https://programmingadvices.com/).

## Live Demo
https://github.com/user-attachments/assets/54b76a82-a87a-4d42-99f0-19bbb83e8a29

## Features
- **Multiple Rounds**: Play up to 10 rounds against the computer.
- **Randomized Computer Choices**: The computer’s choices are randomized each round.
- **Game Summary**: After each round, results are displayed with the choices and winner.
- **Final Game Results**: A game summary is shown after all rounds, declaring the overall winner (Player, Computer, or Draw).
- **Replay Option**: After the game is over, the player is given the option to replay.

## How It Works
1. **Player Input**: The player chooses either Stone, Paper, or Scissors.
2. **Computer Choice**: The computer randomly selects its choice.
3. **Determine Winner**: The game compares the player and computer’s choices to determine the round’s winner based on the classic rules:
   - Stone stronger than Scissors
   - Scissors  stronger than Paper
   - Paper  stronger than Stone
4. **Display Results**: The results of each round, including the choices and the winner, are displayed.
5. **End of Game**: After the designated number of rounds, the game displays the final results, indicating how many rounds each player won, the number of draws, and the overall game winner.

## Game Flow
- At the start, the player is prompted to enter how many rounds they want to play (between 1 and 10).
- For each round, the player chooses one of the three options (Stone, Paper, Scissors).
- The computer makes a random choice for each round.
- The result of each round is shown immediately after.
- At the end of the game, a summary is displayed with the overall winner.
- The player is asked if they want to play again.


