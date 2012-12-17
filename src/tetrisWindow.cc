/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-  */
/*
 * tetris.cc
 * Copyright (C) 2012 Noemi Szypuła, Karol Piotrowicz, Marcin Kurtz <nkmprojekt@gmail.com>
 * 
 */

#include <iostream>
#include "tetrisWindow.h"
#include "oProgramieTetrisDialog.h"

//Konstruktor Tetris++
Tetris::Tetris() :
buttonNowaGra("Nowa gra"),
buttonWyjdzZGry("Wyjdź z gry"),
buttonOProgramie("O programie"),
etkietaLiczbyPunktow("<b>Liczba punktów</b>"),
etykietaLiczbaPunktowGracza("<span size='20000'><b>1000 pkt.</b></span>"),//Pango Markup style 2000 = 20 * 1000 dla 20pt
boxOknoGlowne(Gtk::ORIENTATION_HORIZONTAL,10),//10 odlegosc marginesu pomiedzy widgetami
boxMenuGlowne(Gtk::ORIENTATION_VERTICAL,10)//10 odlegosc marginesu pomiedzy widgetami
{
	nazwaOknaGry = "Tetris++";//Nazwa okna gry
	set_title (nazwaOknaGry);//Ustawianie nazwy okna
	set_border_width(10);//Ustalanie odległości od marginesu
	set_size_request (450,500);//Ustalanie minimalej wielkośic okna
	
	//Edycja etykiet, dodawanie możliwości zmiany stylu
	etykietaLiczbaPunktowGracza.set_use_markup(true);
	etkietaLiczbyPunktow.set_use_markup (true);

	//Dodawanie grid do okna
	add(boxOknoGlowne);

	//Dodawanie planszy gry
	planszaGry.set_size_request (300,480);//Edycja wielkosci planszy
	boxOknoGlowne.pack_start(planszaGry);
	
	//Dodawanie do boxOknoGlowne boxMenuGlowne
	boxOknoGlowne.pack_start(boxMenuGlowne);

	//Ustawienia boxMenuGlowne
	boxMenuGlowne.set_size_request (150,480);

	//Dodawanie etykiet do boxMenuGlowne
	boxMenuGlowne.pack_start(etkietaLiczbyPunktow,Gtk::PACK_SHRINK);
	boxMenuGlowne.pack_start(etykietaLiczbaPunktowGracza,Gtk::PACK_SHRINK);
	
	//Edycja wielkosci przyciskow
	buttonNowaGra.set_size_request (150,40);
	buttonWyjdzZGry.set_size_request (150,40);
	buttonOProgramie.set_size_request (150,40);
	
	//Dodawanie nastepnych przyciskow do boxMenuGlowne
	boxMenuGlowne.pack_start(buttonNowaGra,Gtk::PACK_SHRINK);
	boxMenuGlowne.pack_start(buttonWyjdzZGry,Gtk::PACK_SHRINK);
	boxMenuGlowne.pack_start(buttonOProgramie,Gtk::PACK_SHRINK);	
	
	//Przyłączanie sygnałów przycisków do funkcji
	buttonNowaGra.signal_clicked().connect(sigc::mem_fun(*this,&Tetris::NowaGra));
	buttonOProgramie.signal_clicked().connect(sigc::mem_fun(*this,&Tetris::OProgramie));
	
	//Łączenie z przekazaniem argumentów
	buttonWyjdzZGry.signal_clicked().connect(sigc::bind<Glib::ustring>(sigc::mem_fun (*this,&Tetris::WyjdzZGry),"OK"));

	//Wyświetlanie wszystkich widgetow okna
	show_all_children();
}

//Destruktor
Tetris::~Tetris()
{
}

//Handler dla przycisku buttonNowaGra
void Tetris::NowaGra()
{
	std::cout << "Wybrano nowa gre!" << std::endl;
}

//Handler dla przycisku buttonNowaGra
void Tetris::OProgramie()
{
	OProgramieTetrisDialog oProgramie;
	oProgramie.run();
}

//Handler dla przycisku buttonWyjdzZGry
void Tetris::WyjdzZGry(const Glib::ustring& dane)
{
	std::cout << "Wybrano wyjście z gry! " << dane << std::endl;
}