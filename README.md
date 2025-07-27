![cub3d](https://github.com/user-attachments/assets/4dca35d8-d343-431a-82c2-601fbb338da4)

---

## 🇬🇧 Cub3d

Cub3d is a 3D rendering engine inspired by Wolfenstein 3D, coded in C.  
The project uses a custom raycasting algorithm developed entirely from scratch. While functional, it is not perfect and may have some inaccuracies or limitations.

The engine features a multi-layering system allowing the display and animation of several layers, including vertically animated doors (top to bottom).

### Main Features

- **Custom Raycasting**: The raycasting algorithm is coded without external libraries. It can be improved and is not free from flaws.
- **Multi-layering**: Simultaneous display of several layers (animated doors, etc.)
- **Animated Doors**: Doors are animated from top to bottom for a more dynamic effect.
- **All subject bonuses**: Dynamic mini-map, advanced texture and effects management, interactive animated doors, and much more.

### Quick Start

#### Compilation

```bash
make
```

#### Launch

```bash
./cub3d maps/ma_map.cub
```

### Map File Structure

Map files are in the `maps` folder and use the following characters:

#### Header:
- `NO sprites/wall1.xpm`  : North texture
- `SO sprites/wall2.xpm`  : South texture
- `WE sprites/wall3.xpm`  : West texture
- `EA sprites/wall4.xpm`  : East texture
- `DO sprites/door.xpm`   : Door texture

- `F 220,100,0`           : Floor color
- `C 225,30,0`            : Ceiling color

#### Map:
- `1` : Wall
- `0` : Floor
- `D` : Animated door (multi-layer)
- `N`, `S`, `E`, `W` : Player position and orientation

#### Example

```
NO sprites/wall1.xpm
SO sprites/wall2.xpm
WE sprites/wall3.xpm
EA sprites/wall4.xpm
DO sprites/door.xpm

F 220,100,0
C 225,30,0

        1111111111111111111111111
        1000000000110000000000001
        1011000001110000000000001
        1001000000000000000000001
111111111011000001110000000000001
100000000011000001110111111111111
11110111111111011100000010001
11110111111111011101010010001
11000000110101011100000010001
10000000000000001100000010001
10000000000000001101010010001
11000001110101011111011110N0111
11110111 1110101 101111010001
11111111 1111111 111111111111
```

### Bonuses and Innovations

- Vertical door animation.
- Mouse support on 2 axes.
- Advanced multi-layering management.
- Dynamic minimap.
- Multiple modes (Press M to see).

### Authors

This project was created by:

    LolelsayFR | Emaillet
    UnGarsRandom | Artgirar

---

## 🇫🇷 Cub3d

Cub3d est une implémentation d’un moteur de rendu 3D inspiré de Wolfenstein 3D, codée en C.  
Le projet utilise un algorithme de raycasting développé entièrement à la main, bien que ce dernier soit loin d’être parfait et puisse présenter quelques imprécisions ou limitations.

Le moteur intègre un système de multi-layering permettant l’affichage et l’animation de plusieurs couches de portes, notamment des animations verticales (de haut en bas).

### Fonctionnalités principales

- **Raycasting fait maison** : L’algorithme de raycasting est codé sans bibliothèque externe, mais il n’est pas exempt de défauts et peut être amélioré.
- **Multi-layering** : Affichage simultané de plusieurs couches (portes animées, etc.)
- **Portes animées** : Les portes s’animent de haut en bas pour un rendu plus dynamique.
- **Tous les bonus du sujet** : Mini-map, gestion avancée des textures et des effets, portes interactives animées, et plus encore.

### Démarrage rapide

#### Compilation

```bash
make
```

#### Lancement

```bash
./cub3d maps/ma_map.cub
```

### Structure des fichiers de map

Les fichiers de map se trouvent dans le dossier `maps` et utilisent les caractères suivants :

#### En-tête :
- `NO sprites/wall1.xpm`  : Texture Nord
- `SO sprites/wall2.xpm`  : Texture Sud
- `WE sprites/wall3.xpm`  : Texture Ouest
- `EA sprites/wall4.xpm`  : Texture Est
- `DO sprites/door.xpm`   : Texture de porte

- `F 220,100,0`           : Couleur de sol
- `C 225,30,0`            : Couleur de plafond

#### Map :
- `1` : Mur
- `0` : Sol
- `D` : Porte animée (multi-layer)
- `N`, `S`, `E`, `W` : Position et orientation du joueur

#### Exemple

```
NO sprites/wall1.xpm
SO sprites/wall2.xpm
WE sprites/wall3.xpm
EA sprites/wall4.xpm
DO sprites/door.xpm

F 220,100,0
C 225,30,0

        1111111111111111111111111
        1000000000110000000000001
        1011000001110000000000001
        1001000000000000000000001
111111111011000001110000000000001
100000000011000001110111111111111
11110111111111011100000010001
11110111111111011101010010001
11000000110101011100000010001
10000000000000001100000010001
10000000000000001101010010001
11000001110101011111011110N0111
11110111 1110101 101111010001
11111111 1111111 111111111111
```

### Bonus et innovations

- Animation verticale pour les portes.
- Souris sur 2 axes.
- Gestion avancée du multi-layering.
- Minimap dynamique.
- Plusieurs modes (Appuyez sur M pour voir).

### Auteurs

Ce projet a été créé par :

    LolelsayFR | Emaillet
    UnGarsRandom | Artgirar
