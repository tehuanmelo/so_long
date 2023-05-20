# So_Long

So_Long is a 2D game project developed as part of the 42 curriculum. 
It is a simple game where the player must navigate through a map, collect items, and reach the exit while avoiding obstacles.

## Table of Contents
- [Getting Started](#getting-started)
- [Usage](#usage)
- [Game Controls](#game-controls)
- [Map Fprmat](#map-format)
- [Example Map](#example-map)
- [Game Play](#game-play)
- [Support](#support)
- [Acknowledgments](#acknowledgments)

## Getting Started

Installing the `So_long` can be done in a few simple steps:

1. Clone the project from the project's GitHub repo.

2. Open a terminal and navigate to the directory where the files were cloned.

3. Run the following command to compile the game:


````
make
````
This will create a `./so_long` file in the directory, which is the compiled game that you can play.

4. Start the game by running the following command:

```
./so_long maps/map.ber
```

## Usage

The goal of the game is to collect all the collectible items ('C') 
on the map and reach the exit ('E') without colliding with the obstacles ('1') 
or enemies ('X'). The player character is represented by the player icon ('P').

Use the arrow keys to move the player character around the map. 
The game ends when the player collects all the items and reaches the exit.

## Game Controls

- Use the `arrow keys` to move the player character up, down, left, or right.
- Press `ESC` key or close the game window to quit the game.

## Map Format

The map for the So_Long game is provided in a text file with a .ber extension. The map should consist of the following elements:

- '0': Empty space.
- '1': Wall or obstacle.
- 'C': Collectible item.
- 'E': Exit.
- 'P': Player character starting position.

## Example Map

Here is an example of a So_Long map:
```
111111
100101
1P00E1
111C11
```

## Game Play


## Support

Feel free to contact me on slack or via email

email - `tehuanmelo@gmail.com`

twitter - `@tehuanmelo`

slack - `tde-melo`

## Acknowledgments
I would like to express my sincere gratitude to @42AbuDhabi , and all of the staff members and who have supported me throughout my journey here.
