#include <gtk/gtk.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


static void print_hello (GtkWidget *widget, gpointer data){
  g_print ("Hello World\n");
}


static void activate (GtkApplication* app, gpointer user_data){
  GtkWidget * window;
  GtkWidget * main_box;

  GtkWidget * insert_button;
  GtkWidget * insert_text;
  GtkWidget * insert_box;
  GtkWidget * insert_label;

  GtkWidget * search_text;
  GtkWidget * search_list;
  GtkWidget * search_label;

  // create window
  window = gtk_application_window_new (app);
  gtk_window_set_title (GTK_WINDOW (window), "Notes Reminder");
  gtk_window_set_default_size (GTK_WINDOW (window), 400, 300);
  
  // create containing boxes
  main_box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 15);
  insert_box = gtk_button_box_new(GTK_ORIENTATION_HORIZONTAL);
  gtk_container_add(GTK_CONTAINER (window), main_box);

  // Insert Widgets
  insert_label = gtk_label_new ("Create New");
  insert_button = gtk_button_new_with_label("Insert");
  insert_text = gtk_entry_new ();
  g_signal_connect(insert_button, "clicked", G_CALLBACK (print_hello), NULL);
  g_signal_connect_swapped(insert_button, "clicked", G_CALLBACK (gtk_widget_destroy), window);
 
  // Search Widgets
  search_text = gtk_entry_new ();
  search_label = gtk_label_new ("Search");
  search_list = gtk_list_box_new ();
  gtk_list_box_insert (GTK_LIST_BOX (search_list), gtk_label_new("Teste"), 0);

  // Fill the containers
  gtk_container_add(GTK_CONTAINER (main_box), insert_label);
  
  gtk_container_add(GTK_CONTAINER (main_box), insert_box);
  gtk_container_add(GTK_CONTAINER (insert_box), insert_text);
  gtk_container_add(GTK_CONTAINER (insert_box), insert_button);
  
  gtk_container_add(GTK_CONTAINER (main_box), search_label);
  gtk_container_add(GTK_CONTAINER (main_box), search_text);
  gtk_container_add(GTK_CONTAINER (main_box), search_list);

  gtk_widget_show_all (window);
}


int main (int argc, char **argv){
  int status = 0;
  GtkApplication *app;
  
  app = gtk_application_new ("org.gtk.example", G_APPLICATION_FLAGS_NONE);
  g_signal_connect (app, "activate", G_CALLBACK (activate), NULL);
  status = g_application_run (G_APPLICATION (app), argc, argv);
  g_object_unref (app);

  /* The current (and peak) real memory in kB */
  int currRealMem;
  int peakRealMem;
  
  // stores each word in status file
  char buffer[1024] = "";
  
  // linux file contains this-process info
  FILE* file = fopen("/proc/self/status", "r");
  
  // read the entire file
  while (fscanf(file, " %1023s", buffer) == 1) {
      if (strcmp(buffer, "VmRSS:") == 0) {
          fscanf(file, " %d", &currRealMem);
      }
      if (strcmp(buffer, "VmHWM:") == 0) {
          fscanf(file, " %d", &peakRealMem);
      }
  }

  fclose(file);
  
  printf("currRealMem: %d \n", currRealMem);
  printf("peakRealMem: %d \n", peakRealMem);


  return status;
}

