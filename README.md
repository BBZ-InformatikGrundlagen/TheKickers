# TheKickers
Gianni/Kevin
**********************************************************
Betriebsanleitung für Automatische Toranzeige Tischkicker
**********************************************************
Auf jeder Torseite gibt es eine Anzeige, welche die erzielten Tore der eigenen Mannschaft anzeigt.
Die Toranzeige startet mit dem Wert 0.
Die Torerkennung erfolgt automatisch über einen Sensor.
Sobald der Sensor einen Ball erkennt, wird die Anzeige automatisch um 1 erhöht und zeigt den aktuellen Torstatus am Display.
Um die Anzeige zurück auf den Ausgangswert (null) zu setzen, können die Taster (A) und (B) am MicroBit gedrückt werden.
Sollte die Toranzeige während dem Spiel manuell korrigiert werden müssen, kann dies über die Taster links und rechts vom MicroBit durchgeführt werden.
Der Taster (A) links am MicroBit korrigiert die Anzeige um minus eins.
Der Taster (B) rechts am MicroBit korrigiert die Anzeige um plus eins.
Bei einem Sieg (Tore = 10), wird das Ende des Spiels durch einen Signalton ausgerufen und die Anzeige wird zurück auf null gesetzt.
