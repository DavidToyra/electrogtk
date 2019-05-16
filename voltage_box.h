#ifndef VOLTAGE_BOX_H_
#define VOLTAGE_BOX_H_
#include <gtk/gtk.h>
#include "helper_functions.h"

/**
 * @brief Constructor for voltage gtk view
 *
 * Constructs the voltage_box GUI element which contains
 * the entry field for setting the voltage.
 *
 * @return GtkWidget 
 */
extern GtkWidget* voltage_box_new(void);

#endif
