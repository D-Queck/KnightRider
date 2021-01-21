/*
 Name:		LEDmotion.ino
 Created:	21.01.2021 10:12:26
 Author:	queck
*/

const int hell = 1; //Zustand: LED heller werden
const int dunkel = 2; //Zustand: LED dunkler werden
int zustandDimmen = hell; //aktueller Zustand dimmen

const int vorwaerts = 1; //Zustand: LEDs dimmen vorwärts
const int rueckwaerts = 2; //Zustand: LEDs dimmen rückwärts
int zustandRichtung = vorwaerts; //aktueller Zustand Richtung

const int pwmValueMax = 255; //Max-wert PWM
const int pwmValueMin = 0; //Min-wert PWM
const int pwmValueStep = 15; //Zu-/Ab-nahme des PWM-wertes

int pwmValue = 0; //Speicherung des PWMvalues

int leds[] = { 11, 10, 9, 6, 5 }; //Array beinhaltet PWM-Pins
int index = 0; //index Pin-Array
int anzahlLeds = sizeof(leds); //Anzahl LEDs

void setup()
{
	//pinMode wird initialisiert
	for (int i = 0; i < anzahlLeds; i++)
	{
		pinMode(leds[i], OUTPUT);
	}
}

//Methode zum Dimmen der LEDs
void ledDimmer()
{
	if (zustandDimmen == hell)
	{
		pwmValue += pwmValueStep;

		if (pwmValue == pwmValueMax)
		{
			zustandDimmen = dunkel;
			pwmValue = pwmValueMax;
		}
	}
	else if (zustandDimmen == dunkel)
	{
		pwmValue -= pwmValueStep;

		if (pwmValue == pwmValueMin)
		{
			zustandDimmen = hell;
			pwmValue = pwmValueMin;
		}
	}
	analogWrite(leds[index], pwmValue);
	delay(45);
}

//nächster Wert im Index -> Pin-Array
void indexNext()
{
	if (pwmValue == pwmValueMin)
	{
		index++;
	}
}

//Ein Wert zurück im Index -> Pin-Array
void indexBack()
{
	if (pwmValue == pwmValueMin)
	{
		index--;
	}
}

//Richtungsechsel LED
void richtungLed()
{
	if (zustandRichtung == vorwaerts)
	{
		if (index < 4)
		{
			indexNext();
		}
		else
		{
			zustandRichtung = rueckwaerts;
		}
	}

	if (zustandRichtung == rueckwaerts)
	{
		if (index > 0)
		{
			indexBack();
		}
		else
		{
			zustandRichtung = vorwaerts;
		}
	}
}

void loop()
{
	switch (index)
	{
	case 0:
		ledDimmer();
		richtungLed();
		break;

	case 1:
		ledDimmer();
		richtungLed();
		break;

	case 2:
		ledDimmer();
		richtungLed();
		break;

	case 3:
		ledDimmer();
		richtungLed();
		break;

	case 4:
		ledDimmer();
		richtungLed();
		break;
	}
}
