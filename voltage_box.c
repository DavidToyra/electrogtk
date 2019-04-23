#include "voltage_box.h"

/**
 * @brief Constructor for voltage_box GUI element
 *
 * Constructs the voltage_box GUI element which contains
 * the entry field for setting the voltage.
 *
 * @return GtkWidget A voltage_box GUI Element
 */
VoltageWidgets *voltage_box_new(void)
{
	
	VoltageWidgets *voltageInfo;

	//set widget name
	GtkWidget* entry;
	entry = gtk_entry_new();
	gtk_widget_set_name(entry, "voltage");
	
	voltageInfo->voltage = entry;
	printf("easypeasy\n");
	voltageInfo->voltage_box = gtk_vbox_new(FALSE, 2);
	printf("filled the struct with shit\n");
	//set label box
	GtkWidget *label = gtk_label_new("Voltage (V): ");
  	GtkWidget *hbox = gtk_hbox_new(TRUE,2);
  	gtk_container_add(GTK_CONTAINER(hbox), label);
  	gtk_container_add(GTK_CONTAINER(hbox), voltageInfo->voltage);
  	gtk_container_add(voltageInfo->voltage_box, hbox);
	
	printf("added label box\n");
	return voltageInfo;
}

