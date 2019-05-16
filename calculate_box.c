/*
 * @file calculate_box.c
 * @author David Töyrä
 * @date 26 april 2019
 * @brief A gtk box containing the calculate functionality of electrotest.
 */
 
#include <gtk/gtk.h>
#include "calculate_box.h"
#include "voltage_box.h"
#include "coupling_box.h"
#include "helper_functions.h"
#include "electrogui.h"


GtkWidget* result_power;
GtkWidget* result_resistance;

/**
 * @brief on click listener for the calculate button
 * calculates resistance and power with the library functions.
 *
 * @param button calculate button
 * @param gui A struct that contains pointers to all gui parts and to the
 * array which contains the resistor values.
 *
 */
void button_clicked (GtkWidget *button, struct gui_comp* gui) {

	//Get data from voltage and coupling boxes
	update_resistor_values((*gui).resistor_box, (*gui).resistor_values);
	float voltage = atof(gtk_entry_get_text(GTK_ENTRY(find_label((*gui).voltage_box, "voltage"))));
	char coupling;
	if(strcmp(gtk_entry_get_text(GTK_ENTRY(find_label((*gui).coupling_box, "coupling"))), "S") == 0
	 || strcmp(gtk_entry_get_text(GTK_ENTRY(find_label((*gui).coupling_box, "coupling"))), "s") == 0)
	{
		coupling = 'S';
		printf("coupling = %s\n", gtk_entry_get_text(GTK_ENTRY(find_label((*gui).coupling_box, "coupling"))));
	} 
	else if (strcmp(gtk_entry_get_text(GTK_ENTRY(find_label((*gui).coupling_box, "coupling"))) , "P")
	 || strcmp(gtk_entry_get_text(GTK_ENTRY(find_label((*gui).coupling_box, "coupling"))) , "p"))
	{
		coupling = 'P';
		printf("coupling = %s\n", gtk_entry_get_text(GTK_ENTRY(find_label((*gui).coupling_box, "coupling"))));
	}

	//Calculate resistance and power
	float resistance = calc_resistance(3, coupling, (*gui).resistor_values);
	float power =  calc_power_r(voltage, resistance);

	//Convert result to strings
	char res_resistance[10];
	sprintf(res_resistance, "%.2f",resistance);

	char res_power[10];
	sprintf(res_power, "%.2f",power);

	//Publish results
	gtk_entry_set_text(GTK_ENTRY(result_resistance), res_resistance);
	gtk_entry_set_editable(GTK_ENTRY(result_resistance), FALSE);
	gtk_entry_set_text(GTK_ENTRY(result_power), res_power);
	gtk_entry_set_editable(GTK_ENTRY(result_power), FALSE);

}



/**
 * @brief Constructor of the lower GUI part.
 * 
 * Contains the calculate button and the output of power and resistance.
 *
 * @param gui A struct that contains pointers to all gui parts and to the
 * array which contains the resistor values.
 * @return GtkWidget* pointer to the widget with the calculate box.
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

	//Make main box for the calculate function
	lower_vbox = gtk_vbox_new(FALSE, 5);
	valign = gtk_alignment_new(0, 1, 0, 0);
	gtk_container_add(GTK_CONTAINER(lower_vbox), valign);
	hbox = gtk_hbox_new(TRUE, 3);

	//Make button and add callback funtion to it
	button = gtk_button_new_with_label("Calculate");
	gtk_widget_set_size_request(button, 70, 30);
	gtk_container_add(GTK_CONTAINER(hbox), button);


	g_signal_connect(GTK_OBJECT(button), "clicked",
		   GTK_SIGNAL_FUNC(button_clicked), (gpointer *) gui);

	//Make replacement resistance box
	result_resistance_box = gtk_vbox_new(FALSE, 2);
	result_resistance = gtk_entry_new();
	gtk_entry_set_editable(GTK_ENTRY(result_resistance), FALSE);
	GtkWidget *label = gtk_label_new("Replacement Resistance (Ohm)");
  	GtkWidget *vbox = gtk_vbox_new(TRUE, 2);

  	gtk_container_add(GTK_CONTAINER(vbox), label);
  	gtk_container_add(GTK_CONTAINER(vbox), result_resistance);
  	gtk_container_add(GTK_CONTAINER(result_resistance_box), vbox);
	gtk_container_add(GTK_CONTAINER(hbox), result_resistance_box);

	//Make power box
	result_power_box = gtk_vbox_new(FALSE, 2);
	result_power = gtk_entry_new();
	gtk_entry_set_editable(GTK_ENTRY(result_power), FALSE);
	GtkWidget *power_label = gtk_label_new("Power (W)");
	GtkWidget *powervbox = gtk_vbox_new(TRUE, 2);
	
	gtk_container_add(GTK_CONTAINER(vbox), power_label);
	gtk_container_add(GTK_CONTAINER(vbox), result_power);
	gtk_container_add(GTK_CONTAINER(result_power_box), powervbox);
	gtk_container_add(GTK_CONTAINER(hbox), result_power_box);

	halign = gtk_alignment_new(0, 0, 0, 0);
	gtk_container_add(GTK_CONTAINER(halign), hbox);

	gtk_box_pack_start(GTK_BOX(lower_vbox), halign, FALSE, FALSE, 0);

	return lower_vbox;

}
