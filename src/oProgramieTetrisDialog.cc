/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-  */
/*
 * oProgramieTetrisDialog.cc
 * Copyright (C) 2012 Noemi Szypuła, Karol Piotrowicz, Marcin Kurtz <nkmprojekt@gmail.com>
 * 
 */

#include "oProgramieTetrisDialog.h"

OProgramieTetrisDialog::OProgramieTetrisDialog()
{
	wersjaTetris = "Wersja 0.01";
	nazwaTetris = "Tetris++";
	stronaWWW = "https://github.com/NKMProjekt";

	autorzyProgramu.push_back (Glib::ustring("Noemi Szypuła"));
	autorzyProgramu.push_back (Glib::ustring("Karol Piotrowicz"));
	autorzyProgramu.push_back (Glib::ustring("Marcin Kurtz"));

	oProgramie = "Gra napisana w C++ na zaliczenie przedmiotu Programowanie w C++.";

	/* Ustawianie właściwości AboutDialog */
	set_program_name(nazwaTetris);
	set_version (wersjaTetris);
	set_authors (autorzyProgramu);
	set_comments (oProgramie);
	set_website (stronaWWW);
}

OProgramieTetrisDialog::~OProgramieTetrisDialog()
{
}

