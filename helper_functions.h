#include <gtk/gtk.h>

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
extern GtkWidget* add_widget_with_label_vbox(GtkContainer *box, gchar *caption, GtkWidget *widget);

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
extern GtkWidget* add_widget_with_label_hbox(GtkContainer *box, gchar *caption, GtkWidget *widget);

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
extern GtkWidget* find_child(GtkWidget* parent, const gchar* name);

/**
 * @brief Helper to create entry widget with a name
 *
 * Naming widgets is handy as they can be searched easily
 * with find_child() also provided in this helper function collection.
 *
 * @param name string on how to name the new entry widget
 * @return GtkWidget* pointer to the constructed and named gtk_entry widget
 */
extern GtkWidget* gtk_entry_with_name_new(gchar *name);

#endif /* ADD_LABEL_HELPER_H_ */
