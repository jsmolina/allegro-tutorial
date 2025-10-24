## What's this?
This repository provides a **ready-to-use boilerplate** for building MS-DOS games using Allegro 4 and a Dockerized environment.  
You’ll get:
- A minimal working example: loading a background, animating a sprite from a spritesheet, rendering the game loop.  
- A Docker setup so you don’t spend hours fighting with old dependencies, compilers or OS configs.  
- A clean folder structure and starter build scripts so you can focus on **making the game**, not setting up the toolchain.

## Why use Docker for Allegro 4?  
Modern systems often struggle with Allegro 4‘s vintage toolchain:
- Compiler versions and libraries have changed a lot; setting things up manually is error-prone.  
- Old MS-DOS-targeted builds (via DJGPP) require specific configurations. And datfiles are a nightmare.
- You want to build under the *same conditions*, reproducible on any platform (Windows, macOS, Linux).

## 🏗 What the boilerplate gives you  
- `src/` folder: example C source (`main.c`) showing initialization, loading, game loop, cleanup.  
- `static/` folder: assets (bitmaps, sprites, tiles, sound).  
- `build.sh` (or equivalent): script to collect assets, generate `statics.h`, compile, link and produce output (MS-DOS .exe + data file).  
- `Dockerfile` + `docker-compose.yaml`: pre-configured container environment.  
- `statics.h`: automatically generated header listing all data files to be included.  

## Getting Started  
1. Install [Docker](https://www.docker.com) and Docker Compose if you haven’t already.  
2. In project root run:  
   ```bash
   docker-compose build   # builds the Docker image  
   docker-compose up      # runs asset generation + compilation
   ```
3. After success you’ll get an MS-DOS-compatible executable and the data.dat (or equivalent) data file.

4. Open src/main.c to see how the game loop works. Copy/extend it for your own game logic, add new C/H files, new assets, etc.

5. For assets: prefer tools like Aseprite / LibreSprite, and export indexed bitmaps (mode X palette) to satisfy Allegro 4’s expectations.

7. You can replace the palette with your own (used for older ports like “Rio Inmaculado”); just ensure consistency across all bitmaps and the screen mode.

## Asset Tips

* Allegro 4 expects indexed BMPs (not full RGB) when using mode X or 256-colour modes. Otherwise colours may look wrong.
* Use Aseprite / LibreSprite: set the palette to your target 256 colours, design your sprites/tiles, then export with “Indexed + Mode X” or equivalent.
* Use a tilemap editor (e.g., Tiled) to build backgrounds from 8 × 8 tiles exported from your sprite tool.
* When you adopt your own palette: make sure all screens, bitmaps and tiles reference the same palette. Mixing palettes leads to palette flicker or bad rendering.


## Folder Structure
```
/
├── Dockerfile
├── docker-compose.yaml
├── build.sh                ← add any of your assets to this file to include in data file
├── statics.h               ← auto-generated
├── data.dat                ← compiled game data
├── src/
│   └── main.c
├── static/
│   ├── sprites/
│   └── tiles/
│   └── sounds/
└── README.md
```
## License & Contributions

Feel free to fork this repository, modify the boilerplate for your own MS-DOS game projects, and contribute back improvements (asset pipelines, more game-loop examples, cross-platform testing).
If you make major improvements, submitting a pull request is welcome.

## Final Note

This is not a full game engine like CPCtelera or Churrera from The Mojon Twins — it’s a starting point.
Use it as a scaffold: tweak it, build your game logic on top, plug in assets, and you’re ready to go from zero to playable faster.
  

