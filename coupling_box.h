#ifndef COUPLING_BOX_H_
#define COUPLING_BOX_H_
#include <gtk/gtk.h>
#include "helper_functions.h"

typedef struct{
	GtkWidget* coupling;
	GtkWidget* coupling_box;
} Couplings;

/**
 * @brief Constructor for the Resistor Coupling Gui part
 *
 * The Resistor coupling GUI part allows to choose between serial/parallel
 * coupling of the resistors.
 *
 * @return GtkWidget* pointer to the new created Gui part.
 *
 */
extern Couplings* coupling_box_new(void);
#endif

