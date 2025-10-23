## What's this?
This is a simple basic repository for allegro 4, dockerized to ease compiling the dat files, and including a working example of loading a background a moving a sprite with a spritesheet over screen.

Relevant files:

1. `statics.h`: Lists all data.dat files.
2. `build.sh`: The script that should include all your statics (bmp, tiled files, ...).
3. `main.c`: the game entry, loads things, main loop, clean things. When you create your game, you should create extra C and H files, of course.


* How is it possible that my bmps look horrible and yours are ok? Allegro expects indexed bmps, so better use Aseprite/Libresprite and select Mode X palette before exporting.

## Compiling

Compile with
* `docker-compose build`
Generate docker image

* `docker-compose up`
Does two steps:
1. Wake up docker, generates and copies `statics.h` and `datos.dat`.
2. Compile code in src.

