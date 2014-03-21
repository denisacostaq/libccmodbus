/*! \file serial_portrs_232.h
    \author Alvaro Denis Acosta Quesada <denisacostaq@gmail.com>
    \date Tue Mar 18 19:55:16 CDT 2014

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

#ifndef COMMUNICATION_RTU_SERIAL_PORTRS_232_H
#define COMMUNICATION_RTU_SERIAL_PORTRS_232_H

#include "Communication/comm_interface.h"
#include "Communication/RTU/qserial_port_adapter.h"

namespace COMMUNICATION
{
class SerialPortRS_232 : public CommInterface
{
  public:
    SerialPortRS_232(SERIAL_PORT::BaudRate baudrate,
                     SERIAL_PORT::DataBits databits,
                     SERIAL_PORT::Parity parity,
                     SERIAL_PORT::StopBits stop_bits,
                     SERIAL_PORT::FlowControl flow_control);
    ~SerialPortRS_232() = default;

    SerialPortRS_232(const SerialPortRS_232&) = delete;
    SerialPortRS_232& operator=(const SerialPortRS_232&) = delete;

    SerialPortRS_232(const SerialPortRS_232&&) = delete;
    SerialPortRS_232& operator=(const SerialPortRS_232&&) = delete;

    inline CommErrorCode connect(int timeout) override {
      return m_serial_port->connect(timeout);
    }

    inline CommErrorCode disconnect(int timeout) override {
      return m_serial_port->disconnect(timeout);
    }

    inline CommErrorCode read(int timeout, char *data, int *n_bytes) override {
      return m_serial_port->read(timeout, data, n_bytes);
    }

    inline CommErrorCode write(int timeout, const char *data, int *n_bytes) override {
      return m_serial_port->write(timeout, data, n_bytes);
    }

  private:
    CommAdapterInterface *m_serial_port;
};
}  //namespace COMMUNICATION
#endif // COMMUNICATION_RTU_SERIAL_PORTRS_232_H
