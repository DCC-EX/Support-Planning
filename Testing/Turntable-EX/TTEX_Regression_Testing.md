# Turntable-EX Regression Testing Process

The regression testing process is to be completed prior to any new release of Turntable-EX.

## Preparation

The CommandStation used to for this testing must be running the [add-turntable-controller](https://github.com/DCC-EX/CommandStation-EX/tree/add-turntable-controller) branch of release version 4.0.1.

In addition, the included myAutomation.h and myHal.cpp files must be included with the software uploaded to the CommandStation.

### Hardware Requirements

- CommandStation-EX with wireless and EX-RAIL support.
- An Arduino Nano/Uno configured as per the Turntable-EX documentation with a supported stepper driver, motor, and homing sensor.
- A suitable config.h file configured as per the Turntable-EX documentation, with the only configuration change being the appropriate stepper driver to suit the supported hardware in use.
- LEDs for validating the LED and accessory outputs.
- A phone or tablet running Engine Driver (A full WiThrottle app supporting ROUTEs will also work).

## Outputs

Outputs of each step are to be recorded... somewhere?

## Testing Process

Ensure Turntable-EX is correctly connected via the I2C bus to the CommandStation, then power on Turntable-EX first, followed by the CommandStation, ensuring both are connected via serial, with serial console opened to both.

### Startup, Homing, and Calibration Tests

On startup, use the serial console of Turntable-EX to validate the version, and note if steps have been stored previously in EEPROM or not:

```
License GPLv3 fsf.org (c) dcc-ex.com
Turntable-EX version X.X.X
```

If calibration has been completed previously, you should see:

```
Turntable-EX has been calibrated for XXXX steps per revolution
```

Otherwise:

```
Turntable-EX has not been calibrated yet
```



### Validate Turntable-EX is Online

In the serial console of the CommandStation, execute `<D HAL SHOW>` and ensure the output is as displayed:

```
<D HAL SHOW><* Arduino Vpins:2-69 *>
<* PCA9685 I2C:x40 Configured on Vpins:100-115 OFFLINE *>
<* PCA9685 I2C:x41 Configured on Vpins:116-131 OFFLINE *>
<* MCP23017 I2C:x20 Configured on Vpins:164-179 OFFLINE *>
<* MCP23017 I2C:x21 Configured on Vpins:180-195 OFFLINE *>
<* TurntableEX I2C:x60 Configured on Vpins:600-600  *>
<* LCD3:Free RAM= 2412b *>
```
