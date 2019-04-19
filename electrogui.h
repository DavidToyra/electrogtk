#include  <gtk/gtk.h>

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
GtkWidget* voltage_box_new(void);
GtkWidget* resistor_box_new(void);
float get_voltage(GtkWidget* voltage_box);
GtkWidget* resistor_box_new(void);
gfloat* update_resistor_values(GtkWidget* resistor_box, gfloat *value_array);

