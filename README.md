<div align=center>
  <img src="https://i.imgur.com/kmK7sYT.png" width=80 heigh=80>
  <h1>Arduino Monopoly</h1>
  <p>Projekt zautomatyzowanej gry planszowej w oparciu o płytkę Arduino</p>
</div>

# Spis treści
1. [O projekcie](O-projekcie)
    - [Wykorzystane technologie](Wykorzystane-technologie)
2. [Instalacja](instalacja)
3. [Sposób użycia](sposób-użycia)

## O projekcie
Na przykładzie popularnej gry planszowej, projekt dotyka podstawowych zagadnień związanych z mikrokontrolerami:
- Uruchamianie kodu w C++ na mikrokontrolerach
- Obsługa GPIO
- Integracja środowiska programistycznego

Skonfigurowaliśmy automatyczną kompilację i wgrywanie projektu na mikrokontroler za pomocą CMake i PlatformIO
Zaimportowaliśmy odpowiednie biblioteki ze sterownikami do peryferiów
Utworzyliśmy abstrakcję kodu wykorzystując programowanie obiektowe w C++ (ze względu na brak czasu wyłącznie zarys pełnej logiki)

### Wykorzystane technologie
- Arduino UNO (lub w naszym przypadku kompatybilny klon)
- Moduł RFID 13.56MHz
- LCD z LiquidCrystal_I2C
- [InfraRed lib](https://github.com/Arduino-IRremote/Arduino-IRremote)
- [Adresowalna tasma LED](https://github.com/Aircoookie/WLED)

## Instalacja


## Sposób użycia
Kompilowaliśmy rozwiązanie za pomocą IDE CLion od Jetbrains, które znacząco uprościło tworzenie i debugwanie kodu, kompilację oraz instalację oprogramowania.
Rozpoczęcie rozgrywki następuje od razu po uruchomieniu płytki.

