/*! \file TODO:
    \author Alvaro Denis Acosta Quesada <denisacostaq@gmail.com>
    \date Wed Mar 19 08:32:25 CDT 2014

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

#ifndef MODBUS_POINT_H
#define MODBUS_POINT_H

#include <string>

class ModbusPoint
{
  public:
    ModbusPoint() = default;
    ~ModbusPoint() = default;

    ModbusPoint(const ModbusPoint&) = delete;
    ModbusPoint& operator=(const ModbusPoint&) = delete;

    ModbusPoint(const ModbusPoint&&) = delete;
    ModbusPoint& operator=(const ModbusPoint&&) = delete;

  private:
    int m_address;
    std::string m_name;
    //m_read_type;
    //m_write_type;
    int m_period;
};

#endif // MODBUS_POINT_H
