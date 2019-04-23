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
GtkWidget* coupling_box_new(void)
{
	GtkWidget *coupling_box;
	GtkWidget* entry;
	entry = gtk_entry_new();
	gtk_widget_set_name(entry, "coupling");
	
	coupling_box = gtk_vbox_new(FALSE, 2);
	GtkWidget *label = gtk_label_new("Coupling S or P: ");
  	GtkWidget *hbox = gtk_hbox_new(TRUE,2);

  	gtk_container_add(GTK_CONTAINER(hbox), label);
  	gtk_container_add(GTK_CONTAINER(hbox), entry);
  	gtk_container_add(GTK_CONTAINER(coupling_box), hbox);
	

	return coupling_box;
}

