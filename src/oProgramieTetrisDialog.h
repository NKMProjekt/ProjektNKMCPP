/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-  */
/*
 * oProgramieTetrisDialog.h
 * Copyright (C) 2012 Noemi Szypuła, Karol Piotrowicz, Marcin Kurtz <nkmprojekt@gmail.com>
 * 
 */

#include <gtkmm/aboutdialog.h>
#include <vector>

class OProgramieTetrisDialog : public Gtk::AboutDialog
{
	public:
		OProgramieTetrisDialog();
		virtual ~OProgramieTetrisDialog();
	private:
		Glib::ustring wersjaTetris, nazwaTetris, oProgramie,stronaWWW;
		std::vector<Glib::ustring> autorzyProgramu;
};