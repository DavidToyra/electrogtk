#include <gtk/gtk.h>
#include "calculate_box.h"
#include "voltage_box.h"
#include "coupling_box.h"
#include "helper_functions.h"
#include "electrogui.h"


GtkWidget* result_power;
GtkWidget* result_resistance;



/**
 * @brief callback function for calculation button
 *
 * Function uses the electrotest libraries to calculate the replacement
 * resistor and power. Currently, no additional error handling over the
 * libraries is implemented. The function takes a struct with pointers
 * to the relevant gui parts and the data array that contains the
 * resistor values.
 *
 * @param button The button widget to which the callback relates.
 * @param gui A struct that contains pointers to all gui parts and to the
 * array which contains the resistor values.
 *
 */
void button_clicked (GtkWidget *button, struct gui_comp* gui) {

	// Get Data
	update_resistor_values((*gui).resistor_box, (*gui).resistor_values);
	float voltage = atof(gtk_entry_get_text(GTK_ENTRY(find_label((*gui).voltage_box, "voltage"))));
	char coupling;
	if(strcmp(gtk_entry_get_text(GTK_ENTRY(find_label((*gui).coupling_box, "coupling" )), "S")))
	{
		coupling = 'S';
	} else if (strcmp(gtk_entry_get_text(GTK_ENTRY(find_label((*gui).coupling_box, "coupling" )), "P")))
	{
		coupling = 'P';
	}

	// Calculate
	float resistance = calc_resistance(3, coupling, (*gui).resistor_values);
	float power =  calc_power_r(voltage, resistance);

	// Convert Result to strings
	char res_resistance[10];
	sprintf(res_resistance, "%.2f",resistance);

	char res_power[10];
	sprintf(res_power, "%.2f",power);

	// Publish results
	gtk_entry_set_text(GTK_ENTRY(result_resistance), res_resistance);
	gtk_entry_set_editable(GTK_ENTRY(result_resistance), FALSE);
	gtk_entry_set_text(GTK_ENTRY(result_power), res_power);
	gtk_entry_set_editable(GTK_ENTRY(result_power), FALSE);

}



/**
 * @brief Constructor of the lower GUI part.
 *
 * This part of the GUI contains the calculation button and
 * the result boxes.
 *
 * @param gui A struct that contains pointers to all gui parts and to the
 * array which contains the resistor values.
 * @return GtkWidget* Pointer to the constructed and wired-up GUI part
 *
 */
GtkWidget* calc_result_box_new(struct gui_comp* gui){

	GtkWidget* lower_vbox;
	GtkWidget* valign;
	GtkWidget* halign;
	GtkWidget* hbox;
	GtkWidget* button;
	GtkWidget* result_resistance_box;
	GtkWidget* result_power_box;

	lower_vbox = gtk_vbox_new(FALSE, 5);
	valign = gtk_alignment_new(0, 1, 0, 0);
	gtk_container_add(GTK_CONTAINER(lower_vbox), valign);


	hbox = gtk_hbox_new(TRUE, 3);

	button = gtk_button_new_with_label("Calculate");
	gtk_widget_set_size_request(button, 70, 30);
	gtk_container_add(GTK_CONTAINER(hbox), button);


	g_signal_connect(GTK_OBJECT(button), "clicked",
		   GTK_SIGNAL_FUNC(button_clicked), (gpointer *) gui);


	result_resistance_box = gtk_vbox_new(FALSE, 2);
	result_resistance = gtk_entry_new();
	gtk_entry_set_editable(GTK_ENTRY(result_resistance), FALSE);
	add_widget_with_label_vbox(GTK_CONTAINER(result_resistance_box),"Replacement Resistance (Ohm)", result_resistance);
	gtk_container_add(GTK_CONTAINER(hbox), result_resistance_box);

	result_power_box = gtk_vbox_new(FALSE, 2);
	result_power = gtk_entry_new();
	gtk_entry_set_editable(GTK_ENTRY(result_power), FALSE);

	add_widget_with_label_vbox(GTK_CONTAINER(result_power_box),"Power (W)", result_power);
	gtk_container_add(GTK_CONTAINER(hbox), result_power_box);

	halign = gtk_alignment_new(0, 0, 0, 0);
	gtk_container_add(GTK_CONTAINER(halign), hbox);

	gtk_box_pack_start(GTK_BOX(lower_vbox), halign, FALSE, FALSE, 0);

	return lower_vbox;

}
