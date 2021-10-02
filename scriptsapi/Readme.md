## Python scripts interfacing with the API ##

These scripts are designed to work in Python 3 preferably with version 3.6 or higher. Dependencies are installed with pip in a virtual environment. The sequence of operations is the following:

```
sudo apt-get install virtualenv gcc g++ gfortran python3-dev
virtualenv -p /usr/bin/python3 venv # Create virtual environment
. ./venv/bin/activate               # Activate virtual environment
pip install -r requirements.txt     # Install requirements
```

<h2>freqtracking.py</h2>

This script is used to achieve frequency tracking with the FreqTracker plugin. Ideally you would start it before connecting the Frequency Tracker plugin in rpx-100. It works continuously (daemon style) until stop via Ctl-C.

Options are:

  - `-h` or `--help` show help message and exit
  - `-A` or `--address` listening address (default `0.0.0.0`)
  - `-P` or `--port`  listening port (default `8888`)
  - `-a` or `--address-sdr` rpx-100 REST API address (defaults to calling address)
  - `-p` or `--port-sdr` rpx-100 REST API port (default `8091`)
  - `-f` or `--tracker-frequency` Absolute frequency the tracker should aim at (in Hz optional)
  - `-r` or `--refcorr-limit` Limit of the tracker frequency reference correction. Correction is not apply if error is in this +/- frequency range (Hz, optional, default 1000 Hz)
  - `-d` or `--transverter-device` Transverter device index to use for tracker frequency correction (optional)

With default options (no parameters) it will listen on all available interfaces including loopback at `127.0.0.1` and at port `8888`. It will identify the rpx-100 API address with the first request from rpx-100 and connect back at port `8091`.

Normal sequence of operations:

  - Start `freqtracking.py` in a terminal
  - In rpx-100 connect the Frequency Tracker plugin by clicking on the grey square at the left of the top bar of the Frequency Tracker GUI. It opens the channel settings dialog. Check the 'Reverse API' box. Next to this box is the address and port at which the channel will be connected. If you use the defaults for `freqtracking.py` you may leave it as it is else you have to adjust it to the address and port of `freqtracking.py` (options `-A` and `-P`).
  - In the same manner connect the channel you want to be controlled by `freqtracking.py`. You may connect any number of channels like this. When a channel is removed `freqtracking.py` will automatically remove it from its list at the first attempt to synchronize that will fail.

<h2>ptt_active.py</h2>

PTT (Push To Talk) actively listening system. For a pair of given device set indexes it actively listens to start and stop commands on the corresponding devices to swich over to the other

Options are:

  - `-h` or `--help` show help message and exit
  - `-A` or `--address` listening IP address. Default `0.0.0.0` (all interfaces)
  - `-P` or `--port` listening port. Default `8000`
  - `-p` or `--port-sdr` rpx-100 instance REST API listening port. Default `8091`
  - `-l` or `--link` Pair of indexes of the device sets to link. Default `0 1`
  - `-d` or `--delay` Switch over delay in seconds. Default `1`
  - `-f` or `--freq-sync` Synchronize devices center frequencies

Normal sequence of operations:

In this example we have a Rx device on index 0 and a Tx device on index 1. All settings are assumed to be the default settings.

  - Start `ptt_active.py` in a terminal
  - On the Rx device right click on the start/stop button and activate reverse API at address `127.0.0.1` port `8000` (default)
  - On the Tx device right click on the start/stop button and activate reverse API at address `127.0.0.1` port `8000` (default)
  - Start the Rx or Tx device
  - Stop the running device (Rx or Tx) this will switch over automatically to the other

Important: you should initiate switch over by stopping the active device and not by starting the other.

<h2>qo100_datv.py</h2>

Quick control of configuration for receiving QO-100 DATV to rapidly follow spotted activity on [BATC web sdr](https://eshail.batc.org.uk/wb/)

Options are:
  - `-h` or `--help` show this help message and exit
  - `-a` or `--address` address and port of rpx-100 instance API. Default: 127.0.0.1:8091
  - `-d` or `--device` index of device set. Default 0
  - `-c` or `--channel` index of DATV demod channel. Default 0
  - `-f` or `--frequency` device center frequency (kHz). Mandatory. Ex: 491500
  - `-s` or `--symbol-rate` symbol rate (kS/s). Mandatory. Ex: 1500

<h2>config.py</h2>

Sends a sequence of commands recorded in a JSON file which is in the form of a list of commands.

Options are:

  - `-h` or `--help` show help message and exit
  - `-a` or `--address` address and port of rpx-100 instance. Default is `127.0.0.1:8091`
  - `-j` or `--json-file` JSON file containing description of API commands

Each command in the JSON file is a JSON document with the following keys:

  - `endpoint`: URL suffix (API function) - mandatory
  - `method`: HTTP method (GET, PATCH, POST, PUT, DELETE) - mandatory
  - `params`: pairs of argument and values - optional
  - `payload`: request body in JSON format - optional
  - `msg`: descriptive message for console display - optional
  - `delay`: delay in milliseconds after command - optional

Example of a JSON file (delay is an example you normally do not need it):

```json
[
    {
        "endpoint": "/deviceset/0/device",
        "method": "PUT",
        "payload": {
            "hwType": "HackRF"
        },
        "msg": "Set HackRF on Rx 0"
    },
    {
        "endpoint": "/deviceset/0/device/settings",
        "method": "PUT",
        "payload": {
            "deviceHwType": "HackRF",
            "hackRFInputSettings": {
              "LOppmTenths": 0,
              "bandwidth": 1750000,
              "biasT": 0,
              "centerFrequency": 433800000,
              "dcBlock": 1,
              "devSampleRate": 1536000,
              "fcPos": 2,
              "iqCorrection": 0,
              "lnaExt": 1,
              "lnaGain": 32,
              "log2Decim": 2,
              "reverseAPIAddress": "127.0.0.1",
              "reverseAPIDeviceIndex": 0,
              "reverseAPIPort": 8888,
              "useReverseAPI": 0,
              "vgaGain": 24
            },
            "direction": 0
        },
        "msg": "Setup HackRF on Rx 0"
    },
    {
        "endpoint": "/deviceset/0/channel",
        "method": "POST",
        "payload": {
            "channelType": "RemoteSink",
            "direction": 0
        },
        "msg": "Add a remote sink channel"
    },
    {
        "endpoint": "/deviceset/0/channel/0/settings",
        "method": "PUT",
        "payload": {
            "RemoteSinkSettings": {
              "dataAddress": "192.168.1.5",
              "dataPort": 9094,
              "filterChainHash": 0,
              "log2Decim": 3,
              "nbFECBlocks": 8,
              "reverseAPIAddress": "127.0.0.1",
              "reverseAPIChannelIndex": 0,
              "reverseAPIDeviceIndex": 0,
              "reverseAPIPort": 8888,
              "rgbColor": -7601148,
              "title": "Channel 0",
              "txDelay": 0,
              "useReverseAPI": 0
            },
            "channelType": "RemoteSink",
            "direction": 0
        },
        "msg": "Setup remote sink on channel 0",
        "delay": 1000
    },
    {
        "endpoint": "/deviceset/0/device/run",
        "method": "POST",
        "msg": "Start device on deviceset R0"
    }
]
```
If you have presets defined you may also use presets instead of having to set up the device and channels. In this case you only "PUT" the right device and apply the preset like this:

```json
[
    {
        "endpoint": "/deviceset/0/device",
        "method": "PUT",
        "payload": {
            "hwType": "RTLSDR"
        },
        "msg": "setup RTLSDR on Rx 0"
    },
    {
        "endpoint": "/preset",
        "method": "PATCH",
        "payload": {
            "deviceSetIndex": 0,
            "preset": {
                "groupName": "QO100",
                "centerFrequency": 489675000,
                "type": "R",
                "name": "Narrowband master"
            }
        },
        "msg": "load preset on Rx 0"
    },
    {
        "endpoint": "/deviceset/0/device/run",
        "method": "POST",
        "msg": "Start device on deviceset R0"
    }
]
```

<h2>superscanner.py</h2>

Connects to spectrum server to monitor PSD and detect local PSD hotspots to pilot channel(s). Thus channels can follow band activity. This effectively implements a "scanner" feature with parallel tracking of any number of channels. It is FFT based so can effectively track spectrum hotspots simultaneously. Therefore the "super" superlative.

It requires rpx-100 version 5.6 or above. On rpx-100 instance baseband spectrum should be set in log mode and the spectrum server activated with an accessible address and a port that matches the port given to `superscanner.py`. Please refer to rpx-100 documentation for details.

The script runs in daemon mode and is stopped using `Ctl-C`.

<h3>Options</h3>

  - `-a` or `--address` rpx-100 web base address. Default: `127.0.0.1`
  - `-p` or `--api-port` rpx-100 API port. Default: `8091`
  - `-w` or `--ws-port` rpx-100 websocket spectrum server port. Default: `8887`
  - `-c` or `--config-file` JSON configuration file. Mandatory. See next for format details
  - `-j` or `--psd-in` JSON file containing PSD floor information previously saved with the `-J` option
  - `-J` or `--psd-out` Write PSD floor information to JSON file
  - `-n` or `--nb-passes` Number of passes for PSD floor estimation. Default: `10`
  - `-f` or `--psd-level` Use a fixed PSD floor value therefore do not perform PSD floor estimaton
  - `-X` or `--psd-exclude-higher` Level above which to exclude bin scan during PSD floor estimation
  - `-x` or `--psd-exclude-lower` Level below which to exclude bin scan during PSD floor estimation
  - `-G` or `--psd-graph` Show PSD floor graphs. Requires `matplotlib`
  - `-N` or `--hotspots-noise` Number of hotspots above which detection is considered as noise. Default `8`
  - `-m` or `--margin` Margin in dB above PSD floor to detect acivity. Default: `3`
  - `-g` or `--group-tolerance` Radius (1D) tolerance in points (bins) for hotspot aggregation. Default `1`
  - `-r` or `--freq-round` Frequency rounding value in Hz. Default: `1` (no rounding)
  - `-o` or `--freq-offset` Frequency rounding offset in Hz. Default: `0` (no offset)

Command examples:
  - `python ./superscanner.py -a 127.0.0.1 -p 8889 -w 8886 -c 446M.json -g 10 -r 12500 -o 6250 -J psd_pmr.json`
  - `python ./superscanner.py -a 192.168.0.3 -j psd.json -c 145M.json -g 10 -r 2500`

<h3>Configuration file</h3>

This file drives how channels in the connected rpx-100 instance are managed.

```json
{
    "deviceset_index": 0,           // rpx-100 instance deviceset index addressed - required
    "freqrange_inclusions": [
        [145170000, 145900000]      // List of frequency ranges in Hz to include in processing - optional
    ],
    "freqrange_exclusions": [       // List of frequency ranges in Hz to exclude from processing - optional
        [145000000, 145170000],
        [145290000, 145335000],
        [145800000, 146000000]
    ],
    "channel_info": [               // List of controlled channels - required
        {                           // Channel information - at least one required
            "index": 0,             // Index of channel in deviceset - required
            "fc_pos": "usb",        // Center frequency position in hotspot - optional: default center
                                    // lsb: center frequency at end of hotspot (higer frequency)
                                    // usb: center frequency at beginning of hotspot (lower frequency)
                                    // canter: center frequency at mid-point of hotspot (center frequency)
            "fc_shift": -300        // Center frequency constant shift from computed frequency - optional
        },
        {
            "index": 2
        },
        {
            "index": 3
        }
    ]
}
```

<h3>Run with supervisord</h3>

Refer to supervisord documentation.

Esample of `superscanner.conf` file to put in your `/etc//etc/supervisor/conf.d/` folder (add it in the `[incude]` section of `/etc/supervisor/supervisord.conf`). Environment variable `PYTHONUNBUFFERED=1` is important for the log tail to work correctly.

```
[program:superscanner]
command = /opt/build/rpx-100/scriptsapi/venv/bin/python /opt/build/rpx-100/scriptsapi/superscanner.py -a 192.168.0.24 -c /home/f4exb/145M_scan.config.json -g 4 -r 3125 -f -65
process_name = superscanner
user = f4exb
stopsignal = INT
autostart = false
autorestart = false
environment =
    USER=f4exb,
    PATH="/home/f4exb/bin:/home/f4exb/.local/bin:/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/games:/usr/local/games",
    HOME="/home/f4exb",
    PYTHONUNBUFFERED=1
stdout_logfile = /home/f4exb/log/superscanner.log
stdout_logfile_maxbytes = 10MB
stdout_logfile_backups = 3
redirect_stderr=true
```

<h2>rpx-100.py</h2>

Holds constants related to rpx-100 software required by other scripts

<h2>Unit tests</h2>

Run as `python <file>` in the virtual environment

  - `test_superscanner.py` is testing `superscanner.py`
