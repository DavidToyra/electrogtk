/*
 * @file coupling_box.h
 * @author David Töyrä
 * @date 26 april 2019
 * @brief A gtk box containing the coupling options of serial or parallel.
 */
#ifndef COUPLING_BOX_H_
#define COUPLING_BOX_H_
#include <gtk/gtk.h>
#include "helper_functions.h"


/**
 * @brief Constructor for the Resistor Coupling Gui part
 *
 * The coupling takes an input of either s or p, it is undefined
 * for something else.
 *
 * @return GtkWidget* pointer to the new created Gui part.
 *
 */
extern GtkWidget* coupling_box_new(void);
#endif

