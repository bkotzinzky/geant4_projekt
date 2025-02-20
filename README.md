1. GEOMETRIA
Geometria symulacji składa się z trzech objętości: szalki Petriego, warstwy komórek umieszczonych na szalce oraz źródła. W rzeczywistości do napromieniania komórek korzystam ze źródła o bardzo niskiej mocy dawki (ok. 1uSv/h). Źródło to zostało specjalnie stworzone z myślą o tym projekcie. Jest ono wykonane z pokruszonych radioaktywnych łupków, które zostały wymieszane z żywicą epoksydową. Dlatego też zdefiniowana została objętość źródła, z której będą emitowane cząstki.

2. ŹRÓDŁO
Do stworzenia źródła korzystam z opcji GPS. Dzięki temu mogłem w łatwy sposób zdefiniować objętość, w której chcę tworzyć cząstki. Dodatkowo, energia cząstek jest wczytywana z pliku spectrum.mac, który odpowiada rzeczywistemu widmu, które zostało zmierzone w SLCJ.

3. OUTPUT
W symulacji zapisywane są 3 pliki. Pierwszy z nich (stat.txt) zapisuje najbardziej podstawowe informacje o symulacji, tj. czas jej wykonywania, średnia dawka zdeponowana w komórkach, liczba symulowanych eventów itd. Drugi plik (energy_distribution.txt) zapisuje powierzchniowy rozkład energii zdeponowanej w komórkach - komórki zostały podzielone na piksele a zdeponowana energia przypisywana jest do odpowiedniego z nich. W ten sposób sprawdzę na ile jednorodna jest zdeponowana dawka. Ostatni plik (data.root) składa się z dwóch drzew rootowych. Pierwsze zapisuje energię zdeponowaną w komórkach w każdym evencie, a drugie pozycję depozytu energii i jego wartość w każdym stepie. test
