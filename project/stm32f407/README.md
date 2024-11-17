### 1. Chip

#### 1.1 Chip Info

Chip Name: STM32F407ZGT6.

Extern Oscillator: 8MHz.

UART Pin: TX/RX PA9/PA10.

IIC Pin: SCL/SDA PB8/PB9.

### 2. Development and Debugging

#### 2.1 Integrated Development Environment

LibDriver provides both Keil and IAR integrated development environment projects.

MDK is the Keil ARM project and your Keil version must be 5 or higher.Keil ARM project needs STMicroelectronics STM32F4 Series Device Family Pack and you can download from https://www.keil.com/dd2/stmicroelectronics/stm32f407zgtx.

EW is the IAR ARM project and your IAR version must be 9 or higher.

#### 2.2 Serial Port Parameter

Baud Rate: 115200.

Data Bits : 8.

Stop Bits: 1.

Parity: None.

Flow Control: None.

#### 2.3 Serial Port Assistant

We use '\n' to wrap lines.If your serial port assistant displays exceptions (e.g. the displayed content does not divide lines), please modify the configuration of your serial port assistant or replace one that supports '\n' parsing.

### 3. AGS10ET

#### 3.1 Command Instruction

1. Show ags10et chip and driver information.

   ```shell
   ags10et (-i | --information)
   ```

2. Show ags10et help.

   ```shell
   ags10et (-h | --help)
   ```

3. Show ags10et pin connections of the current board.

   ```shell
   ags10et (-p | --port)
   ```

4. Run ags10et read test, num means test times. 

   ```shell
   ags10et (-t read | --test=read) [--times=<num>]
   ```

5. Run ags10et read function, num means test times.

   ```shell
   ags10et (-e read | --example=read) [--times=<num>]
   ```

#### 3.2 Command Example

```shell
ags10et -i

ags10et: chip is ASAIR AGS10ET.
ags10et: manufacturer is ASAIR.
ags10et: interface is IIC.
ags10et: driver version is 1.0.
ags10et: min supply voltage is 2.9V.
ags10et: max supply voltage is 3.1V.
ags10et: max current is 33.00mA.
ags10et: max temperature is 85.0C.
ags10et: min temperature is -40.0C.
```

```shell
ags10et -p

ags10et: SCL connected to GPIOB PIN8.
ags10et: SDA connected to GPIOB PIN9.
```

```shell
ags10et -t read --times=3

ags10et: chip is ASAIR AGS10ET.
ags10et: manufacturer is ASAIR.
ags10et: interface is IIC.
ags10et: driver version is 1.0.
ags10et: min supply voltage is 2.9V.
ags10et: max supply voltage is 3.1V.
ags10et: max current is 33.00mA.
ags10et: max temperature is 85.0C.
ags10et: min temperature is -40.0C.
ags10et: start read test.
ags10et: version is 0x0C.
ags10et: ethanol is 2399ppb.
ags10et: ethanol is 2377ppb.
ags10et: ethanol is 2374ppb.
ags10et: resistance is 7411100.00ohm.
ags10et: zero point calibration 0xF6F7.
ags10et: current resistance zero point calibration.
ags10et: reset zero point calibration.
ags10et: modify slave address 0x1A.
ags10et: finish read test.
```

```shell
ags10et -e read --times=3

ags10et: 1/3.
ags10et: ethanol is 2076ppb.
ags10et: 2/3.
ags10et: ethanol is 2067ppb.
ags10et: 3/3.
ags10et: ethanol is 2052ppb.
```

```shell
ags10et -h

Usage:
  ags10et (-i | --information)
  ags10et (-h | --help)
  ags10et (-p | --port)
  ags10et (-t read | --test=read) [--times=<num>]
  ags10et (-e read | --example=read) [--times=<num>]

Options:
  -e <read>, --example=<read>    Run the driver example.
  -h, --help                     Show the help.
  -i, --information              Show the chip information.
  -p, --port                     Display the pin connections of the current board.
  -t <read>, --test=<read>       Run the driver test.
      --times=<num>              Set the running times.([default: 3])
```

