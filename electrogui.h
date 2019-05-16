#ifndef ELECTROGUI_H_
#define ELECTROGUI_H_
#include <gtk/gtk.h>
#include "coupling_box.h"
#include "voltage_box.h"
#include "libresistance.h"
#include "libpower.h"
#include "libcomponent.h"

/**
 * @brief Struct with pointers to all gui and data parts
 *
 * The struct contains pointers to the three GtkWidget gui
 * parts and the float array that contains the current resistor
 * values.
 */
struct gui_comp {
	GtkWidget* voltage_box;
	GtkWidget* coupling_box;
	GtkWidget* resistor_box;
	GtkWidget* calc_result_box;
	float* resistor_values;
};

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
GtkWidget* find_label(GtkWidget* parent, const gchar* name);

/**
 * @brief Constructor for the three resistor fields GUI.
 *
 * This GUI part contains three resistor input field.
 *
 * @return GtkWidget Contains the constructed GUI part.
 */
GtkWidget* resistor_box_new(void);

/**
 * @brief Updates the value_array with values from the GUI
 *
 * The Function assumes a gfloat array of size 3.
 *
 * @param resistor_box The GUI part to access the user input.
 * @value_array Float array of size 3 that contains the resistor values
 */
gfloat* update_resistor_values(GtkWidget* resistor_box, gfloat *value_array);
#endif

