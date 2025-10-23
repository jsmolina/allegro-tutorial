## What's this?
This is a simple basic repository for allegro, dockerized to ease compiling the dat files, and including a working example of loading a background a moving a sprite over screen.
## Compiling

Compile with
* `docker-compose build`
Generate docker image

* `docker-compose up`
Does two steps:
1. Wake up docker, generates and copies `statics.h` and `datos.dat`.
2. Compile code in src.

