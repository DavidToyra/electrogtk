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

GtkWidget* find_label(GtkWidget* parent, const gchar* name);
GtkWidget* resistor_box_new(void);
gfloat* update_resistor_values(GtkWidget* resistor_box, gfloat *value_array);
#endif

