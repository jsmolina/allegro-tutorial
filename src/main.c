#include <stdio.h>
#include <allegro.h>
#include "allegro/gfx.h"
#include "statics.h"

#define CAT_FRAMES 2
#define WALK_CYCLE 8

PALETTE palette;
DATAFILE *dat_file;


static volatile int update_count, frame_count, fps = 0;

void gfx_timer_proc(void) { update_count = 1; }
END_OF_FUNCTION(gfx_timer_proc)

static void gfx_fps_proc(void) {
    fps = frame_count;
    frame_count = 0;
}
END_OF_FUNCTION(gfx_fps_proc)

void gfx_init_timer() {
    LOCK_VARIABLE(update_count);
    LOCK_VARIABLE(frame_count);
    LOCK_VARIABLE(fps);
    LOCK_FUNCTION(gfx_timer_proc);
    LOCK_FUNCTION(gfx_fps_proc);
    install_int_ex(gfx_timer_proc, BPS_TO_TIMER(70));
    install_int_ex(gfx_fps_proc, BPS_TO_TIMER(1));
}
static volatile long speed_counter = 0;

void increment_speed_counter()
{
    speed_counter++;
}
END_OF_FUNCTION(increment_speed_counter);

void clean(BITMAP * background, int xpos) {
    blit(background, screen, 9+xpos, 215, 9+xpos, 215, 33, 17);
}

int main(void) {
    RGB black = { 16, 16, 16, 0 };
    if (allegro_init() != 0)
        return 1;
    install_keyboard();

    if (set_gfx_mode(GFX_MODEX, 320, 240, 320, 240) != 0) {
        set_gfx_mode(GFX_TEXT, 0, 0, 0, 0);
        allegro_message("Unable to set a 320x240 mode with 320x240 "
                        "virtual dimensions\n");
        return 1;
    }
    set_color_depth(8);
    set_color_conversion(COLORCONV_NONE);

    dat_file = load_datafile("datos.dat");
    get_pallete(palette);
    // index 0 of bmp will be transparent for sprites!
    set_color(0, &black);
    BITMAP *background = dat_file[BACK_BMP].dat;
    BITMAP *double_buffer = create_video_bitmap(SCREEN_W, SCREEN_H);
    BITMAP *bg_video = create_video_bitmap(SCREEN_W, SCREEN_H);

    // cat spritesheet
    BITMAP *cat_spritesheet = dat_file[CAT_BMP].dat;
    BITMAP *sp_cat[CAT_FRAMES];
    int frame_width = (int) cat_spritesheet->w / 2;
    for (int i = 0; i < CAT_FRAMES; i++) {
        sp_cat[i] = create_sub_bitmap(cat_spritesheet, i * frame_width, 0, frame_width, cat_spritesheet->h);        
    }
    int xpos = 0;
    int frame = 0;

    // main loop
    gfx_init_timer();
    blit(background, screen, 0, 0, 0, 0, 320, 240);
    blit(background, bg_video, 0, 0, 0, 0, 320, 240);

    do {
       if ((xpos / WALK_CYCLE) % 2 == 0) {
            frame = 0;
        } else {
            frame = 1;
        }
        clean(background, xpos);
        xpos++;

        draw_sprite(screen, sp_cat[frame], 10 + xpos, 215);

        if (xpos > 250) {
            clean(bg_video, xpos);
            xpos = 0;
            
        }
   

       vsync();
    } while (!keypressed());

    for (int i = 0; i < CAT_FRAMES; i++) {
        destroy_bitmap(sp_cat[i]);
    }
    unload_datafile(dat_file);

    clear_keybuf();
    return 0;
}

END_OF_MAIN()
