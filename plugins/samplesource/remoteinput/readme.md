<h1>Remote input plugin</h1>

<h2>Introduction</h2>

This input sample source plugin gets its samples over tbe network from a RPX100 instance's Remote channel sink using UDP connection.

Forward Error Correction with a Cauchy MDS block erasure codec is used to prevent block loss. This can make the UDP transmission more robust particularly over WiFi links.

Please note that there is no provision for handling out of sync UDP blocks. It is assumed that frames and block numbers always increase with possible blocks missing. Such out of sync situation has never been encountered in practice.

The remote RPX100 instance that sends the data stream is controlled via its REST API using a separate control software for example [RPX100cli](https://github.com/f4exb/RPX100cli)

A sample size conversion takes place if the stream sample size sent by the remote instance and the Rx sample size of the local instance do not match (i.e. 16 to 24 bits or 24 to 16 bits). Best performace is obtained when both instances use the same sample size.

It is present only in Linux binary releases.

<h2>Build</h2>

The plugin will be built only if the [CM256cc library](https://github.com/f4exb/cm256cc) is installed in your system. For CM256cc library you will have to specify the include and library paths on the cmake command line. Say if you install cm256cc in `/opt/install/cm256cc` you will have to add `-DCM256CC_DIR=/opt/install/cm256cc` to the cmake commands.

<h2>Interface</h2>

![SDR Remote input plugin GUI](../../../doc/img/RemoteInput_plugin.png)

<h3>1: Start/Stop</h3>

Device start / stop button.

  - Blue triangle icon: device is ready and can be started
  - Green square icon: device is running and can be stopped

<h3>2: Frequency</h3>

This is the center frequency in Hz sent in the meta data from the remote RPX100 instance and corresponds to the center frequency of reception. The sub kHz value (000 to 999 Hz) is represented in smaller digits on the right.

<h3>3: Stream sample rate</h3>

Stream I/Q sample rate in kS/s

<h3>4: Auto correction options and stream status</h3>

![SDR Remote input stream GUI](../../../doc/img/RemoteInput_plugin_02.png)

<h4>4.1: Auto correction options</h4>

These buttons control the local DSP auto correction options:

  - **DC**: auto remove DC component
  - **IQ**: auto make I/Q balance

<h4>4.2: Receive buffer length</h4>

This is the main buffer (writes from UDP / reads from DSP engine) length in units of time (seconds). As read and write pointers are normally about half the buffer apart the nominal delay introduced by the buffer is the half of this value.

<h4>4.3: Main buffer R/W pointers positions</h4>

Read and write pointers should always be a half buffer distance buffer apart. This is the difference in percent of the main buffer size from this ideal position.

  - When positive it means that the read pointer is leading
  - When negative it means that the write pointer is leading (read is lagging)

This corresponds to the value shown in the gauges above (9)

<h4>4.4: Date/time</h4>

This is the current timestamp of the block of data sent from the receiver. It is refreshed about every second. The plugin tries to take into account the buffer that is used between the data received from the network and the data effectively used by the system however this may not be extremely accurate. It is based on the timestamps sent from the Remote sink channel at the other hand that does not take into account its own buffers.

<h3>5: Main buffer R/W pointers gauge</h3>

There are two gauges separated by a dot in the center. Ideally these gauges should not display any value thus read and write pointers are always half a buffer apart. However due to the fact that a whole frame is reconstructed at once up to ~10% variation is normal and should appear on the left gauge (write leads).

  - The left gauge is the negative gauge. It is the value in percent of buffer size from the write pointer position to the read pointer position when this difference is less than half of a buffer distance. It means that the writes are leading or reads are lagging.
  - The right gauge is the positive gauge. It is the value in percent of buffer size of the difference from the read pointer position to the write pointer position when this difference is less than half of a buffer distance. It menas that the writes are lagging or reads are leading.

The system tries to compensate read / write unbalance however at start or when a large stream disruption has occurred a delay of a few tens of seconds is necessary before read / write reaches equilibrium.

<h3>6: Data stream status</h3>

![SDR Remote input stream GUI](../../../doc/img/RemoteInput_plugin_04.png)

<h4>6.1: Sample size</h4>

This is the size in bits of a I or Q sample sent in the stream by the remote server.

<h4>6.2: Total number of frames and number of FEC blocks</h4>

This is the total number of frames and number of FEC blocks separated by a slash '/' as sent in the meta data block thus acknowledged by the remote server. When you set the number of FEC blocks with (4.1) the effect may not be immediate and this information can be used to monitor when it gets effectively set in the remote server.

A frame consists of 128 data blocks (1 meta data block followed by 127 I/Q data blocks) and a variable number of FEC blocks used to protect the UDP transmission with a Cauchy MDS block erasure correction.

Using the Cauchy MDS block erasure correction ensures that if at least the number of data blocks (128) is received per complete frame then all lost blocks in any position can be restored. For example if 8 FEC blocks are used then 136 blocks are transmitted per frame. If only 130 blocks (128 or greater) are received then data can be recovered. If only 127 blocks (or less) are received then none of the lost blocks can be recovered.

<h4>6.3: Stream status</h4>

The color of the icon indicates stream status:

  - Green: all original blocks have been received for all frames during the last polling timeframe (ex: 136)
  - No color: some original blocks were reconstructed from FEC blocks for some frames during the last polling timeframe (ex: between 128 and 135)
  - Red: some original blocks were definitely lost for some frames during the last polling timeframe (ex: less than 128)

<h4>6.4: Minimum total number of blocks per frame</h4>

This is the minimum total number of blocks per frame during the last polling period. If all blocks were received for all frames then this number is the nominal number of original blocks plus FEC blocks (Green lock icon). In our example this is 128+8 = 136.

If this number falls below 128 then some blocks are definitely lost and the lock lights in red.

<h4>6.5: Maximum number of FEC blocks used by frame</h4>

Maximum number of FEC blocks used for original blocks recovery during the last polling timeframe. Ideally this should be 0 when no blocks are lost but the system is able to correct lost blocks up to the nominal number of FEC blocks (Neutral lock icon).

<h4>6.6: Reset events counters</h4>

This push button can be used to reset the events counters (4.7 and 4.8) and reset the event counts timer (4.9)

<h4>6.7: Unrecoverable error events counter</h4>

This counter counts the unrecoverable error conditions found (i.e. 4.4 lower than 128) since the last counters reset.

<h4>6.8: Recoverable error events counter</h4>

This counter counts the unrecoverable error conditions found (i.e. 4.4 between 128 and 128 plus the number of FEC blocks) since the last counters reset.

<h4>6.9: events counters timer</h4>

This HH:mm:ss time display shows the time since the reset events counters button (4.6) was pushed.

<h3>7: Remote server test</h3>

Test remote connection with its API.

![SDR Remote input stream GUI](../../../doc/img/RemoteInput_plugin_05.png)

<h4>7.1: Remote connection indicator</h4>

The "Remote" label is lit in green when the connection is successful

<h4>7.2: API IP address</h4>

IP address of the remote RPX100 instance REST API

<h4>7.3: API port</h4>

Port of the remote RPX100 instance REST API

<h4>7.4: Get information button</h4>

When the return key is hit within the address (5.2) or port (5.3) the changes are effective immediately. You can also use this button to set again these values. Clicking on this button will send a request to the API to get the remote RPX100 instance information that is displayed in the API message box (8)

<h3>8: Local network interface address and port for data reception</h3>

![SDR Remote source input stream GUI](../../../doc/img/RemoteInput_plugin_06.png)

<h4>8.1: Interface IP address</h4>

IP address of the local network interface the remote RPX100 instance sends the data to. Effective when the validation button (8.3) is pressed.

<h4>8.2: Interface port</h4>

Local port the remote RPX100 instance sends the data to.  Effective when the validation button (8.3) is pressed.

<h4>8.3: Validation button</h4>

When the return key is hit within the interface address (8.2), port (8.3), multicast group address (10) and multicast group join/leave (9) the changes of parameters for data reception are ready for commit and this button turns green. You then push this button to commt the changes.

<h3>9: Join or leave multicast group</h3>

Use this toggle button to join or leave the multicast group which address is specified next (10). Effective when the validation button (8.3) is pressed.

<h3>10: Multicast group address</h3>

This is the address of the multicast group. Effective when the validation button (8.3) is pressed.

<h3>11: Status message</h3>

The API status is displayed in this box. It shows "API OK" when the connection is successful and reply is OK

<h3>12: Remote information</h3>

This is the information returned by the remote when connection with its API is successful
