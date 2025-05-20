BEWERTUNG: 32

# Auswertung der Abgabe

- Status: Abgabe wurde bewertet
- Punkte: **32** von **100**

## Test 1

- Test: *Erforderliche Dateien sind vorhanden*
- Beschreibung: Das erforderliche Makefile muss vorhanden sein.
- Status: ausgeführt
- Erfolgreich: **Ja**
- Laufzeit: 0:00:00.000034
##### Testschritte
- Makefile soll vorhanden sein: OK
- types.h soll vorhanden sein: OK
- network.h soll vorhanden sein: OK

## Test 2

- Test: *Qt-Projektdatei ist vorhanden*
- Beschreibung: Eine Projektdatei für das Qt-Projekt zum Erstellen mit `qmake` ist vorhanden.
- Status: ausgeführt
- Erfolgreich: **Ja**
- Laufzeit: 0:00:00.000345
- Punkte: **16**
##### Testschritte
- Für ./**/*.pro wurde ./project.pro gefunden: OK

## Test 3

- Test: *Makefile-Target autotest existiert*
- Beschreibung: Das Makefile besitzt ein Target zum Kompilieren der Tests.
- Status: ausgeführt
- Erfolgreich: **Ja**
- Laufzeit: 0:00:00.000148
- Punkte: **16**
##### Testschritte
- Inhalt von Makefile prüfen: OK

## Test 4

- Test: *Kompilieren der Tests*
- Beschreibung: Mit dem Befehl `make autotest` können die Tests kompiliert werden.
- Status: ausgeführt
- Erfolgreich: **Nein**
- Laufzeit: 0:00:01.492355
- Punkte: **0**
- Return-Code / Fehlercode: `2`
- Kommandozeile: `make autotest`
##### Testschritte
- Rückgabe-Code ist `0`: fehlgeschlagen

##### Ausgabe

```g++ -I. -I/usr/local/include -std=c++17 -o /repo/test_runner /tester.cpp /usr/local/lib/libgtest_main.a /usr/local/lib/libgtest.a network.cpp
```

##### Fehlerausgabe

```In file included from /tester.cpp:6:
/repo/network.h:11:19: error: field 'file' has incomplete type 'std::ifstream' {aka 'std::basic_ifstream<char>'}
   11 |     std::ifstream file;
      |                   ^~~~
In file included from /usr/local/include/c++/14.2.0/bits/localefwd.h:41,
                 from /usr/local/include/c++/14.2.0/string:45,
                 from /tester.cpp:3:
/usr/local/include/c++/14.2.0/iosfwd:118:11: note: declaration of 'std::ifstream' {aka 'class std::basic_ifstream<char>'}
  118 |     class basic_ifstream;
      |           ^~~~~~~~~~~~~~
network.cpp:1:9: warning: #pragma once in main file
    1 | #pragma once
      |         ^~~~
network.cpp:11:19: error: field 'file' has incomplete type 'std::ifstream' {aka 'std::basic_ifstream<char>'}
   11 |     std::ifstream file;
      |                   ^~~~
In file included from /usr/local/include/c++/14.2.0/bits/localefwd.h:41,
                 from /usr/local/include/c++/14.2.0/string:45,
                 from network.cpp:2:
/usr/local/include/c++/14.2.0/iosfwd:118:11: note: declaration of 'std::ifstream' {aka 'class std::basic_ifstream<char>'}
  118 |     class basic_ifstream;
      |           ^~~~~~~~~~~~~~
make: *** [Makefile:35: autotest] Error 1
```

##### Hinweise zur Behebung des Fehlers

- Stellen Sie sicher, dass der Kompilier-Befehl mit dem angegebenen Befehl aus dem Übungsblatt übereinstimmt.
- Sie dürfen in Ihren C++-Dateien, welche mit kompiliert werden, **keine** eigene main-Funktion haben. Kommentieren Sie diese ggf. aus.
- Entfernen Sie ggf. Dateien mit dem Namen `test_runner` aus Ihrem Repository.


## Test 5

- Test: *Ausführbare Anwendung der Unit-Tests wurde erstellt*
- Beschreibung: Die Anwendung wird mit Unit-Tests kompiliert und erzeugt die geforderte Datei `/repo/test_runner`.
- Status: nicht ausgeführt
- Erfolgreich: **Nein**
##### Hinweise zur Behebung des Fehlers

Der Test wurde nicht ausgeführt, da vorherige Tests fehlgeschlagen sind. Beheben Sie die vorherigen Probleme und versuchen Sie es dann erneut.

## Test 6

- Test: *Ausführbare Anwendung der Unit-Tests enthält die Testfälle*
- Beschreibung: Die geforderte Datei `/repo/test_runner` enthält die `tester.cpp`-Datei.
- Status: nicht ausgeführt
- Erfolgreich: **Nein**
##### Hinweise zur Behebung des Fehlers

Der Test wurde nicht ausgeführt, da vorherige Tests fehlgeschlagen sind. Beheben Sie die vorherigen Probleme und versuchen Sie es dann erneut.

## Test 7

- Test: *QMake kann ausgeführt werden*
- Beschreibung: qmake erzeugt ein Makefile für die Anwendung
- Status: nicht ausgeführt
- Erfolgreich: **Nein**
- Punkte: **0**
##### Hinweise zur Behebung des Fehlers

Der Test wurde nicht ausgeführt, da vorherige Tests fehlgeschlagen sind. Beheben Sie die vorherigen Probleme und versuchen Sie es dann erneut.

## Test 8

- Test: *Erzeugtes Makefile kann die Anwendung erstellen*
- Beschreibung: Das erzeugte Makefile für die Anwendung kann kompiliert werden.
- Status: nicht ausgeführt
- Erfolgreich: **Nein**
- Punkte: **0**
##### Hinweise zur Behebung des Fehlers

Der Test wurde nicht ausgeführt, da vorherige Tests fehlgeschlagen sind. Beheben Sie die vorherigen Probleme und versuchen Sie es dann erneut.

## Test 9

- Test: *Testfälle werden korrekt ausgeführt*
- Beschreibung: Die Unit-Tests der Anwendung werden korrekt ausgeführt (max. Laufzeit 60 Sekunden).
- Status: nicht ausgeführt
- Erfolgreich: **Nein**
- Punkte: **0**
##### Hinweise zur Behebung des Fehlers

Der Test wurde nicht ausgeführt, da vorherige Tests fehlgeschlagen sind. Beheben Sie die vorherigen Probleme und versuchen Sie es dann erneut.

