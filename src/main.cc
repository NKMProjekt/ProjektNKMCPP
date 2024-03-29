/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-  */
/*
 * main.cc
 * Copyright (C) 2012 Noemi Szypuła, Karol Piotrowicz, Marcin Kurtz <nkmprojekt@gmail.com>
 * 
 */

#include <gtkmm.h>
#include <iostream>
#include "tetrisWindow.h"
#include "config.h"

int
main (int argc, char *argv[])
{
	Glib::RefPtr<Gtk::Application> app = Gtk::Application::create(argc, argv, "org.gtkmm.tetris");//Referencja do aplikacji GTKMM Tetris++

	Tetris window;

	return app->run(window);
}

