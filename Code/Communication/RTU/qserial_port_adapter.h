/*! \file TODO:
    \author Alvaro Denis Acosta Quesada <denisacostaq@gmail.com>
    \date Thu Mar 20 23:08:14 CDT 2014

    \brief This file become from: TODO

    \attention <h1><center>&copy; COPYRIGHT
    Apache License, Version 2.0, January 2004</center></h1>

    \copyright

    <h3>This file is part of <a href="http://www.TODO:.com"><strong>TODO:</strong></a> program, a TODO:.</h3>
    Copyright [2014] [Alvaro Denis Acosta Quesada]

    Licensed under the Apache License, Version 2.0 (the "License");
    you may not use this file except in compliance with the License.
    You may obtain a copy of the License at

       http://www.apache.org/licenses/LICENSE-2.0

    Unless required by applicable law or agreed to in writing, software
    distributed under the License is distributed on an "AS IS" BASIS,
    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
    See the License for the specific language governing permissions and
    limitations under the License.
 */

#ifndef QSERIAL_PORT_ADAPTER_H
#define QSERIAL_PORT_ADAPTER_H

#include <iostream>

#include <QtSerialPort/QSerialPort>

#include "Communication/comm_adapter_interface.h"
#include "Communication/RTU/serial_port_enums.h"

namespace COMMUNICATION
{
class QSerialPortAdapter : public CommAdapterInterface
{
  public:
    QSerialPortAdapter(SERIAL_PORT::BaudRate baudrate,
                       SERIAL_PORT::DataBits databits,
                       SERIAL_PORT::Parity parity,
                       SERIAL_PORT::StopBits stop_bits,
                       SERIAL_PORT::FlowControl flow_control);

    CommErrorCode connect(int32_t timeout) override;
    CommErrorCode disconnect(int32_t timeout) override;
    CommErrorCode read(int timeout, char *data, int *n_bytes) override;
    CommErrorCode write(int timeout, const char *data, int *n_bytes) override;
};
}
#endif // QSERIAL_PORT_ADAPTER_H
