Description
This project is a game similar to "Plants vs Zombies", but adapted to contain much simpler geometry. The goal of the game is to place diamonds in the path of advancing hexagons to destroy them before they reach the edge of the screen and reduce your life.

System Requirements
Operating System: Windows, macOS, Linux
GPU with OpenGL 3.3 support or newer
Keyboard and mouse

Installation and Launch
Clone or download this repository to your computer.
Make sure you have a C++ compiler and OpenGL library installed.
Compile and run the source code using a C++ development environment (e.g., Visual Studio for Windows, Xcode for macOS, or g++ for Linux).

Gameplay
The objective of the game is to place diamonds in the available cells to destroy the advancing hexagons.
Hexagons will appear at random intervals and move along the lines.
You can collect stars to obtain the resources needed for placing diamonds.
Each type of diamond costs a certain number of stars.
Be careful to place the diamonds in strategic positions to block the advance of hexagons and destroy them before they reach the edge of the screen.

Controls
Use the mouse to select and place diamonds.
Press the left button to select and drag a diamond into the desired cell.
Press the right button to delete a diamond from a cell.

Project Structure
main.cpp: The main file of the application, which contains the display functions and game logic.
geom.hpp: The file containing geometric definitions for objects in the game (diamonds, hexagons, stars, etc.).
utils.hpp: The file with utility functions, such as collision detection and mouse event handling.
textures/: The directory containing textures used for objects in the game.
shaders/: The directory containing OpenGL shaders for rendering objects.
fonts/: The directory containing fonts used for displaying text in the user interface.

Conclusion
The "Diamonds vs Hexagons" game is a simplified version of the classic "Plants vs Zombies", offering a fun and engaging experience. Place diamonds strategically, collect resources, and defeat the horde of hexagons to win the game!

Enjoy your gaming experience! 🎮🚀
