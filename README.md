# Workshop 04. Mai 2012

## Inhalt

Der zweite Workshoptermin wird sich auch noch den Grundlagen widmen: »Dinge« und Speicher, Stack und Heap, Klassen und Instanzen (Objekte)

### Folien zum Vortrag

Die Vortragsfolien stehen BALD als [PDF](URL) zum Download bereit. Außerdem liegt der LaTeX-Quellcode zu den Folien im Ordner `slides`.

###Screencast

Ein Screencast des Vortrags wird nach dem Workshop an dieser Stelle verlinkt.

## Aufgaben

Sendet, nachdem ihr alle Aufgaben abgearbeitet habt, einen Pull-Request an das Workshop-Repository. Stellt sicher, dass ihr vorher alle eure Änderungen in euren Fork übertragen habt. Nennt euren Workshop-Betreuer im Text des Pull-Requests, einer der Betreuer (bevorzugt der genannte) wird dann eure Lösungen durchsehen, kommentieren und nach Abschluss des Reviews den Pull-Request als abgelehnt markieren.


### Aufgabe 1: Fibonacci-LUT

Eine LUT ist eine Lookup-Tabelle ( [siehe wikipedia](https://de.wikipedia.org/wiki/Lookup-Tabelle) ).
Diese speichert Daten (_hier: Fibonacci-Zahlen_) deart, dass auf diese Schnell mittels eines Schlüssels (_hier: die Nummer `n` der Fibonacci-Zahl_) zugegriffen werden kann.

Schreibe eine Fibonnaci-LUT als Klasse. Die Objekte der Klasse sollen mit einem Parameter erzeugt werden, der die größte Nummer der Fibonnaci-Zahlen festlegt.
Mittels einer Methode soll aus einem Objekt auf eine Fibonnaci-Zahl der LUT zugegriffen werden können.


Spoiler:
Verwende ein Array auf dem Heap und verwalte es im ctor und dtor.


### Aufgabe 2: Ringpuffer

Ein Ringpuffer ist eine Datenstruktur, in der endlich viele Daten gespeichert werden können. Wird versucht, mehr Daten hineinzuschreiben, so werden alte Daten überschrieben.
Siehe [wikipedia](https://de.wikipedia.org/wiki/Ringpuffer#Ringpuffer)

Schreibe eine Ringpuffer-Klasse, dessen Instanzen `double`s speichern können. Ein neues Datum (ein neuer `double`) soll hinzugefügt werden können (push), die vorhandenen Elemente in entgegengesetzter Reihenfolge zum Einfügen gelöscht (pop). 
Man soll mittels einer Methode auf jedes Element des Ringpuffers auslesen können (ob du überprüfst, ob dieses Element noch nicht beschrieben wurde, bleibt dir überlassen).


Spoiler:
Verwende die Fibonacci-LUT als Grundgerüst. Dann benötigst du nur noch einen zusätzlichen Pointer (und natürlich andere Methoden/Funktionen).