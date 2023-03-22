#include <iostream>
#include "consts.hpp"
#include "man/settings.hpp"
#include "man/serial.hpp"

void vs::man::serial::init() {
    if (!en) {
        char port[20] = {0};
        sprintf(port, "\\\\.\\%s", vs::man::settings::smap[vs::man::settings::COMPORTID].c_str());
        shandle = CreateFile(port, GENERIC_WRITE, 0, 0, OPEN_EXISTING, 0, 0);
        if (shandle == INVALID_HANDLE_VALUE) {
            std::cout << "Failed to open port: " << port << std::endl;
            en = false;
            return;
        }
        else {
            std::cout << "Port " << port << " opened" << std::endl;
            en = true;
        }

        DCB sparams = {0};
        sparams.DCBlength = sizeof(sparams);

        GetCommState(shandle, &sparams);
        sparams.BaudRate = std::stoi(vs::man::settings::smap[vs::man::settings::COMBAUDRATE]);
        sparams.ByteSize = std::stoi(vs::man::settings::smap[vs::man::settings::COMBYTESIZE]);
        sparams.StopBits = ONESTOPBIT;
        sparams.Parity   = NOPARITY;
        SetCommState(shandle, &sparams);

        COMMTIMEOUTS timeout = {0};
        timeout.ReadIntervalTimeout = 50;
        timeout.ReadTotalTimeoutConstant = 50;
        timeout.ReadTotalTimeoutMultiplier = 50;
        timeout.WriteTotalTimeoutConstant = 50;
        timeout.WriteTotalTimeoutMultiplier = 10;

        SetCommTimeouts(shandle, &timeout);

        uint8_t buf[vs::gfx::ledcount*3] = {0};
        buf[0] = 255;
        transmit(buf, vs::gfx::ledcount*3);
    }
}

void vs::man::serial::transmit(const uint8_t* buffer, const unsigned bufsize) {
    if (en) {
        WriteFile(shandle, buffer, bufsize, NULL, NULL);
    }
}

void vs::man::serial::transmit(const std::vector<uint8_t>& buffer) {
    if (en) {
        WriteFile(shandle, buffer.data(), buffer.size(), NULL, NULL);
    }
}

void vs::man::serial::disable() {
    if (en) {
        uint8_t  buffer[vs::gfx::ledcount * 3] = {0};
        DWORD    written = 0;
        WriteFile(shandle, buffer, vs::gfx::ledcount * 3, &written, NULL);

        CloseHandle(shandle);
        en = false;
    }
}

bool vs::man::serial::enabled() {
    return en;
}
