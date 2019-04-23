#include "voltage_box.h"

/**
 * @brief Constructor for voltage gtk view
 *
 * Constructs the voltage_box GUI element which contains
 * the entry field for setting the voltage.
 *
 * @return GtkWidget 
 */
GtkWidget *voltage_box_new(void)
{
	GtkWidget* voltageInfo = gtk_entry_new();
	gtk_widget_set_name(voltageInfo, "voltage");
	
	GtkWidget* voltage_box = gtk_vbox_new(FALSE, 2);
	GtkWidget *label = gtk_label_new("Voltage (V): ");
  	GtkWidget *hbox = gtk_hbox_new(TRUE,2);

  	gtk_container_add(GTK_CONTAINER(hbox), label);
  	gtk_container_add(GTK_CONTAINER(hbox), voltageInfo);
  	gtk_container_add(GTK_CONTAINER(voltage_box), hbox);
	
	return voltage_box;
}



