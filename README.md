## Pokemon Battle System
A C++ game engine project, built with SDL2, featuring a turn-based battle system inspired by Pokémon (though I started off planning to make a digimon digital-pet clone).

## Overview

My attempt at making a **graphical** game in C++ without using a game engine. It utilizes a message-based system for inter-component communication, (the beginnings of) a modular GUI framework, and features turn-based battle mechanics.

<img width="512" height="384" alt="Image" src="https://github.com/user-attachments/assets/e2693240-a294-4213-bac6-40a2ff6477b3" />

## Features

- **Message Bus Architecture**: Decoupled system communication using a publisher-subscriber pattern
- **Turn-Based Battle System**: Player vs. enemy combat with random damage calculations
- **GUI Framework**: Menu navigation system with button selection and rendering
- **Monster System**: Player and wild monster classes with health management
- **Input Handling**: Keyboard input system with context-aware message dispatching
- **Modular Design**: Systems organized as independent, reusable components

## Project Structure

### Core Systems
- `System.hpp/cpp` - Base class for all game systems
- `MessageBus.hpp/cpp` - Central message routing system
- `InputSystem.hpp/cpp` - Keyboard input handling
- `GameLogicSystem.hpp/cpp` - Game state management
- `BattleSystem.hpp/cpp` - Turn-based battle logic

### GUI Components
- `GuiSystem.hpp/cpp` - Base GUI system
- `GuiMainMenu.hpp/cpp` - Main menu interface
- `GuiBattleCommands.hpp/cpp` - Battle command menu
- `Button.hpp/cpp` - Interactive button component

### Graphics & Audio
- `LWindow.hpp/cpp` - SDL window management
- `LTexture.hpp/cpp` - Texture loading and rendering
- `AudioSystem.hpp/cpp` - Sound playback (not implemented)

### Game Data
- `Monster.hpp/cpp` - Monster base class and subclasses
- `CharacterData.hpp` - Pokémon data structures
- `RNG.hpp/cpp` - Random number generation

## Building

Requires SDL2, SDL2_image, and SDL2_ttf libraries.

```bash
g++ -std=c++11 *.cpp -lSDL2 -lSDL2_image -lSDL2_ttf -o pkmn_battle
```

## Current Status

The following features are functional:
- Main menu navigation
- Battle initialization and turn-based combat
- Message routing between systems
- Basic rendering pipeline

## Architecture Notes

This project demonstrates:
- **Decoupled Design**: Systems communicate exclusively through messages, enabling easy testing and modification
- **RAII Principles**: Resource management through constructors/destructors
- **Polymorphism**: System and GameObject hierarchies for extensibility
