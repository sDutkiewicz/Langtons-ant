CFLAGS = -Wall
TITLE = app

all:
	@cc $(CFLAGS) -c main.c plansza.c logika.c
	@cc main.o plansza.o logika.o -o $(TITLE)
	@echo Program został skompilowany jako: $(TITLE)
	@rm main.o plansza.o logika.o

clear:
	@rm $(TITLE)