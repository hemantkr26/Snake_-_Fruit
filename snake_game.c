#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ncurses.h>

#define WIDTH 20
#define HEIGHT 20

int gameOver;
int x, y, fruitX, fruitY, score, highScore; // Declaration of highScore variable
enum eDirection { STOP = 0, LEFT, RIGHT, UP, DOWN };
enum eDirection dir = STOP; // Initialize direction to STOP initially

void Setup() {
    gameOver = 0;
    x = WIDTH / 2;
    y = HEIGHT / 2;
    fruitX = rand() % WIDTH;
    fruitY = rand() % HEIGHT;
    score = 0;

    FILE *file = fopen("highscore.txt", "r");
    if (file) {
        fscanf(file, "%d", &highScore);
        fclose(file);
    } else {
        highScore = 0;
    }
}

void Draw() {
    clear();

    // Draw top wall
    for (int i = 0; i < WIDTH + 2; i++)
        mvprintw(0, i, "#");

    // Draw bottom wall
    for (int i = 0; i < WIDTH + 2; i++)
        mvprintw(HEIGHT + 1, i, "#");

    // Draw left and right walls
    for (int i = 1; i <= HEIGHT; i++) {
        mvprintw(i, 0, "#");
        mvprintw(i, WIDTH + 1, "#");
    }

    // Draw the snake
    attron(COLOR_PAIR(1));
    mvprintw(y, x, "O");
    attroff(COLOR_PAIR(1));

    // Draw the fruit
    attron(COLOR_PAIR(2));
    mvprintw(fruitY, fruitX, "F");
    attroff(COLOR_PAIR(2));

    // Draw the score and high score
    mvprintw(HEIGHT + 3, 0, "Score: %d", score);
    mvprintw(HEIGHT + 4, 0, "High Score: %d", highScore);

    // Refresh the screen
    refresh();
}

int main() {
    srand(time(NULL));

    // Initialize ncurses
    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);
    start_color();
    init_pair(1, COLOR_GREEN, COLOR_BLACK); // Snake color
    init_pair(2, COLOR_RED, COLOR_BLACK);   // Fruit color

    Setup();

    while (!gameOver) {
        Draw();

        // Check for user input and update the snake's direction
        int ch = getch();
        switch (ch) {
            case KEY_LEFT:
                dir = LEFT;
                break;
            case KEY_RIGHT:
                dir = RIGHT;
                break;
            case KEY_UP:
                dir = UP;
                break;
            case KEY_DOWN:
                dir = DOWN;
                break;
            case 'x':
                gameOver = 1;
                break;
        }

        // Update snake's position based on direction
        switch (dir) {
            case LEFT:
                x--;
                break;
            case RIGHT:
                x++;
                break;
            case UP:
                y--;
                break;
            case DOWN:
                y++;
                break;
            default:
                break;
        }

        // Check for collision with the walls
        if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
            gameOver = 1;

        // Check if the snake eats the fruit
        if (x == fruitX && y == fruitY) {
            score += 10;
            if (score > highScore) {
                highScore = score;
                FILE *file = fopen("highscore.txt", "w");
                if (file) {
                    fprintf(file, "%d", highScore);
                    fclose(file);
                }
            }
            fruitX = rand() % WIDTH;
            fruitY = rand() % HEIGHT;
        }
    }

    // Cleanup ncurses
    endwin();
    return 0;
}
