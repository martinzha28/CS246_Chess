<h1 align="center"> CS246 Final Project: Chess </h1>
<!------------------------------------------------------------------------------------------------------------------------------------------------->
<h2> Introduction </h2>

Chess is a tabletop board game consisting of 16 pieces, played on an 8x8 checkerboard. By the instructions provided within the CS246 A5 Chess Project guidelines, this checkerboard is laid out with the white square at position “H8” in the bottom right. The game follows the rules outlined by traditional chess, and the end goal is to win the game by forcing your opponent to make a series of moves that results in a checkmate. A draw is determined by a stalemate, a resignation by one player results in a win for their opponent, and score is kept between each color (“White” or “Black”). A computer player has been designed to play this game as well, either against another computer, or against a human. 2 humans may also play against one another.

<!------------------------------------------------------------------------------------------------------------------------------------------------->

<h2> Instructions on How to Play </h2>

After forking the repository, simply run `make` in the command line to compile the entire program. Afterwards, run `./chess` to run the program.

<h3> Display </h3>

The text-based display is as follows:
```
8 rnbqkbnr
7 pppppppp
6 _ _ _ _
5 _ _ _ _
4 _ _ _ _
3 _ _ _ _
2 PPPPPPPP
1 RNBQKBNR
  abcdefgh
```
The White pieces are always capitalized and the black pieces are always in lower case. After every move, the display is updated along with several possibilities for messages: a player is in check, has won, or a draw. Afterwards, the score is displayed.

<h3> Commands </h3>

- `game white-player black-player` starts a new game. The parameters `white-player`, `black-player` can either be `human` or `computer[1-2]`.
  - To play 2 humans, we can run `game human human`. If you want to play black versus a computer, we can type `game computer1 human`.
- `resign` concedes the game to the opponent. This is the only way, outside of winning or drawing, to end the game.
- A move consists of the command `move` followed by the starting and edning coordinates of the piece to be moved. For example, `move e2 e4`.
  - Pawn promotion would additionally specify the piece type to whicht he pawn is promoted: `move e7 e8 Q`.
  - In the case of a computer player, the command `move` without arguments makes the computer player make a move.
- `setup` enters setup mode, within which you can set up your own initial board conifgurations. This can only be done when a game is not currently running. Within setup mode, the following language is used:
  - `+ K e1` places the piece `K` on the square `e1`. If a piece is already on that square, it is replaced.
  - `- e1` removes the piece from the square.
  - `= colour` make it colour's turn to go next.
  - `done` to leave setup move.
  - The board must contain exactly one white king and exactly one black king. No pawns can be on the promotion row, and neither king is in check. The user cannot leave setup mode until all conditions are satisfied.


<h2> UML Diagram </h2>

![Updated UML Diagram](uml.jpg)


<h2> Documents </h2>

<a href="chess.pdf">Instructions</a>
<br>
<a href="design.pdf">Design</a>
<br>
<a href="UML.jpg">UML Diagram</a>
<br>



