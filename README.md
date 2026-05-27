# Laivų mūšis

Terminalinė klasikinio **Laivų mūšio (Battleship)** stalo žaidimo realizacija, parašyta C++17 kalba, taikant objektinio programavimo principus. Galima žaisti prieš kompiuterio valdomą priešininką 10×10 tinklelyje su standartine penkių laivų flotile.

---

## Savybės

* **Žmogus prieš AI** žaidimas 10×10 žaidimo lauke
* **Paprastas laivų išdėstymas** — įvedamos pradžios ir pabaigos koordinatės rankiniu būdu arba importuojama iš anksto paruoštą lentą iš failo
* **AI priešininkas** — automatiškai išdėsto laivus atsitiktinėse galimose vietose ir kiekvienu ėjimu šaudo į dar nepasirinktus langelius
* **Spalvotas terminalo vaizdavimas** — pataikymai pažymėti raudonai, nepataikymai geltonai, savi laivai mėlynai (reikalingas ANSI palaikantis terminalas)
* **Išdėstymo validacija** — tikrinama ar laivai neišeina už ribų, nesikerta, neliečia vienas kito ir nėra įstrižai
* **Automatinis aplinkos atskleidimas nuskendus laivui** — aplinkiniai langeliai automatiškai pažymimi kaip nepataikymai
* **Atskirų dalių testai**, apimantys Board, Ship, Human ir AI klases

---

## Klasių architektūra

```
Player  (abstrakti)
├── Human   — nuskaito šūvio koordinates iš stdin
└── AI      — automatiškai parenka atsitiktines dar nepanaudotas koordinates

Board   — valdo 10×10 tinklelio būseną ir laivų sąrašą
Ship    — saugo pradžios/pabaigos koordinates, pataikymų skaičių ir būseną (nuskendo ar ne)
Coordinates — paprasta (x, y) struktūra
Game    — valdo žaidimo inicijavimą ir pagrindinį ciklą
```

**Pagrindiniai projektavimo sprendimai:**

* `Player` yra abstrakti bazinė klasė su grynai virtualia funkcija `fireShot()`, užtikrinančia bendrą sąsają žmogui ir AI.
* `Board` priklauso `Player` (kompozicija), todėl kiekvieno žaidėjo lenta yra visiškai inkapsuliuota.
* `Game` naudoja `Player` polimorfizmą ir valdo ėjimų ciklą nežinodama, ar žaidėjas yra žmogus, ar AI.

---

## Naudojami projektavimo šablonai

### 1. Strategijos šablonas (Strategy Pattern)

`Player` klasė deklaruoja funkciją `fireShot()`, o `Human` ir `AI` ją realizuoja skirtingai — žmogus nuskaito koordinates iš klaviatūros, AI parenka jas automatiškai. `Game` ciklas kviečia `fireShot()` polimorfiškai, nežinodamas, su kuriuo žaidėju dirba.

```
Player
  └── fireShot() = 0       ← bendra sąsaja
        ├── Human::fireShot()   ← nuskaito iš stdin
        └── AI::fireShot()      ← atsitiktinė, dar nepanaudota koordinatė
```

### 2. Fasado šablonas (Facade Pattern)

`Game` klasė slepia vidinę sudėtingumą — `Board`, `Ship`, `Player`, `Coordinates` sąveiką — ir pateikia tik dvi viešas funkcijas: `runSetup()` ir `runGame()`. `main.cpp` nereikia žinoti jokių detalių apie žaidimo eigą.

```cpp
// main.cpp — visas žaidimas trimis eilutėmis
Game game;
game.runSetup();
game.runGame();
```

---

## Projekto struktūra

```
battleship/
├── include/                # Antraštiniai failai
│   ├── Coordinates.h
│   ├── Ship.h
│   ├── Board.h
│   ├── Player.h
│   ├── Human.h
│   ├── AI.h
│   └── Game.h
├── src/                    # Implementacijos failai
│   ├── main.cpp
│   ├── Ship.cpp
│   ├── Board.cpp
│   ├── Player.cpp
│   ├── Human.cpp
│   ├── AI.cpp
│   └── Game.cpp
├── tests/                  # Testai
│   ├── test.cpp
│   ├── BoardTest.{h,cpp}
│   ├── ShipTest.{h,cpp}
│   ├── HumanTest.{h,cpp}
│   └── AITest.{h,cpp}
├── build/                  # Sukompiliuoti failai (generuojami)
├── Makefile
├── Doxyfile
├── activity.drawio.png
├── use-case.drawio.png
└── README.md
```

---

## Klasių diagrama

![](https://github.com/justas-319/battleship/blob/main/class_graph.pdf)

---

## Reikalavimai

* **g++** su C++17 palaikymu
* **make**
* ANSI terminalas spalvoms

---

## Kompiliavimas ir paleidimas

```bash
make
./build/battleship
make clean
```

---

## Kaip žaisti

**Paruošimas**

1. Pasirenkama, ar importuoti lentą iš failo, ar dėlioti rankiniu būdu.
2. Jei rankiniu būdu — įvedama kiekvieno laivo pradžią ir pabaigą (x1 y1 x2 y2).

**Flotilė**

| Laivas       | Dydis |
| ------------ | ----- |
| Lėktuvnešis  | 5     |
| Karo laivas  | 4     |
| Kreiseris    | 3     |
| Povandeninis | 3     |
| Minininkas   | 2     |

**Žaidimo eiga**

* Įvedamos atakos koordinatės
* AI atlieka savo ėjimą
* Žaidžiama iki visiško laivų sunaikinimo

---

## Lentos failo importavimo formatas

```
x1 y1 x2 y2 (x5)
```

Pvz.:

```
0 0 4 0
0 2 3 2
0 4 2 4
0 6 2 6
0 8 1 8
```

---

## Lentos reikšmių kodavimas

| Skaičius | Reikšmė      |
| -------- | ------------ |
| 0        | tuščia       |
| 1        | laivas       |
| 2        | pataikymas   |
| 3        | nepataikymas |

---

## Žaidimo metu matomo vaizdo pavyzdys

![](https://github.com/justas-319/battleship/blob/main/Example_output.png)

---

## Dokumentacija

Generuojama su Doxygen.

```
doxygen Doxyfile
```

---

## Naudojamos technologijos

- [GitHub](github.com)
- [Discord](discord.com)

---

## Autoriai

* Justas Kurtinaitis
* Edgar Dainarovič
* Kamil Bužinski

---

## Darbų pasiskirstymas

* Justas Kurtinaitis - Game.cpp žaidimo logikos sukūrimas ir išvedimo į terminalą formatavimas.

* Edgar Dainarovič - Board.cpp ir Ship.cpp sukūrimas ir doxygen dokumentacijos paruošymas.

* Kamil Bužinski - Player.cpp, AI.cpp ir Human.cpp sukūrimas ir projekto dokumentacijos ReadMe paruošymas.

---

## Balų paskirstymas

Užduotis | Justas | Edgaras | Kamilis |
 ------- | ------ | ------- | ------- |
   P1    |  33%   |   33%   |   33%   |
   P2    |  33%   |   36%   |   30%   |
   P3    |  33%   |   33%   |   33%   |
