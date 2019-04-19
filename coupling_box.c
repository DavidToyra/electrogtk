#include <gtk/gtk.h>
#include "coupling_box.h"

#include "helper_functions.h"

/**
 * @brief Constructor for the Resistor Coupling Gui part
 *
 * The Resistor coupling GUI part allows to choose between serial/parallel
 * coupling of the resistors.
 *
 * @return GtkWidget* pointer to the new created Gui part.
 *
 */
GtkWidget* coupling_box_new(void){

	GtkWidget* serial;
	GtkWidget* serial_box;
	GtkWidget* parallel;
	GtkWidget* parallel_box;
	GtkWidget* coupling_vbox;
	GtkWidget* coupling_frame;

	serial = gtk_radio_button_new(NULL);
	gtk_widget_set_name(serial, "serial");
	serial_box = gtk_hbox_new(FALSE, 5);
	add_widget_with_label_hbox(GTK_CONTAINER(serial_box),"serial", serial);
	parallel = gtk_radio_button_new_from_widget(GTK_RADIO_BUTTON(serial));
	parallel_box = gtk_hbox_new(FALSE, 5);
	add_widget_with_label_hbox(GTK_CONTAINER(parallel_box),"parallel", parallel);

	coupling_vbox = gtk_vbox_new(FALSE, 1);
	gtk_container_add(GTK_CONTAINER(coupling_vbox), serial_box);
	gtk_container_add(GTK_CONTAINER(coupling_vbox), parallel_box);

	coupling_frame = gtk_frame_new("Coupling");
	gtk_container_add(GTK_CONTAINER(coupling_frame), coupling_vbox);

	return coupling_frame;
}

/**
 * @brief Getter for mode of resistor coupling
 *
 * Function that queries the selected resitor coupling mode
 * in the gui and returns 1 for serial and 0 for parallel.
 *
 * @return 1 = serial, 0 = parallel
 */
int get_coupling(GtkWidget* coupling_box){

	if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON( (GtkWidget *) find_child(coupling_box, "serial")))){
		return 1;
	} else {
		return 0;
	}
}
