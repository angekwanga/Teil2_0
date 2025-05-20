BEWERTUNG: 100

# Auswertung der Abgabe

- Status: Abgabe wurde bewertet
- Punkte: **100** von **100**

## Test 1

- Test: *Erforderliche Dateien sind vorhanden*
- Beschreibung: Das erforderliche Makefile muss vorhanden sein.
- Status: ausgeführt
- Erfolgreich: **Ja**
- Laufzeit: 0:00:00.000105
##### Testschritte
- Makefile soll vorhanden sein: OK
- types.h soll vorhanden sein: OK
- network.h soll vorhanden sein: OK

## Test 2

- Test: *Qt-Projektdatei ist vorhanden*
- Beschreibung: Eine Projektdatei für das Qt-Projekt zum Erstellen mit `qmake` ist vorhanden.
- Status: ausgeführt
- Erfolgreich: **Ja**
- Laufzeit: 0:00:00.000327
- Punkte: **16**
##### Testschritte
- Für ./**/*.pro wurde ./project.pro gefunden: OK

## Test 3

- Test: *Makefile-Target autotest existiert*
- Beschreibung: Das Makefile besitzt ein Target zum Kompilieren der Tests.
- Status: ausgeführt
- Erfolgreich: **Ja**
- Laufzeit: 0:00:00.000142
- Punkte: **16**
##### Testschritte
- Inhalt von Makefile prüfen: OK

## Test 4

- Test: *Kompilieren der Tests*
- Beschreibung: Mit dem Befehl `make autotest` können die Tests kompiliert werden.
- Status: ausgeführt
- Erfolgreich: **Ja**
- Laufzeit: 0:00:02.714754
- Punkte: **16**
- Return-Code / Fehlercode: `0`
- Kommandozeile: `make autotest`
##### Testschritte
- Rückgabe-Code ist `0`: OK

##### Ausgabe

```g++ -I. -I/usr/local/include -std=c++17 -o /repo/test_runner /tester.cpp /usr/local/lib/libgtest_main.a /usr/local/lib/libgtest.a network.cpp
```

## Test 5

- Test: *Ausführbare Anwendung der Unit-Tests wurde erstellt*
- Beschreibung: Die Anwendung wird mit Unit-Tests kompiliert und erzeugt die geforderte Datei `/repo/test_runner`.
- Status: ausgeführt
- Erfolgreich: **Ja**
- Laufzeit: 0:00:00.000020
##### Testschritte
- test_runner soll vorhanden sein: OK

## Test 6

- Test: *Ausführbare Anwendung der Unit-Tests enthält die Testfälle*
- Beschreibung: Die geforderte Datei `/repo/test_runner` enthält die `tester.cpp`-Datei.
- Status: ausgeführt
- Erfolgreich: **Ja**
- Laufzeit: 0:00:00.201525
- Return-Code / Fehlercode: `0`
- Kommandozeile: `readelf -s --wide /repo/test_runner`
##### Testschritte
- Ausgabe ist korrekt: OK
- Rückgabe-Code ist `0`: OK

##### Ausgabe

```<AUSGABE WIRD NICHT ANGEZEIGT>
```

## Test 7

- Test: *QMake kann ausgeführt werden*
- Beschreibung: qmake erzeugt ein Makefile für die Anwendung
- Status: ausgeführt
- Erfolgreich: **Ja**
- Laufzeit: 0:00:00.283912
- Punkte: **16**
- Return-Code / Fehlercode: `0`
- Kommandozeile: `/usr/bin/qmake6 /repo/./project.pro`
##### Testschritte
- Rückgabe-Code ist `0`: OK

##### Ausgabe

```Info: creating stash file /repo/build/.qmake.stash
```

## Test 8

- Test: *Erzeugtes Makefile kann die Anwendung erstellen*
- Beschreibung: Das erzeugte Makefile für die Anwendung kann kompiliert werden.
- Status: ausgeführt
- Erfolgreich: **Ja**
- Laufzeit: 0:00:08.795673
- Punkte: **16**
- Return-Code / Fehlercode: `0`
- Kommandozeile: `make`
##### Testschritte
- Rückgabe-Code ist `0`: OK

##### Ausgabe

```g++ -c -pipe -O2 -std=gnu++1z -Wall -Wextra -fPIC -D_REENTRANT -DQT_NO_DEBUG -DQT_WIDGETS_LIB -DQT_GUI_LIB -DQT_CORE_LIB -I/repo -I. -I/usr/include/x86_64-linux-gnu/qt6 -I/usr/include/x86_64-linux-gnu/qt6/QtWidgets -I/usr/include/x86_64-linux-gnu/qt6/QtGui -I/usr/include/x86_64-linux-gnu/qt6/QtCore -I. -I/usr/lib/x86_64-linux-gnu/qt6/mkspecs/linux-g++ -o main.o ../main.cpp
g++ -c -pipe -O2 -std=gnu++1z -Wall -Wextra -fPIC -D_REENTRANT -DQT_NO_DEBUG -DQT_WIDGETS_LIB -DQT_GUI_LIB -DQT_CORE_LIB -I/repo -I. -I/usr/include/x86_64-linux-gnu/qt6 -I/usr/include/x86_64-linux-gnu/qt6/QtWidgets -I/usr/include/x86_64-linux-gnu/qt6/QtGui -I/usr/include/x86_64-linux-gnu/qt6/QtCore -I. -I/usr/lib/x86_64-linux-gnu/qt6/mkspecs/linux-g++ -o mainwindow.o ../mainwindow.cpp
g++ -c -pipe -O2 -std=gnu++1z -Wall -Wextra -fPIC -D_REENTRANT -DQT_NO_DEBUG -DQT_WIDGETS_LIB -DQT_GUI_LIB -DQT_CORE_LIB -I/repo -I. -I/usr/include/x86_64-linux-gnu/qt6 -I/usr/include/x86_64-linux-gnu/qt6/QtWidgets -I/usr/include/x86_64-linux-gnu/qt6/QtGui -I/usr/include/x86_64-linux-gnu/qt6/QtCore -I. -I/usr/lib/x86_64-linux-gnu/qt6/mkspecs/linux-g++ -o network.o ../network.cpp
g++ -pipe -O2 -std=gnu++1z -Wall -Wextra -fPIC -dM -E -o moc_predefs.h /usr/lib/x86_64-linux-gnu/qt6/mkspecs/features/data/dummy.cpp
/usr/lib/qt6/libexec/moc -DQT_NO_DEBUG -DQT_WIDGETS_LIB -DQT_GUI_LIB -DQT_CORE_LIB --include /repo/build/moc_predefs.h -I/usr/lib/x86_64-linux-gnu/qt6/mkspecs/linux-g++ -I/repo -I/usr/include/x86_64-linux-gnu/qt6 -I/usr/include/x86_64-linux-gnu/qt6/QtWidgets -I/usr/include/x86_64-linux-gnu/qt6/QtGui -I/usr/include/x86_64-linux-gnu/qt6/QtCore -I. -I/usr/local/include/c++/14.2.0 -I/usr/local/include/c++/14.2.0/x86_64-linux-gnu -I/usr/local/include/c++/14.2.0/backward -I/usr/local/lib/gcc/x86_64-linux-gnu/14.2.0/include -I/usr/local/include -I/usr/local/lib/gcc/x86_64-linux-gnu/14.2.0/include-fixed -I/usr/include/x86_64-linux-gnu -I/usr/include ../mainwindow.h -o moc_mainwindow.cpp
g++ -c -pipe -O2 -std=gnu++1z -Wall -Wextra -fPIC -D_REENTRANT -DQT_NO_DEBUG -DQT_WIDGETS_LIB -DQT_GUI_LIB -DQT_CORE_LIB -I/repo -I. -I/usr/include/x86_64-linux-gnu/qt6 -I/usr/include/x86_64-linux-gnu/qt6/QtWidgets -I/usr/include/x86_64-linux-gnu/qt6/QtGui -I/usr/include/x86_64-linux-gnu/qt6/QtCore -I. -I/usr/lib/x86_64-linux-gnu/qt6/mkspecs/linux-g++ -o moc_mainwindow.o moc_mainwindow.cpp
g++ -Wl,-O1 -Wl,-rpath-link,/usr/lib/x86_64-linux-gnu -o gtfs_search  main.o mainwindow.o network.o moc_mainwindow.o   /usr/lib/x86_64-linux-gnu/libQt6Widgets.so /usr/lib/x86_64-linux-gnu/libQt6Gui.so /usr/lib/x86_64-linux-gnu/libGLX.so /usr/lib/x86_64-linux-gnu/libOpenGL.so /usr/lib/x86_64-linux-gnu/libQt6Core.so -lpthread -lGLX -lOpenGL
```

## Test 9

- Test: *Testfälle werden korrekt ausgeführt*
- Beschreibung: Die Unit-Tests der Anwendung werden korrekt ausgeführt (max. Laufzeit 60 Sekunden).
- Status: ausgeführt
- Erfolgreich: **Ja**
- Laufzeit: 0:00:07.241014
- Punkte: **20**
- Return-Code / Fehlercode: `0`
- Kommandozeile: `/repo/test_runner`
##### Testschritte
- Rückgabe-Code ist `0`: OK

##### Ausgabe

```Running main() from /usr/src/googletest/googletest/src/gtest_main.cc
[==========] Running 2 tests from 1 test suite.
[----------] Global test environment set-up.
[----------] 2 tests from Network
[ RUN      ] Network.DataRead
[       OK ] Network.DataRead (3537 ms)
[ RUN      ] Network.Search
[       OK ] Network.Search (3489 ms)
[----------] 2 tests from Network (7027 ms total)

[----------] Global test environment tear-down
[==========] 2 tests from 1 test suite ran. (7027 ms total)
[  PASSED  ] 2 tests.
```

