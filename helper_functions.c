#include <gtk/gtk.h>
#include "helper_functions.h"


/**
 * @brief Function constructs a label above a provided widget
 *
 * The function creates a new vbox and a label. The provided
 * widget is put in the vbox together with the new label which
 * results in a label above the widget. The vbox is then put
 * into the provided container/box.
 *
 * @param box Gtk Container into which the vbox with label and widget shall be added
 * @param caption String used to construct the caption
 * @param widget widget to which a label shall be constructed
 * @return GtkWidget* returns pointer to the given box/container.
 * This is not always needed but sometimes of advantage when multiple widgets shall be constructed
 * in a loop with a deeply nested constructor.
 */
GtkWidget* add_widget_with_label_vbox(GtkContainer *box, gchar *caption, GtkWidget *widget){
  GtkWidget *label = gtk_label_new(caption);
  GtkWidget *vbox = gtk_vbox_new(TRUE, 2);

  gtk_container_add(GTK_CONTAINER(vbox), label);
  gtk_container_add(GTK_CONTAINER(vbox), widget);
  gtk_container_add(box, vbox);

  return vbox;
}

/**
 * @brief Function constructs a label to the left of a provided widget
 *
 * The function creates a new hbox and a label. The provided
 * widget is put in the hbox together with the new label which
 * results in a label to the left of the widget. The hbox is then put
 * into the provided container/box.
 *
 * @param box Gtk Container into which the hbox with label and widget shall be added
 * @param caption String used to construct the caption
 * @param widget widget to which a label shall be constructed
 * @return GtkWidget* returns pointer to the given box/container.
 * This is not always needed but sometimes of advantage when multiple widgets shall be constructed
 * in a loop with a deeply nested constructor.
 */
GtkWidget* add_widget_with_label_hbox(GtkContainer *box, gchar *caption, GtkWidget *widget){
  GtkWidget *label = gtk_label_new(caption);
  GtkWidget *hbox = gtk_hbox_new(TRUE,2);

  gtk_container_add(GTK_CONTAINER(hbox), label);
  gtk_container_add(GTK_CONTAINER(hbox), widget);
  gtk_container_add(box, hbox);

  return hbox;
}

/**
 * @brief Helper to create entry widget with a name
 *
 * Naming widgets is handy as they can be searched easily
 * with find_child() also provided in this helper function collection.
 *
 * @param name string on how to name the new entry widget
 * @return GtkWidget* pointer to the constructed and named gtk_entry widget
 */
GtkWidget* gtk_entry_with_name_new(gchar *name){
	GtkWidget* entry;
	printf("entry_with_name\n");
	entry = gtk_entry_new();
	gtk_widget_set_name(entry, name);
	printf("set name done\n");
	return entry;
}


/**
 * @brief Find recursively child widgets of a GTK container by name
 *
 * Recursive search of child widgets in a GTK container structure. The
 * function returns, when found a pointer to the respective widget, else
 * NULL.
 * @param parent Widget to start the search at.
 * @param name String of the name to search for
 * @return pointer to the found widget or NULL
 */
GtkWidget* find_child(GtkWidget* parent, const gchar* name){
	if (g_ascii_strcasecmp(gtk_widget_get_name((GtkWidget*)parent), (gchar*)name) == 0){
		return parent;
	}

    if (GTK_IS_BIN(parent)) {
    	GtkWidget *child = gtk_bin_get_child(GTK_BIN(parent));
        return find_child(child, name);
    }


    if (GTK_IS_CONTAINER(parent)) {
    	GList *children = gtk_container_get_children(GTK_CONTAINER(parent));
    	do {
    		GtkWidget* widget = find_child(children->data, name);
    		if (widget != NULL) {
    			return widget;
    		}
    	} while ((children = g_list_next(children)) != NULL);
    }
    return NULL;
}
