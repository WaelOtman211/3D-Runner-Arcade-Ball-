# 3D-Runner-Arcade-Ball

Final project for my practical software engineering diploma.
A 3D developed game with C/C++ and OpenGL.
It is about developing a system in OPENGL that deals with 3D vision
The system / game Runner Arcade Ball is an arcade game in which there is a long and swinging space, the space contains additional elements:

• Obstacles (pits, walls).

• Coins - which actually increases the player's score.

• Clock – adds time to continue the game and win a high score.

The user/player must move from the obstacles and pass them successfully.
The space can be moved, and when you move it the ball is affected by the displacement and moves in the direction according to the change of space (swinging to the right / left).

There is a certain time in each stage (Level), if the time is over and he did not lose, then he moves to the second stage.
The player must get as many points (Coins) as possible.
The more the player has won Clock (time) that is in the space, then he adds time to continue playing, and thus he will have the possibility to get more Score (Coins).

As soon as he lost, we immediately save the game details for him in a file (how many points (Score) he got, to what stage he reached).
