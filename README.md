# Crude Data

* Maximilian Wolfs (c) 2017 - 2018
* mwolfs@hfk-bremen.de

![alt text](https://github.com/maxwolfs/crude-data/blob/master/documentation/CD_hst_totale.jpg "Logo Title Text 1")

#### Introduction

CRUDE DATA translates the virtual real time value of one barrel of crude oil (Brent) in USD as traded in the ICE Future Market in London into an electromechanical 7-segment display. The portly IoT-Machine emphasizes the difference of the material and the abstracted derivative acting as an encoder of the pulse of the global economic machine.

#### Conceptual Background

Crude Oil is if not the most important resource of our planet. Its whereabouts and especially its price determines about war and peace, wealth and poverty. Oil is not only the fuel of the world economy but also the core of an enormous amount of industrial products. But there is big gap in our western society between the actual raw liquid and its virtual value. Most of us have never experienced oil aesthetically with our senses. It only exists in the most artificial abstracted and rational way, as data, changing in real-time and traded by machines.

The barrel as a trading size is due to the unimaginable volume of trade in millions of liters today only a historic leftover. Similarly, the Brent sort exists only as a historical reference on the stock market. While the field in the British North Sea with its four production platforms was of immense economic and geopolitical importance for the independence of Europe’s oil supply in the 1970s, today’s platforms are only expensive and environmentally problematic depreciations for the oil companies. The contrast of temporality is just as astounding: Within billions of years, organisms have emerged under high pressure, burned and processed within decades, and traded in milliseconds.

#### Technical Background

The work consists of four electromechanical 7-segment displays. Each of them consists of seven gear motors which are able to flap 90° to form a pattern with 128 possibilites. Ten of these possible patterns translate as the arabic numbers ranging from 0 – 10. On top of each flap are Leds, which not connected to the logic of the motors and are either all on or off. This makes the steel frame necessary to hide the noise of light emission of the inactive segments. This strange design decision itself goes back to their former use in a gas station in Berlin Köpenick.

In a techno-archaeological investigation, the disused and with spider-nests attached machines were examined. First, the components were identified and their connections on the board traced on a large scale drawing, in order to develope a custom program. Through an open programming interface, it was possible to override the old & inaccessible program code on the old board and thus bring the displays back to a second life. In a further step, another module was developed, consisting of a microcontroller with WiFi connection, which queries via Web API the latest value and sends it via a serial interface to the individual modules to display the latest traded value.

A kinetic light installation, originally built to show car and truck drivers the current petrol prices from a far distance, now decontextualized as an absurd machine. It is driven by the pulse of the global data-driven commodity trading and transforms in rhythmic movements making this unimaginable yet geopolitically significant value to be experienced aesthetically.

#### Exhibitions

* 9.2. - 10.2.2018 at HFK Bremen: Hochschultage 2018
* 27.2.2017 at FAQ Bremen: RTFM: The Technological Sublime

[![Crude Data at FAQ](https://i.imgur.com/Y2USpJY.png)](https://vimeo.com/247011682 "Crude Data at FAQ")

![alt text](https://github.com/maxwolfs/crude-data/blob/master/documentation/CD_hst_totale_ghost.jpg "Logo Title Text 1")

![alt text](https://github.com/maxwolfs/crude-data/blob/master/documentation/FAQ_Halbtotale_1_Dunkel_2.jpg "Logo Title Text 1")

![alt text](https://github.com/maxwolfs/crude-data/blob/master/documentation/FAQ_peoples_dark.jpg "Logo Title Text 1")

![alt text](https://github.com/maxwolfs/crude-data/blob/master/documentation/CD_hst_segmentdetail.jpg "Logo Title Text 1")

![alt text](https://github.com/maxwolfs/crude-data/blob/master/documentation/CD_hst_board.jpg "Logo Title Text 1")
