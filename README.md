## What's this?
This is a simple basic repository for allegro 4, dockerized to ease compiling the dat files, and including a working example of loading a background a moving a sprite with a spritesheet over screen.

1. `statics.h`: Lists all data.dat files.
2. `build.sh`: The script that will add all your statics (bmp, tiled files, ...).

* How is it possible that my bmps look horrible and yours are ok? Allegro expects indexed bmps, so better use Aseprite/Libresprite and select Mode X palette before exporting.

## Compiling

Compile with
* `docker-compose build`
Generate docker image

* `docker-compose up`
Does two steps:
1. Wake up docker, generates and copies `statics.h` and `datos.dat`.
2. Compile code in src.

