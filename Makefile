CFLAGS = -Wall
TITLE = app

all:
	@cc $(CFLAGS) -c main.c plansza.c logika.c argumenty.c
	@cc main.o plansza.o logika.o argumenty.o -o $(TITLE)
	@echo Program został skompilowany jako: $(TITLE)
	@rm main.o plansza.o logika.o argumenty.o

clear:
	@rm $(TITLE)