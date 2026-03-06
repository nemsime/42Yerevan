# so_long

**so_long** is a small 2D game written in **C** using the **MiniLibX graphics library**.
This project is part of the **42 School Common Core** and introduces the basics of graphics programming, event handling, map parsing, and simple game logic.

The goal of the game is to collect all collectibles on the map and reach the exit using the smallest number of moves.

---

# Features

* 2D tile-based rendering
* Player movement
* Collectible system
* Exit that opens after collecting all items
* Map validation
* Keyboard input handling
* Move counter in terminal
* Error handling

---

# Game Rules

The program receives a **map file (.ber)** as an argument.

Example:

```
./so_long maps/map.ber
```

## Allowed map characters

| Character | Description           |
| --------- | --------------------- |
| `1`       | Wall                  |
| `0`       | Empty space           |
| `P`       | Player start position |
| `C`       | Collectible           |
| `E`       | Exit                  |

## Map requirements

* The map must be **rectangular**
* The map must be **surrounded by walls**
* The map must contain:

  * **1 player**
  * **at least 1 collectible**
  * **at least 1 exit**
* There must be a **valid path** to collect all collectibles and reach the exit
* No invalid characters are allowed

---

# Controls

| Key | Action        |
| --- | ------------- |
| W   | Move up       |
| A   | Move left     |
| S   | Move down     |
| D   | Move right    |
| ESC | Exit the game |

---

# Installation

Clone the repository:

```
git clone https://github.com/nemsime/42Yerevan.git
cd 42Yerevan/so_long
```

---

# Install MiniLibX

### Linux

Install required dependencies:

```
sudo apt update
sudo apt install gcc make xorg libxext-dev libbsd-dev
```

Clone MiniLibX:

```
git clone https://github.com/42Paris/minilibx-linux.git
```

Compile MiniLibX:

```
cd minilibx-linux
make
cd ..
```

---

# Compile the Project

```
make
```

---

# Run the Game

```
./so_long maps/map.ber
```

Example:

```
./so_long maps/map1.ber
```

---

# Makefile Commands

```
make        compile the project
make clean  remove object files
make fclean remove object files and executable
make re     recompile the project
```

---

# Technologies Used

* C
* MiniLibX
* X11
* Makefile
* libft

---

