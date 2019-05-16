/*
 * @file calculate_box.h
 * @author David Töyrä
 * @date 26 april 2019
 * @brief A gtk box containing the calculate functionality of electrotest.
 */

#ifndef CALC_BOX_H_
#define CALC_BOX_H_
#include <gtk/gtk.h>
#include "electrogui.h"
#include <stdlib.h>
#include <string.h>

/**
 * @brief Constructor of the lower GUI part.
 * 
 * Contains the calculate button and the output of power and resistance.
 *
 * @param gui A struct that contains pointers to all gui parts and to the
 * array which contains the resistor values.
 * @return GtkWidget* pointer to the widget with the calculate box.
 *
 */
extern GtkWidget* calc_result_box_new(struct gui_comp* gui);
#endif
