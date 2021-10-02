<h1>SoapySDR input plugin</h1>

<h2>Introduction</h2>

This input sample source plugin gets its samples from a device interfaced with [SoapySDR](https://github.com/pothosware/SoapySDR/wiki).

SoapySDR is a [C/C++ API](https://github.com/pothosware/SoapySDR/blob/master/include/SoapySDR/Device.hpp) that interfaces SDR hardware on one side and application software on the other. Due to its very generic nature it was fairly difficult to implement and specific UI widgets were developed to handle specific types of parameters. The level of control depends on how the device API was implemented by the vendors. On application side some parts of the API have not been implemented and can be left as possible enhancements (see next). In any case it is recommended to use the native plugins if they are available.

SoapySDR devices appear in the list of available devices in the order they are listed in the API call to SoapySDR. If more than one device controlled by SoapySDR is listed then its sequence number is incremented like:

  - SoapySDR[0:0] rtlsdr: Generic RTL...
  - SoapySDR[1:0] rtlsdr: Generic RTL...

The SoapySDR driver name appears right before the column

If the same device exposes several channels they appear as distinct devices with the channel number incremented like:

  - SoapySDR[1:0] lime: LimeSDR...
  - SoapySDR[1:1] lime: LimeSDR...

This works similarly to LimeSDR USB or BladeRF 2.0 micro

<h2>Binary distributions</h2>

The binary distributions provide only the SoapySDR base library. It is your responsibility to install SoapySDR in your system with the SoapySDR plugins suitable for your hardware.

<h2>User arguments</h2>

Occasionally some devices may require to have the user specifying keyword parameters in order to open the device correctly. Most noticeably the Red Pitaya (driver `redpitaya`) needs the IP address of the board specified as a `addr=x.x.x.x` key value pair as it does not get scanned automatically.

In such a case you will use the device user arguments (Preferences -> Devices -> User arguments) with the dialog as described [here](../../../sdrgui/deviceuserargs.md)

<h2>SoapySDR API implementation</h2>

Not all parts are implemented. Currently the following have been left out:

  - Frequency API tuning arguments. The tuning elements are of course supported.
  - Clocking API
  - Time API
  - Sensor API
  - Register API
  - GPIO API
  - I2C API
  - SPI API
  - UART API

<h2>Particular considerations concerning hardware</h2>

In general as previously stated you should choose the native plugins if they are available. These are:

  - Airspy
  - AirspyHF
  - BladeRF
  - HackRF
  - LimeSDR
  - PlutoSDR
  - RTLSDR
  - SDRplay RSP1

The following paragraphs list the known issues or oddities.

<h3>BladeRF</h3>

It is very important NOT to use SoapySDR. The default parameters are set to flash the FPGA but as this does not succeeds it results in a FPGA image wipe out and the device returns in "Cypress" mode. It is not too difficult to recover but there is no point risking the hassle.

<h3>SDRplay RSP2</h3>

Do not use sample rates lower than 2 MS/s

<h3>Red Pitaya</h3>

When installed the Red Pitaya SoapySDR plugin lists a Red Pitaya device even if there is no Red Pitaya attached. Trying to select and start it when there is no Red Pitaya will result in program crash.

<h2>Interface</h2>

![SoapySDR input plugin GUI](../../../doc/img/SoapySDRInput_plugin1.png)

The top part described by number tags is common for all devices. The bottom part under the "A" tag depends on the SoapySDR device implementation. The corresponding widgets are stacked vertically inside a scrollable area as there may be many controls depending on how the device interface is implemented in SoapySDR. Move the slider on the right to see all parameters available.

<h3>1: Common stream parameters</h3>

![Remote source input stream GUI](../../../doc/img/RemoteInput_plugin_01.png)

<h4>1.1: Frequency</h4>

This is the center frequency of reception in kHz. The center frequency is usually the same for all Rx channels. The GUI of the sibling channel if present is adjusted automatically if necessary. This control corresponds to the first SoapySDR tuning element usually labeled as "RF" and would generally control the main local oscillator (LO).

Use the wheels to adjust the value. Left click on a digit sets the cursor position at this digit. Right click on a digit sets all digits on the right to zero. This effectively floors value at the digit position. Wheels are moved with the mousewheel while pointing at the wheel or by selecting the wheel with the left mouse click and using the keyboard arrows. Pressing shift simultaneously moves digit by 5 and pressing control moves it by 2.

<h4>1.2: Start/Stop</h4>

Device start / stop button.

  - Blue triangle icon: device is ready and can be started
  - Green square icon: device is running and can be stopped
  - Magenta (or pink) square icon: an error occurred. In the case the device was accidentally disconnected you may click on the icon, plug back in and start again. Check the console log for possible errors.

<h4>1.4: Stream sample rate</h4>

Baseband I/Q sample rate in kS/s. This is the device sample rate (the "SR" SoapySDR control) divided by the decimation factor (4).

<h3>2: Software auto correction options</h3>

These buttons control the RPX100 internal DSP auto correction options:

  - **DC**: auto remove DC component
  - **IQ**: auto make I/Q balance. The DC correction must be enabled for this to be effective.

<h3>3: Baseband center frequency position relative the LO center frequency</h3>

Possible values are:

  - **Cen**: the decimation operation takes place around the LO frequency Fs
  - **Inf**: the decimation operation takes place around Fs - Fc.
  - **Sup**: the decimation operation takes place around Fs + Fc.

With SR as the sample rate before decimation Fc is calculated as:

  - if decimation n is 4 or lower:  Fc = SR/2^(log2(n)-1). The device center frequency is on the side of the baseband. You need a RF filter bandwidth at least twice the baseband.
  - if decimation n is 8 or higher: Fc = SR/n. The device center frequency is half the baseband away from the side of the baseband. You need a RF filter bandwidth at least 3 times the baseband.

<h3>4: Decimation factor</h3>

The I/Q stream from the SoapySDR I/Q stream is downsampled by a power of two before being sent to the passband. Possible values are increasing powers of two: 1 (no decimation), 2, 4, 8, 16, 32, 64.

<h3>5: Transverter mode open dialog</h3>

This button opens a dialog to set the transverter mode frequency translation options. The details about this dialog can be found [here](../../../sdrgui/gui/transverterdialog.md)

<h3>6: Software LO ppm correction</h3>

Use this slider to adjust RPX100 internal LO correction in ppm. It can be varied from -100.0 to 100.0 in 0.1 steps and is applied in software when calculating the frequency at which the LO should be set.

<h2>A: SoapySDR variable interface</h2>

The form of widgets is closely related to the type of setting defined in the [SoapySDR interface](https://github.com/pothosware/SoapySDR/blob/master/include/SoapySDR/Types.hpp). These are:

  - Ranges
    - Continuous range when maximum and minimum are different
    - Discrete value when maximum and minimum are equal. Usually this appears in a range list to define a set of values
  - List of ranges: more than one range applies to the same setting
  - Arguments defined by
    - type: boolean, integer, floating point, string
    - nature: continuous or discrete
  - String list

<h3>A.1: Continuous range</h3>

If the range is all in the positive domain the unsigned variation is used:

![SoapySDR input plugin GUI](../../../doc/img/SoapySDR_range_pos.png)

Note that the same widget is used for single ranges and ranges list. In this case the range selection combo on the right is disabled. The manipulation of the dial is described in (1.1: Frequency)

If the range is in both the positive and negative domains the signed variation is used:

![SoapySDR input plugin GUI](../../../doc/img/SoapySDR_range_neg.png)

If the range applies to a gain a slider is used:

![SoapySDR input plugin GUI](../../../doc/img/SoapySDR_range_gain.png)

<h3>A.2: Discrete range</h3>

Appears with a combo box to select a discrete value:

![SoapySDR input plugin GUI](../../../doc/img/SoapySDR_range_discrete.png)

<h3>A.3: List of ranges</h3>

In this case the range selection combo on the right is enabled:

![SoapySDR input plugin GUI](../../../doc/img/SoapySDR_range_list1.png)

<h3>A.4: Boolean argument</h3>

A checkbox is used to control boolean values:

![SoapySDR input plugin GUI](../../../doc/img/SoapySDR_arg_bool2.png)

For AGC, Auto DC and Auto IQ corrections the checkbox has its text label on the right:

![SoapySDR input plugin GUI](../../../doc/img/SoapySDR_arg_bool1.png)

When set (true) a checkbox is lit in orange:

![SoapySDR input plugin GUI](../../../doc/img/SoapySDR_arg_bool3.png)

<h3>A.5: Int, Float and String arguments</h3>

For all these types of values a line editor is used. Numerical values are parsed from string:

![SoapySDR input plugin GUI](../../../doc/img/SoapySDR_arg_str.png)

<h3>A.6 String lists</h3>

Some parameters like the antenna ports are expressed as a list of possible string values. These are presented in a combo box:

![SoapySDR input plugin GUI](../../../doc/img/SoapySDR_arg_strlist.png)



