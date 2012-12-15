/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-  */
/*
 * main.cc
 * Copyright (C) 2012 Noemi Szypuła, Karol Piotrowicz, Marcin Kurtz <nkmprojekt@gmail.com>
 * 
 */

#include <gtkmm.h>
#include <iostream>
#include "config.h"

/* For testing propose use the local (not installed) ui file */
/* #define UI_FILE PACKAGE_DATA_DIR"/ui/tetris.ui" */
#define UI_FILE "src/tetris.ui"

Gtk::Dialog* pDialog = 0;

void on_button_clicked()
{
	if(pDialog)
		pDialog -> show();
}

void on_buttonQuit_clicked()
{
	if(pDialog)
		pDialog -> hide();
}

int
main (int argc, char *argv[])
{
	Gtk::Main kit(argc, argv);


	//Ładowanie UI z pliku glade
	Glib::RefPtr<Gtk::Builder> builder;

	try
	{
		builder = Gtk::Builder::create_from_file(UI_FILE);
	}
	catch (const Glib::FileError & ex)
	{
		std::cerr << ex.what() << std::endl;
		return 1;
	}

	
	Gtk::Window* main_win = 0;
	builder->get_widget("main_window", main_win);

	builder->get_widget("dialogTest",pDialog);

	if (main_win)
	{
		Gtk::Button* button = 0;
		builder->get_widget("button_test", button);

		Gtk::Button* buttonQuit = 0;
		builder->get_widget("button_quit", buttonQuit);

		if(button && buttonQuit)
		{
			button->signal_clicked().connect(sigc::ptr_fun(on_button_clicked));
			buttonQuit->signal_clicked ().connect(sigc::ptr_fun(on_buttonQuit_clicked));
		}
		
		kit.run(*main_win);
	}

	delete(main_win);
	return 0;
}

