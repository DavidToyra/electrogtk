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
	
	VoltageWidgets* voltageInfo;
	voltageInfo->voltage = gtk_entry_with_name_new("voltage");
	voltageInfo->voltage_box = gtk_vbox_new(FALSE, 2);
	add_widget_with_label_vbox(GTK_CONTAINER(voltageInfo->voltage_box), 
	"Voltage (V):", voltageInfo->voltage);
	return voltageInfo;
}

