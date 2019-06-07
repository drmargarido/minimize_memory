#include "notes.h"

static char insert_current[NOTE_SIZE] = "";
static char search_current[NOTE_SIZE] = "";
static struct note * notes_list = NULL;
static int is_first_run = nk_true;

void
insert_note()
{
    int i=0;
    int offset = 0;
    int result;
    char command[COMMAND_SIZE] = "";

    char escaped_text[COMMAND_SIZE] = "";
    
    if(strlen(insert_current) >= (NOTE_SIZE - 10)){
        insert_current[(NOTE_SIZE - 12)] = '\0';
    }
    
    for(i=0; insert_current[i] != '\0'; i++){
        switch(insert_current[i]){
        case '"':
        case '\\':
            escaped_text[i + offset] = '\\';
            offset++;
        }
        
        escaped_text[i + offset] = insert_current[i];
    }
    
    sprintf(command, "remember \"%s\"", escaped_text);
    result = system(command);

    if(result == 0){
        snprintf(insert_current, NOTE_SIZE, "");
    }
}

static void
search_changed ()
{
  FILE *fp;
  char current_note[NOTE_SIZE];
  char command[COMMAND_SIZE] = "";

  char escaped_text[COMMAND_SIZE] = "";
  int offset = 0;
  int i;

  struct note * next_note = notes_list;
  struct note * previous_note = NULL;
  struct note * tmp_note = NULL;

  if(strlen(search_current) >= (NOTE_SIZE - 10)){
  	search_current[(NOTE_SIZE - 12)] = '\0';
  }
  
  for(i=0; search_current[i] != '\0'; i++){
  	switch(search_current[i]){
      case '"':
      case '\\':
    		escaped_text[i + offset] = '\\';
    		offset++;
  	}
  	
  	escaped_text[i + offset] = search_current[i];
  }

  /* Open the command for reading. */
  sprintf(command, "remindme \"%s\"", escaped_text);

  fp = popen(command, "r");
  if (fp == NULL) {
    printf("Failed to run command\n" );
    exit(1);
  }
  
  /* Clear old notes list */
  while(notes_list != NULL){
    tmp_note = notes_list;
    notes_list = notes_list->next;

    free(tmp_note);
    tmp_note = NULL;
  }
  

  /* Read the output a line at a time and add it to the notes list. */
  while (fgets(current_note, sizeof(current_note)-1, fp) != NULL) {
    if(notes_list == NULL){
        notes_list = malloc(sizeof(struct note));
        next_note = notes_list;
        previous_note = NULL;
    }
    else {
        next_note->next = malloc(sizeof(struct note));
        previous_note = next_note;
        next_note = next_note->next;
        next_note->prev = previous_note;
    }

    strcpy(next_note->text, current_note);
    next_note->next = NULL;
  }
  
  /* close */
  pclose(fp);
}

void
draw(struct nk_context *ctx)
{
  if(is_first_run){
    is_first_run = nk_false;
    search_changed();
  }

  if (nk_begin(ctx, "Notes Reminder", nk_rect(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT), 0))
  {
    struct note * next_note = notes_list;

    /* Text fields data */
    int insert_len;
    char insert_buffer[NOTE_SIZE] = "";

    int search_len;
    char search_buffer[NOTE_SIZE] = "";

    static int selected_item = nk_true;

    /* Note Insertion Area */
    nk_layout_row_static(ctx, WIDGET_HEIGHT / 2, WINDOW_WIDTH - SIDE_MARGIN * 2, 0);

    nk_layout_row_static(ctx, WIDGET_HEIGHT, WINDOW_WIDTH - SIDE_MARGIN * 2, 1);
    nk_label(ctx, "Create New", NK_TEXT_CENTERED);

    nk_layout_row_begin(ctx, NK_STATIC, WIDGET_HEIGHT, 2);
    {
        nk_layout_row_push(ctx, (WINDOW_WIDTH - SIDE_MARGIN * 2) / 3 * 2);
        insert_len = snprintf(insert_buffer, NOTE_SIZE, "%s", insert_current);
        nk_edit_string(ctx, NK_EDIT_SIMPLE, insert_buffer, &insert_len, NOTE_SIZE - 1, nk_filter_default);
        insert_buffer[insert_len] = 0;
        snprintf(insert_current, NOTE_SIZE, "%s", insert_buffer);

        nk_layout_row_push(ctx, (WINDOW_WIDTH - SIDE_MARGIN * 2) / 3);
        if (nk_button_label(ctx, "Insert")){
            insert_note();
        }
    }
    nk_layout_row_end(ctx);


    /* Note Search Area */
    nk_layout_row_static(ctx, WINDOW_HEIGHT / 12, WINDOW_WIDTH - SIDE_MARGIN * 2, 0);

    nk_layout_row_static(ctx, WIDGET_HEIGHT, WINDOW_WIDTH - SIDE_MARGIN * 2, 1);
    nk_label(ctx, "Search", NK_TEXT_CENTERED);

    nk_layout_row_begin(ctx, NK_STATIC, WIDGET_HEIGHT, 2);
    {
        nk_layout_row_push(ctx, (WINDOW_WIDTH - SIDE_MARGIN * 2) / 5);
        nk_label(ctx, "", NK_TEXT_CENTERED);
        nk_layout_row_push(ctx, (WINDOW_WIDTH - SIDE_MARGIN * 2) / 5 * 3);
        search_len = snprintf(search_buffer, NOTE_SIZE, "%s", search_current);
        nk_edit_string(ctx, NK_EDIT_SIMPLE, search_buffer, &search_len, NOTE_SIZE - 1, nk_filter_default);
        search_buffer[search_len] = 0;
        if(strcmp(search_buffer, search_current)){
            snprintf(search_current, NOTE_SIZE, "%s", search_buffer);    
            search_changed();
        }
        else {
            snprintf(search_current, NOTE_SIZE, "%s", search_buffer);
        }
    }
    nk_layout_row_end(ctx);

    nk_layout_row_dynamic(ctx, WINDOW_WIDTH - SIDE_MARGIN * 2, 1);
    if (nk_group_begin(ctx, "Standard", 0))
    {
        while(next_note != NULL){
            nk_layout_row_dynamic(ctx, WIDGET_HEIGHT, 1);
            nk_selectable_label(ctx, next_note->text, NK_TEXT_CENTERED, &selected_item);
            next_note = next_note->next;
        }
        
        nk_group_end(ctx);
    }
  }

  nk_end(ctx);
}
