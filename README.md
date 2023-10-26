# :clipboard: So_long | 42 SP
- Actual Status : finished.
- Result        : Approved with 105 points by moulinette (the 42 tester) ✅
  
  So_long is the fifthy project at 42.
This project is a very small 2D game. Its purpose is to make you work with textures, sprites,
and some other very basic gameplay elements..

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
| ``ft_putnbr.c`` | Contains the functions that deal with hexadecimal, decimal, integers numbers and pointers. |
| ``ft_printf.c`` | Contains the principal function: the function who deal with the type of data. Also contains the function who checks if is a conversion to deal with and the functions to deal with char or strings|
| ``ft_printf.h`` | The header with functions libraries and prototypes. |
| ``ft_printf_bonus.c`` | Contains the principal function: the function who deal with the type of data. Also contains the function who checks if is a conversion to deal with and the functions to deal with char or strings|
| ``ft_putnbr_bonus.c`` | Contains the functions that deal with hexadecimal, decimal, integers numbers and pointers. |
| ``ft_flags_bonus.c`` | Contains the functions that deal with the flags. |
| ``ft_printf_bonus.h`` | The header with functions libraries and prototypes. |
| ``Makefile`` | The automatizated compilator|

## :star: Bonus
Make the player lose when they touch an enemy patrol

## 🛠️ Usage

In order to use the MLX42 of Codam, you must follow the rules in this repository
https://github.com/codam-coding-college/MLX42

Then you 
``` shell
$> git clone https://github.com/NataliMRocha/Printf-42.git
$> cd Printf-42
$> make
```

