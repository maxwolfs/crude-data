# Crude Data

* Maximilian Wolfs (c) 2017 - 2018
* mwolfs@hfk-bremen.de

![alt text](https://github.com/maxwolfs/crude-data/blob/master/documentation/CD_hst_totale.jpg "Logo Title Text 1")

#### Introduction

The installation translates the virtual real time value of one barrel of crude oil (Brent) in USD as traded in the ICE Future Market in London into an electromechanical 7-segment display. The portly IoT-Machine emphasizes the difference of the material and the abstracted derivative acting as an encoder of the pulse of the global economic machine.

#### Conceptual Background

Crude Oil is if not the most important resource of our planet. Its whereabouts and especially its price determines about war and peace, wealth and poverty. Oil is not only the fuel of the world economy but also the core of an enormous amount of industrial products. But there is big gap in our western society between the actual raw liquid and its virtual value. Most of us have never experienced oil aesthetically with our senses. It only exists in the most artificial abstracted and rational way, as data, changing in real-time and traded by machines.

Das Barrel als Handelsgröße ist aufgrund des unvorstellbaren Handelsvolumen in Millionen von Litern heute nur noch ein historisches Leftover. Ebenso existiert die Sorte Brent nur noch als historische Referenz an der Börse. War das Feld in der britischen Nordsee mit seinen vier Förderplattformen in den 1970er Jahren von immenser wirtschaftlicher und geopolitischer Bedeutung für die Unabhänigkeit der Ölversorgung Europas, stellen die Plattformen heute nur noch teure und umweltproblematische Abschreibungen der Ölkonzerne dar. Ebenso erstaunlich ist der Kontrast der Zeitlichkeit: Innerhalb von Milliarden Jahren aus Organismen unter hohem Druck entstanden, innerhalb von Dekaden verbrannt und verarbeitet und in Millisekunden gehandelt.

#### Technical Background

The work consists of four electromechanical 7-segment displays. Each of them consists of seven gear motors which are able to flap 90° to form a pattern with 128 possibilites. Ten of these possible patterns translate as the arabic numbers ranging from 0 - 10. On top of each flap are Leds, which not connected to the logic of the motors and are either all on or off. This makes the steel frame necessary to hide the noise of light emission of the inactive segments. This weird design itself goes back to their former use in a gas station in Berlin Köpenick.

In einer techno-archäologischen Untersuchung wurde sich den ausgedienten mit Spinnennestern versäten Maschinen angenähert. Zunächst wurden die Bauteile identifiziert und deren Verbindungen auf der Platine auf einem großen Plan nachgezeichnet, um so einen eigens Programm zu entwerfen zu können. Durch eine offene Programmierschnittstelle war es möglich den eigenen Progammcode den auf der alten Platine unzugänglichen zu überschreiben und so die Anzeigen wieder zu einem zweiten Leben zu erwecken. In einem weiteren Schritt wurde ein weiteres Modul entwickelt, bestehend aus einem Microcontroller mit WiFi Verbindung, der mittels Web API den aktuellsten Wert abfragt und diesen via serieller Schnittstelle an die einzelenen Module zur Übersetzung schickt.

Es entsteht eine kinetische Lichinstallation, in ihrem ursprünglich Sinn gebaut um Kraftfahrzeughaltern den aktuellen Diesel- oder Benzinpreis aus großer Entfernung anzuzeigen, nun dekontextualisiert um als absurde Maschine, angetrieben vom Puls des globalen datengetriebenen Rohstoffhandels in rhythmischen Bewegungen diesen nicht richtig fassbaren und dennoch geopolitisch bedeutenden Wert ästhetisch erfahrbar zu machen.

#### Exhibitions

* 9.2. - 10.2.2018 at HFK Bremen: Hochschultage 2018
* 27.2.2017 at FAQ Bremen: RTFM: The Technological Sublime

[![Crude Data at FAQ](https://i.imgur.com/Y2USpJY.png)](https://vimeo.com/247011682 "Crude Data at FAQ")

![alt text](https://github.com/maxwolfs/crude-data/blob/master/documentation/CD_hst_totale_ghost.jpg "Logo Title Text 1")

![alt text](https://github.com/maxwolfs/crude-data/blob/master/documentation/FAQ_Halbtotale_1_Dunkel_2.jpg "Logo Title Text 1")

![alt text](https://github.com/maxwolfs/crude-data/blob/master/documentation/FAQ_peoples_dark.jpg "Logo Title Text 1")

![alt text](https://github.com/maxwolfs/crude-data/blob/master/documentation/CD_hst_segmentdetail.jpg "Logo Title Text 1")

![alt text](https://github.com/maxwolfs/crude-data/blob/master/documentation/CD_hst_board.jpg "Logo Title Text 1")
