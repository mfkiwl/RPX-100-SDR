<h1>ADS-B demodulator plugin</h1>

<h2>Introduction</h2>

The ADS-B demodulator plugin can be used to receive and display ADS-B aircraft information. This is information about an aircraft, such as position, altitude, heading and speed, broadcast by aircraft on 1090MHz, in the 1090ES (Extended Squitter) format. 1090ES frames have a chip rate of 2Mchip/s, so the baseband sample rate should be set to be greater than 2MSa/s.

<h2>Interface</h2>

![ADS-B Demodulator plugin GUI](../../../doc/img/ADSBDemod_plugin.png)

<h3>1: Frequency shift from center frequency of reception value</h3>

Use the wheels to adjust the frequency shift in Hz from the center frequency of reception. Right click on a digit sets all digits on the right to zero. This effectively floors value at the digit position. Wheels are moved with the mousewheel while pointing at the wheel or by selecting the wheel with the left mouse click and using the keyboard arrows. Pressing shift simultaneously moves digit by 5 and pressing control moves it by 2. Left click on a digit sets the cursor position at this digit.

<h3>2: Channel power</h3>

Average total power in dB relative to a +/- 1.0 amplitude signal received in the pass band.

<h3>3: Level meter in dB</h3>

  - top bar (green): average value
  - bottom bar (blue green): instantaneous peak value
  - tip vertical bar (bright green): peak hold value

<h3>4: RF bandwidth</h3>

This is the bandwidth in MHz of the channel signal before demodulation.

<h3>5: SR - Channel Sample Rate</h3>

This specifies the channel sample rate the demodulator uses. Values of 2M-12MSa/s are supported, 2MSa/s steps. Ideally, this should be set to the same value as the baseband sample rate (the sample rate received from the radio). If it is different from the baseband sample rate, interpolation or decimation will be performed as needed to match the rates. However, interpolation currently requires a significant amount of processing power and may result in dropped samples.

2 MSa/s should give decent decodes. Higher rates may be experienced with if your hardware allows it (radio device and processing power). However the higher the rate the more processing power required.

Higher channel sample rates may help decode more frames, but will require more processing power.

<h3>6: S - Demodulate all Mode-S frames</h3>

Checking the S button will enable demodulation of all Mode-S frames, not just ADS-B. Mode-S frames will not effect the data displayed in the table or map, but can be feed to aggregators.

<h3>7: FP - Correlate Against Full Preamable</h3>

When the FP button is checked, the demodulator will correlated the received signal against all expected 8 bits of the ES1090 preamble. When unchecked, the correlation will only be against the first 6 bits. Only correlating the first 6 bits can reduce the processing requirements, but may result in more invalid frames.

<h3>8: Threshold</h3>

This sets the correlation threshold in dB between the received signal and expected 1090ES preamble, that is required to be exceeded before the demodulator will try to decode a frame. Lower values should decode more frames amd will require more processing power, but will more often decode invalid frames. You may also look at correlation values obtained with reliable signals in the "Correlation" column of the data table.

<h3>9: Download Opensky-Network Aircraft Database</h3>

Clicking this will download the Opensky-Network (https://opensky-network.org/) aircraft database. This database contains information about aircrafts, such as registration, aircraft model and owner details, that is not broadcast via ADS-B. Once downloaded, this additional information will be displayed in the table alongside the ADS-B data. The database should only need to be downloaded once, as it is saved to disk, and it is recommended to download it before enabling the demodulator.

<h3>10: Download OurAirports Airport Databases</h3>

Clicking this will download the OurAirports (https://ourairports.com/) airport databases. These contains names and locations for airports allowing them to be drawn on the map, as well as their corresponding ATC frequencies, which can also be displayed next to the airport on the map, by clicking the airport name. The size of airports that will be displayed on the map, and whether heliports are displayed, can be set in the Display Settings dialog.

<h3>11: Display Settings</h3>

Clicking the Display Settings button will open the Display Settings dialog, which allows you to choose:

* The units for altitude, speed and vertical climb rate. These can be either ft (feet), kn (knots) and ft/min (feet per minute), or m (metres), kph (kilometers per hour) and m/s (metres per second).
* The minimum size airport that will be displayed on the map: small, medium or large. Use small to display GA airfields, medium for regional airports and large for international airports.
* Whether or not to display heliports.
* The distance (in kilometres), from the location set under Preferences > My Position, at which airports will be displayed on the map.
* The timeout, in seconds, after which an aircraft will be removed from the table and map, if an ADS-B frame has not been received from it.
* The font used for the table.
* Whether demodulator statistics are displayed (primarily an option for developers).
* Whether the columns in the table are automatically resized after an aircraft is added to it. If unchecked, columns can be resized manually and should be saved with presets.

<h3>12: Display Flight Paths</h3>

Checking this button draws a line on the map showing aircraft's flight paths, as determined from received ADS-B frames.

<h3>13: Feed</h3>

Checking Feed enables feeding received ADS-B frames to aggregators such as ADS-B Exchange: https://www.adsbexchange.com or ADSBHub
: https://www.adsbhub.org. Right clicking on the Feed button opens the Feed Settings dialog.

The server hostname and port to send the frames to should be entered in the Server and Port fields, with the appropriate format selected:

* For ADS-B Exchange, set Server hostname to feed.adsbexchange.com, Port to 30005 and Format to Beast binary. You can check for successful feeding (after about 30 seconds) at: https://www.adsbexchange.com/myip/
* For ADSBHub, set Server hostname to data.adsbhub.org, Port to 5002 and Format to Beast hex. You will need to have setup an account on ADSBHub first. You can check for successful feeding at: https://www.adsbhub.org/statistic.php

The Beast binary and Hex formats are as detailed here: https://wiki.jetvision.de/wiki/Mode-S_Beast:Data_Output_Formats

<h3>14: Refresh list of devices</h3>

Use this button to refresh the list of devices.

<h3>15: Select device set</h3>

Specify the SDRangel device set that will be have its centre frequency set when an airport ATC frequency is clicked on the map. Typically, this device set would be a second SDR (as ATC frequencies are around 120MHz, so they can not be received simultaneously with 1090MHz for ADS-B) and have an AM Demodulator channel plugin.

<h3>ADS-B Data</h3>

The table displays the decoded ADS-B data for each aircraft along side data available for the aircraft from the Opensky Network database. The data is not all able to be transmitted in a single ADS-B frame, so the table displays an amalgamation of the latest received data of each type.

![ADS-B Demodulator Data](../../../doc/img/ADSBDemod_plugin_table.png)

* ICAO ID - 24-bit hexidecimal ICAO aircraft address. This is unique for each aircraft. (ADS-B)
* Flight No. - Airline flight number or callsign. (ADS-B)
* Aircraft - The aircraft model. (DB)
* Airline - The logo of the operator of the aircraft (or owner if no operator known). (DB)
* Altitude (Alt) - Altitude in feet or metres. (ADS-B)
* Speed (Spd) - Speed (either ground speed, indicated airspeed, or true airspeed) in knots or kph. (ADS-B)
* Heading (Hd) - The direction the aircraft is heading, in degrees. (ADS-B)
* Vertical rate (VR) - The vertical climb rate (or descent rate if negative) in feet/minute or m/s. (ADS-B)
* Distance (D) - The distance to the aircraft from the receiving antenna in kilometres. The location of the receiving antenna is set under the Preferences > My Position menu.
* Az/El - The azimuth and elevation angles to the aircraft from the receiving antenna in degrees. These values can be sent to a rotator controller Feature plugin to track the aircraft.
* Latitude (Lat) - Vertical position coordinate, in decimal degrees. (ADS-B)
* Longitude (Lon) - Horizontal position coordinate, in decimal degrees. (ADS-B)
* Category (Cat) - The vehicle category, such as Light, Large, Heavy or Rotorcraft. (ADS-B)
* Status - The status of the flight, including if there is an emergency. (ADS-B)
* Squawk - The squawk code (Mode-A transponder code). (ADS-B)
* Registration (Reg) - The registration number of the aircraft. (DB)
* Country - The flag of the country the aircraft is registered in. (DB)
* Registered - The date when the aircraft was registered. (DB)
* Manufacturer - The manufacturer of the aircraft. (DB)
* Owner - The owner of the aircraft. (DB)
* Updated - The local time at which the last ADS-B message was received.
* RX Frames - A count of the number of ADS-B frames received from this aircraft.
* Correlation - Displays the minimun, average and maximum of the preamable correlation in dB for each recevied frame. These values can be used to help select a threshold setting. This correlation value is the ratio between the presence and absence of the signal corresponding to the "ones" and the "zeros" of the sync word adjusted by the bits ratio. It can be interpreted as a SNR estimation.
* RSSI - This Received Signal Strength Indicator is based on the signal power during correlation estimation. This is the power sum during the expected presence of the signal i.e. the "ones" of the sync word.

If an ADS-B frame has not been received from an aircraft for 60 seconds, the aircraft is removed from the table and map. This timeout can be adjusted in the Display Settings dialog.

* Single clicking in a cell will highlight the row and the corresponding aircraft information box on the map will be coloured orange, rather than blue.
* Right clicking on the header will open a menu allowing you to select which columns are visible.
* To reorder the columns, left click and drag left or right a column header.
* Left click on a header to sort the table by the data in that column.
* Double clicking in an ICAO ID cell will open a Web browser and search for the corresponding aircraft on https://www.planespotters.net/
* Double clicking in an Flight No cell will open a Web browser and search for the corresponding flight on https://www.flightradar24.com/
* Double clicking in an Az/El cell will set the aircraft as the active target. The azimuth and elevation to the aicraft will be sent to a rotator controller plugin. The aircraft information box will be coloured green, rather than blue, on the map.
* Double clicking on any other cell in the table will centre the map on the corresponding aircraft.

<h2>Map</h2>

The map displays aircraft locations and data geographically.

![ADS-B Demodulator Map](../../../doc/img/ADSBDemod_plugin_map.png)

The initial antenna location is placed according to My Position set under the Preferences > My Position menu. The position is only updated when the ADS-B demodulator plugin is first opened.

Aircraft are only placed upon the map when a position can be calculated, which can require several frames to be received.

* To pan around the map, click the left mouse button and drag. To zoom in or out, use the mouse scroll wheel.
* Left clicking on an aicraft will highlight the corresponding row in the table for the aircraft and the information box on the map will be coloured orange, rather than blue.
* Double clicking on an aircraft will set it as the active target and the information box will be coloured green.
* Left clicking the information box next to an aircraft will reveal more information. It can be closed by clicking it again.
* Left clicking the information box next to an airport will reveal ATC frequencies for the airport (if the OurAirports database has been downloaded.). This information box can be closed by left clicking on the airport identifier. Double clicking on one of the listed frequencies, will set it as the centre frequency on the selected SDRangel device set (15). The Az/El row gives the azimuth and elevation of the airport from the location set under Preferences > My Position. Double clicking on this row will set the airport as the active target.

<h2>Attribution</h2>

Airline logos and flags are by Steve Hibberd from https://radarspotting.com

Map icons are by Alice Design, Alex Ahineev, Botho Willer, Verry Obito, Sean Maldjia, Tinashe Mugayi, Georgiana Ionescu, Andreas Vögele, Tom Fricker, Will Sullivan, Tim Tores, BGBOXXX Design, and Angriawan Ditya Zulkarnain from the Noun Project https://thenounproject.com/
