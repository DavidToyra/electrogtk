#ifndef VOLTAGE_BOX_H_
#define VOLTAGE_BOX_H_
#include <gtk/gtk.h>
#include "helper_functions.h"


typedef struct{
	GtkWidget* voltage;
	GtkWidget* voltage_box;
} VoltageWidgets;

extern VoltageWidgets* voltage_box_new(void);
#endif
