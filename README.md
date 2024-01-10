# JIMP_Projekt Program Symulacji Mrówki Langtona



## Opis


Program symuluje zachowanie [Mrówki Langtona](https://pl.wikipedia.org/wiki/Mr%C3%B3wka_Langtona), automatu komórkowego zaproponowanego przez Chrisa Langtona w 1986 roku. W każdym kroku mrówka obraca się w lewo lub w prawo, zmienia kolor komórki, na której stoi, a następnie przemieszcza się do następnej komórki.

## Funkcje

- Tworzenie planszy o określonych wymiarach.
- Wykonywanie określonej liczby kroków symulacji.
- Zapisywanie stanu planszy po każdej iteracji do plików.
- Możliwość wczytywania stanu początkowego planszy z pliku.
- Ustawienie początkowego kierunku mrówki.

## Wymagania

- Kompilator języka C.
- System operacyjny UNIX (Linux, macOS).

## Kompilacja

Program można skompilować za pomocą narzędzia `make` na pliku "Makefile". Przykładowa komenda kompilacji:

```bash
make -f Makefile
```

## Użycie

```bash
./app [opcje]
```


Gdzie opcje mogą zawierać:

- `-w <szerokość>`: Szerokość planszy (domyślnie 10).
- `-h <wysokość>`: Wysokość planszy (domyślnie 10).
- `-i <iteracje>`: Liczba iteracji symulacji (domyślnie 10).
- `-d <kierunek>`: Początkowy kierunek mrówki (NORTH, EAST, SOUTH, WEST) (domyślnie NORTH).
- `-o <zagęszczenie>`: Zagęszczenie przeszkód na planszy (procentowo od 0 do 100) (domyślnie 0).
- `-n <nazwa_pliku>`: Bazowa nazwa pliku do zapisu stanu planszy. (domyślnie pliki są zapisywane w folderze "output").
- `-l <nazwa_pliku>`: Nazwa pliku do wczytania początkowego.stanu planszy. (domyślnie plik jest zcztywany z folderu "source").
- `-p` : Wypisuje pomoc dla programu.

## Przykładowe Uruchomienie

```bash
./app -w 20 -h 20 -i 100 -d NORTH -o 30 -n symulacja
```

## Autorzy
Stanisław Dutkiewicz\
Filip Kobus
