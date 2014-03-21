/*! \file TODO:
    \author Alvaro Denis Acosta Quesada <denisacostaq@gmail.com>
    \date Thu Mar 20 10:27:32 CDT 2014

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

#include "modbus_client.h"

namespace PROTOCOL {
  ModbusClient::ModbusClient(char *host, u_int16_t host_port)    
    : m_transport{new COMMUNICATION::TcpSocket{host, host_port}}
  {
  }

  ModbusClient::ModbusClient(SERIAL_PORT::BaudRate baudrate,
                             SERIAL_PORT::DataBits databits,
                             SERIAL_PORT::Parity parity,
                             SERIAL_PORT::StopBits stop_bits,
                             SERIAL_PORT::FlowControl flow_control)
    : m_transport{new COMMUNICATION::SerialPortRS_232{baudrate,
                                                      databits,
                                                      parity,
                                                      stop_bits,
                                                      flow_control}}
  {
  }
}
