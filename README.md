# Welcome SCP Example

This is an extended fork of the ESP-IDF "hello_world" example.

Starts a FreeRTOS task to print some useful info and blink 2 user LEDs.


## Folder contents

The project **scp_welcome** contains one source file in C language [scp_welcome_main.c](main/scp_welcome_main.c). The file is located in folder [main](main).

###This project is based on the release/v4.4 branch of the ESP-IDF.

ESP-IDF projects are built using CMake. The project build configuration is contained in `CMakeLists.txt` files that provide set of directives and instructions describing the project's source files and targets (executable, library, or both). 

Below is short explanation of remaining files in the project folder.

```
├── CMakeLists.txt
├── main
│   ├── CMakeLists.txt
│   └── scp_welcome_main.c
└── README.md                  This is the file you are currently reading
```

For more information on structure and contents of ESP-IDF projects, please refer to Section [Build System](https://docs.espressif.com/projects/esp-idf/en/latest/esp32/api-guides/build-system.html) of the ESP-IDF Programming Guide.

## Troubleshooting

* Program upload failure

    * Hardware connection is not correct: run `idf.py -p PORT monitor`, and reboot your board to see if there are any output logs.
    * The baud rate for downloading is too high: lower your baud rate in the `menuconfig` menu, and try again.

## Technical support and feedback

Please use the following feedback channels:

* For technical queries concerning ESP32 and toolchain, go to the [esp32.com](https://esp32.com/) forum
* For a feature request or bug report, create a [GitHub issue](https://github.com/espressif/esp-idf/issues)
* For questions regarding Telic Sensor2Cloud Platform hardware contact [Telic support](mailto://support@telic.de)

We will get back to you as soon as possible.
