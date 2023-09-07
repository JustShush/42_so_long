# 42 So_long

<table>
<tr>
<td>
	1. <a href="https://github.com/JustShush/42_so_long#%EF%B8%8F-requirements">Requirements</a><br>
	2. <a href="https://github.com/JustShush/42_so_long#%EF%B8%8F-installation">Installation</a><br>
	3. <a href="https://github.com/JustShush/42_so_long#-running">Running</a><br>
	4. <a href="https://github.com/JustShush/42_so_long#-game-rules">Game Rules</a><br>
</td>
</tr>
</table>

## ✔️ Requirements
* Linux
* MinilibX only support TrueColor visual type (8,15,16,24 or 32 bits depth)
* gcc
* make
* X11 include files (package xorg)
* XShm extension must be present (package libxext-dev)
* Utility functions from BSD systems - development files (package libbsd-dev)
* e.g. sudo apt-get install gcc make xorg libxext-dev libbsd-dev (Debian/Ubuntu)

<br>

## 🛠️ Installation
```sh
git clone https://github.com/42Paris/minilibx-linux.git
mv minilibx-linux mlx_linux
cd mlx_linux && make
cd .. && git clone https://github.com/JustShush/42_so_long.git
cd 42_so_long && make
```

### all in one command
```sh
git clone https://github.com/42Paris/minilibx-linux.git;mv inilibx-linux mlx_linux;cd mlx_linux && make;cd .. && git clone https://github.com/JustShush/42_so_long.git;cd 42_so_long && make
```

## 🎮 Running
Run the executable file followed by a valid map file, at the root of the `so_long` directory. Example:
```Shell
$ ./so_long maps/map1.ber
```

### Using your own map files

You can run the game with a custom map file as long as it follows the <a href="https://github.com/WudDoo/so_long#-game-rules">Game Rules</a>.

<br>

## 📝 Game Rules

The executable so_long will receive a map as the only argument, and this map must have a `.ber` filetype.

The file also must follow these rules:

* The only accepted characters are:
	* `P` (player)
	* `1` (wall)
	* `0` (empty)
	* `C` (collectible)
	* `E` (exit)

* The map must be rectangular, i.e. all rows must have the same length
* There must be only one exit and one player, and at least one collectible in the map
* The map must be surrounded by walls
* There must be a valid path the player can take from the starting position, to the exit, collecting all colletibles.

<br>

If any of these checks fail, the game will end with `Error\n` followed by a custom message.

The goal is for the player( to collect all the collectibles on the map before going to an exit in the least possible number of steps