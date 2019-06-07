#define WINDOW_WIDTH    400
#define WINDOW_HEIGHT   300

#define WIDGET_HEIGHT   25
#define SIDE_MARGIN     15
#define ROW_SPACE       10

#define NOTE_SIZE       512
#define COMMAND_SIZE    (NOTE_SIZE * 2)

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "nuklear.h"

void draw(struct nk_context *ctx);

struct note {
    char text[COMMAND_SIZE];
    struct note *next;
    struct note *prev;
};