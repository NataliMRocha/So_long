# :clipboard: So_long | 42 SP
- Actual Status: finished.
- Result      : Approved with 105 points ✅

  :us: So_long is the fifthy project at 42.
This project is a very small 2D game. Its purpose is to make you work with textures, sprites,
and some other very basic gameplay elements...

  	:brazil: So_long é o quinto projeta da 42.
  Esse projeto é um joquinho em 2D. O objetivo é trabalhar com texturas, sprites, e alguns
  elementos básicos de gameplay!
  
<div align="center">
   
![So_long](https://github.com/NataliMRocha/gifs/blob/master/So_long.gif)

</div>

#
#### We need to implement the following rules:

• The player’s goal is to collect every collectible present on the map, then escape
chosing the shortest possible route.  
• The W, A, S, and D keys must be used to move the main character.  
• The player should be able to move in these 4 directions: up, down, left, right.  
• The player should not be able to move into walls.  
• At every move, the current number of movements must be displayed in the shell.  
• The management of your window must remain smooth (changing to another window, minimizing, and so forth).  
• Pressing ESC or clicking on the cross on the window’s framemust close the window and quit the program in a clean way.  
• The map has to be constructed with 3 components: walls, collectibles, and free
space.  
• The map can be composed of only these 5 characters:
0 for an empty space,
1 for a wall,
C for a collectible,
E for a map exit,
D for the devil,
P for the player’s starting position.  
• The map must contain 1 exit, at least 1 collectible, and 1 starting position to
be valid.  
• The map must be rectangular.  
• You must be able to parse any kind of map, as long as it respects the above rules.  

## 📝 Functions

| Files | Description |
| :------: | :---------: |
| ``so_long.h`` | The header with functions libraries and prototypes.|
| ``so_long.c`` | Contains the main. |
| ``validation.c`` | Contains the functions that validate the input. |
| ``map.c`` | Contains the fuctions to validate and allocate de map.|
| ``init.h`` | Contains the functions who load images, create the window and put this images in window in accordance with the map .|
| ``move.c`` | Contains the functions who make the player moves or collect thing, also check if the game is over.|
| ``messages.c`` | Contains the messages of error or end game.|
| ``close.c`` | Contains the functions who free all allocate memory and close the game.|
| ``Makefile`` | The automatizated compilator|

## :star: Bonus
Make the player lose when they touch an enemy patrol

## 🛠️ Usage

In order to use the MLX42 of Codam, you must follow the rules in this repository
https://github.com/codam-coding-college/MLX42

Then you can run this commands below 
``` shell
$> make
$> ./so_long ./map/path_of_the_map
```
• For moves the player you can use the arrow keys or WASD
• You need to collect all the collectibles and only then the oasis will appear
• The objective is to reach the end of the game with the fewest moves 
• You can use any valid map on the directory maps or you can create new maps
