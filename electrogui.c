#include <gtk/gtk.h>
#include <stdio.h>
#include <string.h>
#include "electrogui.h"
#include "coupling_box.h"
#include "helper_functions.h"
#include "libresistance.h"
#include "libpower.h"
#include "libcomponent.h"
#include <stdlib.h>



char* const resistor_names[] = { "res1", "res2", "res3" };
char* const resistor_labels[] = {"1:", "2:", "3:"};

/**
 * @brief Constructor for resistor_box GUI part
 *
 * This GUI part contains three resistor input field.
 *
 * @return GtkWidget Contains the constructed GUI part.
 */
GtkWidget* resistor_box_new(void){

	GtkWidget* upperrightvbox;
	GtkWidget* resistor_frame;

	upperrightvbox = gtk_vbox_new(FALSE, 5);


	for(int i = 0; i < 3; i++){
		add_widget_with_label_hbox(GTK_CONTAINER(upperrightvbox),
				resistor_labels[i],
				gtk_entry_with_name_new(resistor_names[i]));
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
				GTK_ENTRY( (GtkWidget *) find_child(resistor_box, resistor_names[i]))));
	}

	return value_array;
}

/**
 * @brief closeApp callback function
 *
 * Function to close main GTK application window.
 *
 * @param window, pointer to the main window widget
 * @param data, pointer for extra data, not used
 */
void closeApp ( GtkWidget *window, gpointer data ) {
  gtk_main_quit();
}
GtkWidget* voltage_box_new(void){
	GtkWidget *voltage;
	GtkWidget *voltage_box;

	voltage = gtk_entry_with_name_new("voltage");
	voltage_box = gtk_vbox_new(FALSE, 2);
	add_widget_with_label_vbox(GTK_CONTAINER(voltage_box), "Voltage (V):", voltage);
	return voltage_box;
}

/**
 * @brief Retrieve voltage value from GUI entry field
 *
 * Retrieves float value of the voltage input box. The
 * function needs a reference/pointer to the GUI element.
 *
 * @param voltage_box GtkWidget GUI element voltage_box
 * @return float value of the current set voltage value in the GUI
 *
 */
float get_voltage(GtkWidget* voltage_box){
	float voltage_value = atof(gtk_entry_get_text(
			GTK_ENTRY( (GtkWidget *) find_child(voltage_box, "voltage"))));
	return voltage_value;
}


/**
 * @brief Main of electrotestgtk Application
 *
 * Application GTK+ gui frontend for electrotest libraries.
 * The Main file constructs the GUI by calling the three respective
 * constructor functions. Interfacing to the libraries happens
 * mostly in the calc_results_box gui part. Currently the application
 * does not implement advanced user input validation and relies on
 * the functionality in the libraries.  *
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

	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_title(GTK_WINDOW(window), "Electrotest");
	gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
	gtk_window_set_default_size(GTK_WINDOW(window),400, 250);
	gtk_container_set_border_width(GTK_CONTAINER(window), 10);

	global_vbox = gtk_vbox_new(FALSE, 5);

	gui.voltage_box = voltage_box_new();
	gui.coupling_box = coupling_box_new();
	gui.resistor_box = resistor_box_new();
	gui.calc_result_box = calc_result_box_new(gui_pt);
	gui.resistor_values = resistor_values;

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
