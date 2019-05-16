/*
 * @file electrogui.c
 * @author David Töyrä
 * @date 26 april 2019
 * @brief main program that assembles and runs the GUI.
 */
#include "electrogui.h"
#include <stdio.h>
#include <string.h>
#include "helper_functions.h"
#include "calculate_box.h"
#include <stdlib.h>
#include "coupling_box.h"
#include "voltage_box.h"



char* const resistor_names[] = { "res1", "res2", "res3" };
char* const resistor_labels[] = {"1:", "2:", "3:"};

/**
 * @brief Searches for a gtklabel by a name from a parent widget.
 * 
 * Recursively traverses the list of child widgets from a parent
 * until it has found the widget by a name that is searched.
 * 
 * @param parent widget to start searching from.
 * @param name string that represents name of the widget being searched
 * @return gtkwidget matching the name
 */
GtkWidget* find_label(GtkWidget* parent, const gchar* name)
{
	//Check if name matches
	if (g_ascii_strcasecmp(gtk_widget_get_name((GtkWidget*)parent), (gchar*)name) == 0)
	{
		return parent;
	}


    if (GTK_IS_BIN(parent)) 
	{
    	GtkWidget *child = gtk_bin_get_child(GTK_BIN(parent));
        return find_label(child, name);
    }


	//Get list of children and call this function again.
    if (GTK_IS_CONTAINER(parent)) 
	{
    	GList *children = gtk_container_get_children(GTK_CONTAINER(parent));
    	do {
    		GtkWidget* widget = find_label(children->data,name);
    		if (widget != NULL) {
    			return widget;
    		}
    	} while ((children = g_list_next(children)) != NULL);
    }
    return NULL;
}

/**
 * @brief Constructor for the three resistor fields GUI.
 *
 * This GUI part contains three resistor input field.
 *
 * @return GtkWidget Contains the constructed GUI part.
 */
GtkWidget* resistor_box_new(void){

	GtkWidget* upperrightvbox;
	GtkWidget* resistor_frame;

	upperrightvbox = gtk_vbox_new(FALSE, 5);


	for(int i = 0; i < 3; i++)
	{
		GtkWidget* entry = gtk_entry_new();
		gtk_widget_set_name(entry, resistor_names[i]);
		GtkWidget *label = gtk_label_new(resistor_labels[i]);
  		GtkWidget *hbox = gtk_hbox_new(TRUE,2);

  		gtk_container_add(GTK_CONTAINER(hbox), label);
  		gtk_container_add(GTK_CONTAINER(hbox), entry);
  		gtk_container_add(GTK_CONTAINER(upperrightvbox), hbox);
	}

	resistor_frame = gtk_frame_new("Resistors (Ohm)");
	gtk_container_add(GTK_CONTAINER(resistor_frame), upperrightvbox);

	return resistor_frame;
}

/**
 * @brief Updates the value_array with values from the GUI
 *
 * The Function assumes a gfloat array of size 3.
 *
 * @param resistor_box The GUI part to access the user input.
 * @value_array Float array of size 3 that contains the resistor values
 */
gfloat* update_resistor_values(GtkWidget* resistor_box, gfloat *value_array){

	for(int i = 0; i < 3; i++){
		value_array[i] = (gfloat) atof(gtk_entry_get_text(
		GTK_ENTRY( (GtkWidget *) find_label(resistor_box, resistor_names[i]))));
	}

	return value_array;
}

/**
 * @brief closeApp callback function
 *
 * Function to close main GTK application window.
 *
 * @param window, pointer to the main window widget
 */
void closeApp ( GtkWidget *window) {
  gtk_main_quit();
}


/**
 * @brief main function for the electrotest gui.
 *
 * Uses GTK+ v2.0 library for the graphical interface. Creates the meain window
 * and then the gtk widgets one by one and adds them to the main window.
 * 
 */
gint main (gint argc, gchar *argv[]) {

	GtkWidget *window;
	GtkWidget *global_vbox;
	GtkWidget *upper_left_vbox;
	GtkWidget *upper_hbox;

	struct gui_comp gui;
	struct gui_comp* gui_pt = &gui;
	gfloat resistor_values[3] = {1, 1, 1};

	gtk_init(&argc, &argv);

	//Create main frame
	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_title(GTK_WINDOW(window), "Electrotest");
	gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
	gtk_window_set_default_size(GTK_WINDOW(window),400, 250);
	gtk_container_set_border_width(GTK_CONTAINER(window), 10);

	global_vbox = gtk_vbox_new(FALSE, 5);

	//Create boxes for the data I/O
	gui.voltage_box = voltage_box_new();
	gui.coupling_box = coupling_box_new();
	gui.resistor_box = resistor_box_new();
	gui.calc_result_box = calc_result_box_new(gui_pt);
	gui.resistor_values = resistor_values;

	//Add coupling and voltage fields
	upper_left_vbox = gtk_vbox_new(FALSE, 5);
	gtk_container_add(GTK_CONTAINER(upper_left_vbox), gui.voltage_box);
	gtk_container_add(GTK_CONTAINER(upper_left_vbox), gui.coupling_box);

	
	upper_hbox = gtk_hbox_new(FALSE, 5);
	gtk_container_add(GTK_CONTAINER(upper_hbox),upper_left_vbox);
	gtk_container_add(GTK_CONTAINER(upper_hbox),gui.resistor_box);
	gtk_container_add(GTK_CONTAINER(global_vbox), upper_hbox);


    gtk_container_add(GTK_CONTAINER(global_vbox), gui.calc_result_box);
    gtk_container_add(GTK_CONTAINER(window), global_vbox);

    g_signal_connect(G_OBJECT(window), "destroy",
          G_CALLBACK(gtk_main_quit), G_OBJECT(window));

    gtk_widget_show_all(window);

    gtk_main();

    return 0;

}
