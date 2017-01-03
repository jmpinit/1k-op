EESchema Schematic File Version 2
LIBS:power
LIBS:device
LIBS:transistors
LIBS:conn
LIBS:linear
LIBS:regul
LIBS:74xx
LIBS:cmos4000
LIBS:adc-dac
LIBS:memory
LIBS:xilinx
LIBS:microcontrollers
LIBS:dsp
LIBS:microchip
LIBS:analog_switches
LIBS:motorola
LIBS:texas
LIBS:intel
LIBS:audio
LIBS:interface
LIBS:digital-audio
LIBS:philips
LIBS:display
LIBS:cypress
LIBS:siliconi
LIBS:opto
LIBS:atmel
LIBS:contrib
LIBS:valves
EELAYER 25 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L 24LC32 U1
U 1 1 586AEC58
P 5550 3600
F 0 "U1" H 5300 3850 50  0000 C CNN
F 1 "24LC32" H 5750 3850 50  0001 C CNN
F 2 "SMD_Packages:SOIC-8-N" H 5600 3350 50  0001 L CNN
F 3 "" H 5550 3500 50  0000 C CNN
	1    5550 3600
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR01
U 1 1 586AECA2
P 5100 3950
F 0 "#PWR01" H 5100 3700 50  0001 C CNN
F 1 "GND" H 5100 3800 50  0000 C CNN
F 2 "" H 5100 3950 50  0000 C CNN
F 3 "" H 5100 3950 50  0000 C CNN
	1    5100 3950
	1    0    0    -1  
$EndComp
Wire Wire Line
	5150 3500 5100 3500
Wire Wire Line
	5100 3500 5100 3950
Wire Wire Line
	5150 3600 5100 3600
Connection ~ 5100 3600
Wire Wire Line
	5150 3700 5100 3700
Connection ~ 5100 3700
Wire Wire Line
	5100 3900 6150 3900
Connection ~ 5100 3900
$Comp
L +5V #PWR02
U 1 1 586AECF9
P 5550 3250
F 0 "#PWR02" H 5550 3100 50  0001 C CNN
F 1 "+5V" H 5550 3390 50  0000 C CNN
F 2 "" H 5550 3250 50  0000 C CNN
F 3 "" H 5550 3250 50  0000 C CNN
	1    5550 3250
	1    0    0    -1  
$EndComp
Wire Wire Line
	5550 3250 5550 3300
Wire Wire Line
	5950 3700 6000 3700
Wire Wire Line
	6000 3700 6000 3900
Connection ~ 5550 3900
$Comp
L CONN_01X04 P1
U 1 1 586AED2B
P 6450 3450
F 0 "P1" H 6450 3700 50  0000 C CNN
F 1 "CONN_01X04" V 6550 3450 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x04" H 6450 3450 50  0001 C CNN
F 3 "" H 6450 3450 50  0000 C CNN
	1    6450 3450
	1    0    0    -1  
$EndComp
Wire Wire Line
	6250 3500 5950 3500
Wire Wire Line
	5950 3600 6250 3600
Wire Wire Line
	5550 3300 6250 3300
Wire Wire Line
	6250 3400 6150 3400
Wire Wire Line
	6150 3400 6150 3900
Connection ~ 6000 3900
$EndSCHEMATC
