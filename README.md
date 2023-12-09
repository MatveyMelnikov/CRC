# CRC
A simple implementation of crc for communication with an SD card via the spi protocol.

According to the Physical Layer Simplified Specification (Version 9.00, 4.7.2 - command format and 7.2.3 - data read), the CRC occupies the lower six bits of the last byte. In the case of CRC7, the remaining (highest) 5 bytes of data are protected. If CRC16 is used, then all data before the 2 CRC (low-order) bytes is protected.
Examples and checks of calculations are present in the main file.

![изображение](https://github.com/MatveyMelnikov/CRC/assets/55649891/b50417f9-33aa-4945-95b3-4c28bf1fe754)

![изображение](https://github.com/MatveyMelnikov/CRC/assets/55649891/13671b26-7b3c-4051-8aa4-d56e311e3f59)

Examples and checks of calculations are present in the main file.
