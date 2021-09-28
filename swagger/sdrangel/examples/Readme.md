## Examples of client scripts ##

These are all Python scripts using python-requests so you have to install this package as a prerequisite either with your package manager or pip. Some scripts work with Python 3 while others are still with Python 2.7.

<h2>add_channel.py</h2>

Adds a channel to a device set specifying device set index and channel type.

  - Operation ID: `devicesetChannelPost`
  - URI: `/sdrangel/deviceset/{deviceSetIndex}/channel`
  - HTTP method: `POST`

<h2>config.py</h2>

Configure a SDRangel instance with a sequence of API calls defined as a list in a JSON file. See `test.json` for an example.

It uses the following APIs:

  - To select a device in a device set:
    - Operation ID: `devicesetDevicePut`
    - URI: `/sdrangel/deviceset/{deviceSetIndex}/device`
    - HTTP method: `PUT`
  - To load a preset in a device set:
    - Operation ID: `instancePresetPatch`
    - URI: `/sdrangel/preset`
    - HTTP method: `PATCH`
  - To create a new device set:
    - OperationID: `instanceDeviceSetPost`
    - URI: `/sdrangel/deviceset`
    - HTTP method: `POST`
  - Activate the DV serial dongle support for digital voice modes
    - OperationID: `instanceDVSerialPatch`
    - URI: `/sdrangel/dvserial`
    - HTTP method: `PATCH`
  - Start a device streaming
    - OperationID: `devicesetDeviceRunPost`
    - URI: `/sdrangel/deviceset/{deviceSetIndex}/device/run`
    - HTTP method: `POST`

<h2>limesdr_tx.py</h2>

Create a Tx device set with a LimeSDR Tx device and a NFM modulator channel configured to send some beacon Morse code. Then starts the Tx.

It uses the following APIs:

  - To create a new device set:
    - OperationID: `instanceDeviceSetPost`
    - URI: `/sdrangel/deviceset`
    - HTTP method: `POST`
  - To select a device in a device set:
    - Operation ID: `devicesetDevicePut`
    - URI: `/sdrangel/deviceset/{deviceSetIndex}/device`
    - HTTP method: `PUT`
  - To create a new channel:
    - Operation ID: `devicesetChannelPost`
    - URI: `/sdrangel/deviceset/{deviceSetIndex}/channel`
    - HTTP method: `POST`
  - To change the settings of a channel:
    - OperationID: `devicesetChannelSettingsPatch`
    - URI: `/sdrangel/deviceset/{deviceSetIndex}/channel/{channelIndex}/settings`
    - HTTP method: `PATCH`
  - Start a device streaming
    - OperationID: `devicesetDeviceRunPost`
    - URI: `/sdrangel/deviceset/{deviceSetIndex}/device/run`
    - HTTP method: `POST`

<h2>nfm_test.py</h2>

Example of creating NFM channels (demodulator and modulator) and changing the settings

It uses the following APIs:

  - To create a new channel:
    - Operation ID: `devicesetChannelPost`
    - URI: `/sdrangel/deviceset/{deviceSetIndex}/channel`
    - HTTP method: `POST`
  - To create a new device set:
    - OperationID: `instanceDeviceSetsPost`
    - URI: `/sdrangel/devicesets`
    - HTTP method: `POST`
  - To change the settings of a channel:
    - OperationID: `devicesetChannelSettingsPatch`
    - URI: `/sdrangel/deviceset/{deviceSetIndex}/channel/{channelIndex}/settings`
    - HTTP method: `PATCH`

<h2>ptt_active.py</h2>

Handles the switchover between two arbitrary device sets
  - Both device sets should have the reverse API feature set with the address and port of this server
  - Once in place and you have started one of the devices you should only stop one or the other never start. There are two reasons for this:
    - This module reacts on an action already taken so if you start Tx then the Rx is not stopped immediately and damage to the Rx could occur. If you start with a stop action you cannot get in this situation.
    - For half duplex devices (only the HackRF) it will lock Tx or Rx. You can always recover the situation by stopping the running side.
  - There is no assumption on the Rx or Tx nature you may as well switchover 2 Rx or 2 Tx
  - Both devices have not to belong to the same physical device necessarily. You could mix a RTL-SDR Rx and a HackRF Tx for example

Depends on `flask` and `requests`: to install do `pip install flask requests` in your virtual environment.

<h2>ptt.py</h2>

Implements a basic push to talk (PTT) feature. Verifies that devise set #0 is a Rx and that #1 is a Tx. Stops streaming on one device and start streaming on the other depending on the PTT move (Rx to Tx or Tx to Rx).

It uses the following APIs:

  - Get information on device sets:
    - Operation ID: `instanceDeviceSetsGet`
    - URI: `/sdrangel/devicesets`
    - HTTP method: `GET`
  - Start a device streaming
    - OperationID: `devicesetDeviceRunPost`
    - URI: `/sdrangel/deviceset/{deviceSetIndex}/device/run`
    - HTTP method: `POST`
  - Stop a device streaming
    - OperationID: `devicesetDeviceRunDelete`
    - URI: `/sdrangel/deviceset/{deviceSetIndex}/device/run`
    - HTTP method: `DELETE`

<h2>randomize_colors.py</h2>

Randomize channel colors for a specified device set

It uses the following APIs:

  - Get information on a device set
    - Operation ID: `devicesetGet`
    - URI: `/sdrangel/deviceset/{deviceSetIndex}`
    - HTTP method: `GET`
  - To get the settings of a channel:
    - OperationID: `devicesetChannelSettingsGet`
    - URI: `/sdrangel/deviceset/{deviceSetIndex}/channel/{channelIndex}/settings`
    - HTTP method: `GET`
  - To change the settings of a channel:
    - OperationID: `devicesetChannelSettingsPatch`
    - URI: `/sdrangel/deviceset/{deviceSetIndex}/channel/{channelIndex}/settings`
    - HTTP method: `PATCH`

<h2>reverseapi.py</h2>

This script runs continuously to act as the server side of SDRangel reverse API feature. It will respond with a copy of the settings when forwarding channel or device settings which is a valid reply and will also send back a valid reply when forwarding the device start/stop actions. The reverse API feature was implemented in version 4.3.2 and you can learn more about it in the Wiki.

It uses Python flask package for the server so you will need to either install it system wide or better create your own virtual environment and use the `pip install flask` command once your virtual environment is activated. If you know Python then you know what a virtual environment is about.

Then in the virtual environment do:

```
export FLASK_APP=reverseapi.py
export FLASK_ENV=development
flask run
```
By default the server will listen on port 5000. It was used to conveniently test the reverse API but actually does not do much. It can serve as a base to implement more complex scenarios to control other devices or software or other instances of SDRangel.

<h2>rtlsdr_settings.py</h2>

Make sure a RTLSDR device is selected on device set #0. Get and change the settings of this RTLSDR device.

It uses the following APIs:

  - Get information on a device set:
    - Operation ID: `devicesetGet`
    - URI: `/sdrangel/deviceset/{deviceSetIndex}`
    - HTTP method: `GET`
  - To select a device in a device set:
    - Operation ID: `devicesetDevicePut`
    - URI: `/sdrangel/deviceset/{deviceSetIndex}/device`
    - HTTP method: `PUT`
  - To get the settings of a device:
    - OperationID: `devicesetDeviceSettingsGet`
    - URI: `/sdrangel/deviceset/{deviceSetIndex}/device/settings`
    - HTTP method: `GET`
  - To change the settings of a device:
    - OperationID: `devicesetDeviceSettingsPatch`
    - URI: `/sdrangel/deviceset/{deviceSetIndex}/device/settings`
    - HTTP method: `PATCH`

<h2>rx_test.py</h2>

Sets specified Rx in existing source device set or create a new source device set with this Rx. Adds an NFM demodulator channel.

It uses the following APIs:

  - Create a new device set:
    - Operation ID: `devicesetPost`
    - URI: `/sdrangel/deviceset`
    - HTTP method: `POST`
  - Get information on a device set:
    - Operation ID: `devicesetGet`
    - URI: `/sdrangel/deviceset/{deviceSetIndex}`
    - HTTP method: `GET`
  - To select a device in a device set:
    - Operation ID: `devicesetDevicePut`
    - URI: `/sdrangel/deviceset/{deviceSetIndex}/device`
    - HTTP method: `PUT`
  - To get the settings of a device:
    - OperationID: `devicesetDeviceSettingsGet`
    - URI: `/sdrangel/deviceset/{deviceSetIndex}/device/settings`
    - HTTP method: `GET`
  - To change the settings of a device:
    - OperationID: `devicesetDeviceSettingsPatch`
    - URI: `/sdrangel/deviceset/{deviceSetIndex}/device/settings`
    - HTTP method: `PATCH`
  - To create a new channel:
    - Operation ID: `devicesetChannelPost`
    - URI: `/sdrangel/deviceset/{deviceSetIndex}/channel`
    - HTTP method: `POST`
  - To get the settings of a channel:
    - OperationID: `devicesetChannelSettingsGet`
    - URI: `/sdrangel/deviceset/{deviceSetIndex}/channel/{channelIndex}/settings`
    - HTTP method: `GET`
  - To change the settings of a channel:
    - OperationID: `devicesetChannelSettingsPatch`
    - URI: `/sdrangel/deviceset/{deviceSetIndex}/channel/{channelIndex}/settings`
    - HTTP method: `PATCH`
  - Start a device streaming
    - OperationID: `devicesetDeviceRunPost`
    - URI: `/sdrangel/deviceset/{deviceSetIndex}/device/run`
    - HTTP method: `POST`

<h2>rx_tx_test.py</h2>

Combines `rx_test` and `tx_test` to create a pair of source and sink device sets. The APIs used are the same as in `rx_test` or `tx_test`.

<h2>scanner.py</h2>

Simple AM and NFM scanner with multiple equally spaced channels. Stops whenever any of the channels squelch opens. At the moment the following sampling devices can be used:

  - AirspyHF
  - HackRF
  - LimeSDR
  - RTLSDR

Check `./scanner.py --help` for the options.

Requires numpy

&#9758; Try to first run with the `-m` (mock) option to see what the scanner parameters will be. In particular pay attention to the computed sample rate that should be within range for your hardware. For devices with fixed or discrete rates make sure the computed sample rate does not exceed the unique device sample rate or the highest possible sample rate.

In addition to some APIs being used in other script it uses:

  - Get channels reports:
    - Operation ID: `devicesetChannelsReportGet`
    - URI: `/sdrangel/deviceset/{deviceSetIndex}/channels/report`
    - HTTP method: `GET`

<h2>start_stop.py</h2>

Starts or stops a device in the specified device set

It uses the following APIs:

  - Get information on device sets:
    - Operation ID: `instanceDeviceSetsGet`
    - URI: `/sdrangel/devicesets`
    - HTTP method: `GET`
  - Start a device streaming
    - OperationID: `devicesetDeviceRunPost`
    - URI: `/sdrangel/deviceset/{deviceSetIndex}/device/run`
    - HTTP method: `POST`
  - Stop a device streaming
    - OperationID: `devicesetDeviceRunDelete`
    - URI: `/sdrangel/deviceset/{deviceSetIndex}/device/run`
    - HTTP method: `DELETE`

<h2>stop_server.py</h2>

This works with a server instance only i.e. `sdrangelsrv`. It will shutdown the instance nicely as you would do with the exit menu or Ctl-Q in the GUI application.

It uses this API:

  - Stop a server instance
    - OperationID: `instanceDelete`
    - URI: `/sdrangel`
    - HTTP method: `DELETE`

<h2>tx_test.py</h2>

Sets specified Tx in existing sink device set or create a new sink device set with this Tx. Adds an NFM modulator channel.

It uses the following APIs:

  - Create a new device set:
    - Operation ID: `devicesetPost`
    - URI: `/sdrangel/deviceset`
    - HTTP method: `POST`
  - Get information on a device set:
    - Operation ID: `devicesetGet`
    - URI: `/sdrangel/deviceset/{deviceSetIndex}`
    - HTTP method: `GET`
  - To select a device in a device set:
    - Operation ID: `devicesetDevicePut`
    - URI: `/sdrangel/deviceset/{deviceSetIndex}/device`
    - HTTP method: `PUT`
  - To get the settings of a device:
    - OperationID: `devicesetDeviceSettingsGet`
    - URI: `/sdrangel/deviceset/{deviceSetIndex}/device/settings`
    - HTTP method: `GET`
  - To change the settings of a device:
    - OperationID: `devicesetDeviceSettingsPatch`
    - URI: `/sdrangel/deviceset/{deviceSetIndex}/device/settings`
    - HTTP method: `PATCH`
  - To create a new channel:
    - Operation ID: `devicesetChannelPost`
    - URI: `/sdrangel/deviceset/{deviceSetIndex}/channel`
    - HTTP method: `POST`
  - To get the settings of a channel:
    - OperationID: `devicesetChannelSettingsGet`
    - URI: `/sdrangel/deviceset/{deviceSetIndex}/channel/{channelIndex}/settings`
    - HTTP method: `GET`
  - To change the settings of a channel:
    - OperationID: `devicesetChannelSettingsPatch`
    - URI: `/sdrangel/deviceset/{deviceSetIndex}/channel/{channelIndex}/settings`
    - HTTP method: `PATCH`
  - Start a device streaming
    - OperationID: `devicesetDeviceRunPost`
    - URI: `/sdrangel/deviceset/{deviceSetIndex}/device/run`
    - HTTP method: `POST`
