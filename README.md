# Snake & Fruit Game in C on Linux

Description:

The snake and fruit game is a classic arcade-style game where the player controls a snake that moves around the screen, eating fruit to attain highscore while avoiding collisions with the walls of the game area or with its own tail. Here's how the game could be implemented using C on the Kali Linux platform, integrating various programming concepts:

Data Structures:
Snake Data Structure: You can represent the snake using an array of structures or linked lists. Each element of the array or node in the linked list would contain information about the position of the snake segment on the game grid.
Fruit Data Structure: Similar to the snake, you can represent the fruit using a structure containing its position on the game grid.

Arrays:
Arrays will be utilized to represent the game grid, where each cell can be empty, contain part of the snake, or a fruit. Additionally, arrays will store the direction of the snake's movement.

Loops:
Main Game Loop: The main loop of the game will continuously update the game state, handle user input, move the snake, check for collisions, and update the score.
Snake Movement Loop: Within the main loop, there will be a loop responsible for moving the snake. This loop will iterate through each segment of the snake, updating its position based on the direction of movement.
Collision Detection Loop: Another loop will be used to check for collisions between the snake, the walls, and the fruit. If a collision is detected, appropriate actions will be taken (e.g.spawning a new fruit, ending the game).
Conditional Statements:

Directional Input Handling: Conditional statements will be used to determine the direction in which the snake moves based on user input (e.g., arrow keys or WASD keys).
Collision Detection: Conditional statements will be used to check if the snake collides with the walls of the game area, its own tail, or the fruit.
Score Update: Conditional statements will determine when to update the player's score, typically when the snake eats a fruit.
Dynamic Memory Allocation:

You may use dynamic memory allocation, especially if you choose to represent the snake using a linked list data structure. This would allow the snake to grow dynamically as it eats fruits without the need to define a maximum length.

Conclusion:
By integrating data structures, arrays, loops, conditional statements, and potentially dynamic memory allocation, you can create a fully functional snake and fruit game in C on the Kali Linux platform. This project provides an excellent opportunity to practice fundamental programming concepts while creating an enjoyable game experience.
