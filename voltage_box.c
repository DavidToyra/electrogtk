#include <stdlib.h>
#include "helper_functions.h"

/**
 * @brief Constructor for voltage_box GUI element
 *
 * Constructs the voltage_box GUI element which contains
 * the entry field for setting the voltage.
 *
 * @return GtkWidget A voltage_box GUI Element
 */
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
