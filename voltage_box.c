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
	printf("after struct create\n");
	voltageInfo->voltage = gtk_entry_with_name_new("voltage");
	printf("easypeasy\n");
	voltageInfo->voltage_box = gtk_vbox_new(FALSE, 2);
	printf("filled the struct with shit\n");
	add_widget_with_label_vbox(GTK_CONTAINER(voltageInfo->voltage_box), 
	"Voltage (V):", voltageInfo->voltage);
	printf("added label box\n");
	return voltageInfo;
}

