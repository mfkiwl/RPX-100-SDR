<h1>Local sink channel plugin</h1>

<h2>Introduction</h2>

This plugin sends I/Q samples from the baseband to a Local Input plugin source in another device set. It is basically the same as the Remote Sink channel plugin but pipes the samples internally instead of sending them over the network.

It may be used when you want to "zoom in" a particular area of the baseband. For example you would like to receive both the SSB section and the repeater section of the amateur 2m band (Region 1) using a single Rx device for example the RTL-SDR. You would then run the RTL-SDR at 2.4 MS/s without decimation. This provides a 2.4 MHz bandwidth that when centered on 145 MHz spans more than the entire 2m band (Region 1).

You can then use a Local Sink decimating by 8 and centered on 144.250 MHz (Position code 2, filter chain code LLH) thus spanning 300 kHz from 144.150 to 144.400 MHz. You can use another Local Sink decimating by 4 and centered on 145.600 MHz (Position code 7, filter chain code HC) thus spanning 600 kHz from 145.300 to 145.900 MHz and including the entire repeater band.

These Local Sinks can then be coupled with two Local Input device source plugins in two different device sets. In these device sets you will get a better view of the respective sub bands.

Note that because it uses only the channelizer half band filter chain to achieve decimation and center frequency shift you have a limited choice on the center frequencies that may be used (similarly to the Remote Sink). The available center frequencies depend on the baseband sample rate, the channel decimation and the filter chain that is used so you have to play with these parameters to obtain a suitable center frequency and pass band.

<b>&#9888; Important warning</b> When closing the application or before closing the local input device the local sink is connected to you have to stop the device where the local sink operates. This is because there is no reverse link for the local input to notify the local sink that it closes. Therefore closing the local input while the local sink runs will crash the program.

<h2>Interface</h2>

![Local sink channel plugin GUI](../../../doc/img/LocalSink.png)

<h3>1: Decimation factor</h3>

The device baseband can be decimated in the channel and its center can be selected with (5). The resulting sample rate of the I/Q stream sent over the network is the baseband sample rate divided by this value. The value is displayed in (2).

<h3>2: I/Q stream sample rate</h3>

This is the sample rate in kS/s of the I/Q stream sent to the Local Input source instance.

<h3>3: Half-band filters chain sequence</h3>

This string represents the sequence of half-band filters used in the decimation from device baseband to resulting I/Q stream. Each character represents a filter type:

  - **L**: lower half-band
  - **H**: higher half-band
  - **C**: centered

<h3>4: Center frequency shift</h3>

This is the shift of the channel center frequency from the device center frequency. Its value is driven by the device sample rate , the decimation (1) and the filter chain sequence (5).

<h3>5: Half-band filter chain sequence</h3>

The slider moves the channel center frequency roughly from the lower to the higher frequency in the device baseband. The number on the right represents the filter sequence as the decimal value of a base 3 number. Each base 3 digit represents the filter type and its sequence from MSB to LSB in the filter chain:

  - **0**: lower half-band
  - **1**: centered
  - **2**: higher half-band

<h3>6: Local Input source index</h2>

This selects the index of the Local Input source where to send the I/Q samples. The list can be refreshed with the next button (7)

<h3>7: Refresh local input devices list</h2>

Use this button to refresh the list of Local Input sources indexes.
