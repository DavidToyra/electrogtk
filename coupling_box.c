#include <gtk/gtk.h>
#include "coupling_box.h"



/**
 * @brief Constructor for the Resistor Coupling Gui part
 *
 * The Resistor coupling GUI part allows to choose between serial/parallel
 * coupling of the resistors.
 *
 * @return GtkWidget* pointer to the new created Gui part.
 *
 */
Couplings* coupling_box_new(void)
{
	Couplings *couplings;
	couplings->coupling = gtk_entry_with_name_new("coupling");
	couplings->coupling_box = gtk_vbox_new(FALSE, 2);
	add_widget_with_label_vbox(GTK_CONTAINER(couplings->coupling_box),
	 "Coupling(S or P):", couplings->coupling);

	return couplings;
}

