## What's this?
This is a simple basic repository for allegro 4, dockerized to ease compiling dat files, and including a working example of loading a background a moving a sprite with a spritesheet over screen. 

Relevant files:

1. `statics.h`: Lists all data.dat files.
2. `build.sh`: The script that should include all your statics (bmp, tiled files, wav, mid ...).
3. `main.c`: the game entry, loads things, main loop, clean things. When you create your game, you should create extra C and H files, of course.

* What does it generate? MS-DOS executable + datafile

* How is it possible that my bmps look horrible and yours are ok? Allegro expects indexed bmps, so better use Aseprite/Libresprite and select Mode X palette before exporting.
* I don't have docker compose, what's that? you should learn about docker, it's great: https://www.docker.com/
* Can I use my own palette? sure, I used it on `rio-inmaculado`, but be sure to use the same palette on the current screen for everything you draw on it.

<img width="603" height="449" alt="image" src="https://github.com/user-attachments/assets/76532012-73a1-492c-b446-9c82a0b5b442" />

## Compiling

Compile with
* `docker-compose build`
Generate docker image

* `docker-compose up`
Does two steps:
1. Wake up docker, generates and copies `statics.h` and `datos.dat`.
2. Compile code in src.

## Recommended tools
* Aseprite / Libresprite. THE TOOL. I won't recommend at all using gimp for Allegro, as allegro 4 expects indexed bitmaps.
* Tiled: you could generate 8x8 tiles from aseprite, and then compose them to generate an uniform map.

  
## A bit of context
Docker is a tool that lets you create and run applications inside containers.
A container is like a tiny self-contained computer that already includes everything your program needs to run: the operating system, libraries, compilers, and dependencies.

Instead of manually setting up your local machine (and risking version conflicts or configuration headaches), Docker packages the entire environment into a reusable image.

Working with Allegro 4 (an old graphics and audio library) can be painful today:

* Dependencies are outdated and often hard to compile on modern systems.
* Compiler and library versions differ between platforms.
* Setting everything up correctly can take hours or even days.

Docker solves all that:

* The container already includes Allegro 4 and DJGPP, build tools, and all required dependencies.
* You can build games for MS-DOS from any modern computer (Windows, macOS, Linux) with zero local setup.
* Every developer gets exactly the same build environment, so the results are consistent across machines.

While the project isn’t meant to be a full framework like CPCtelera or The Mojon Twins’ Churrera, it does serve as a boilerplate:
* It provides a basic Allegro 4 game structure — folders, Makefile, assets, and minimal code.
* It defines the Docker build environment, so anyone can start developing instantly.
* It lets you focus on making the game, not fighting with compilers or dependencies.
