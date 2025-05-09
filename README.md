# Sim Racing Setup Display

## Features

- 

## Getting Started

### Hardware Requirements

- 

### Software Requirements

- [**Platform IO**](https://platformio.org/install/ide?install=vscode): Used for programming the ATmega32u4 microcontroller.

### Software Installation and Setup

> You can use the pre compiled hex file. Or you compile it yourself.

1. **Install PlatformIO**:
- Follow the [installation guide](https://platformio.org/install) to set up PlatformIO in your preferred environment (VSCode, Atom, etc.).

2. **Clone the Repository**:

```sh
git clone https://github.com/lusmdl/MySimRacingCore.git
```

3. **Open the Project**:
- Open the cloned repository folder in your PlatformIO environment.

4. **Build and Upload**:
- Connect your Arduino.
- Build and upload the code using PlatformIO:

```sh
pio run --target upload
```


### Hardware Setup

To get started, you’ll need to assemble the LCD shiled and connect GND, TWI (2 Wire) to the I²C Master.

## Documentation
- **Software**: [doc/software/html/index.html](/doc/software/html/index.html)

## Contributing

We welcome contributions from the community!

First, read the [general contributing conventions for projects from me](CONTRIBUTING.md).

1. Fork the repository.
2. Create a new branch (`git checkout -b feature-branch`).
3. Commit your changes (`git commit -am 'Add new feature'`).
4. Push to the branch (`git push origin feature-branch`).
5. Create a new Pull Request.

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.
