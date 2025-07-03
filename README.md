# cub3D - My first RayCaster with miniLibX

## Overview

**cub3D** is a 42 School project that recreates the legendary **Wolfenstein 3D** game engine using ray-casting techniques. This project challenges students to create a realistic 3D graphical representation of a maze from a first-person perspective using the **miniLibX** graphics library. The project focuses on understanding fundamental computer graphics concepts, mathematical algorithms, and real-time rendering techniques.

As part of the 42 curriculum's graphics track, cub3D bridges the gap between basic programming and advanced computer graphics, introducing concepts like ray-casting, texture mapping, and event-driven programming that are foundational to game development and computer graphics.

## Features

### Core Functionality

- **Texture mapping** - with different wall textures for North, South, East, and West faces
- **Customizable floor and ceiling colors** - via RGB values
- **Map parsing system** - supporting `.cub` configuration files
- **Ray-casting engine** - implementing Wolfenstein 3D-style 3D rendering
- **Cross-platform compatibility** - (macOS and Linux)

### Controls & Interface

- **WASD movement** for navigating through the maze
- **Arrow keys** for looking left and right
- **ESC key** and window close button for clean program termination
- **Smooth window management** with proper event handling

### Map System

- **6-character map format**: `0` (empty space), `1` (wall), `N/S/E/W` (player spawn)
- **Closed map validation** ensuring walls surround the playable area
- **Flexible map parsing** supporting various map layouts and configurations
- **Error handling** with descriptive messages for invalid configurations

## How to Run

### Installation & Compilation

```bash
# Clone the repository
git clone https://github.com/yuki-jinnouchi/42-cub3d.git cub3d
cd cub3d

# Compile the project (includes libft and miniLibX)
make

# The executable will be created as ./cub3D
```

### Execution

```bash
# Run with a map file
./cub3D map/sample01.cub

# Try different sample maps
./cub3D map/sample02.cub
./cub3D map/sample03.cub
./cub3D map/sample04.cub
```

### Map File Format Example

```bash
NO ./texture/North.xpm
SO ./texture/South.xpm
WE ./texture/West.xpm
EA ./texture/East.xpm

F 50,30,0
C 220,220,220

111111
100101
101001
1100N1
111111
```

## Reference

- [miniLibX Documentation](https://github.com/42Paris/minilibx-linux) - Official miniLibX library documentation
- [Wolfenstein 3D](http://users.atw.hu/wolf3d/) - Original game for reference
- [Ray-Casting Tutorial](https://lodev.org/cgtutor/raycasting.html) - Comprehensive guide to ray-casting algorithms
