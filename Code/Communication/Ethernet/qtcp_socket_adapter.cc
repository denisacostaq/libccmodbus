/*! \file TODO:
    \author Alvaro Denis Acosta Quesada <denisacostaq@gmail.com>
    \date Tue Mar 18 23:30:39 CDT 2014

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

#include "qtcp_socket_adapter.h"
namespace COMMUNICATION
{
  QTcpSocketAdapter::QTcpSocketAdapter(QString remot_server, int remot_server_port)
    : m_server{remot_server},
        m_server_port{remot_server_port},
        m_socket{}
  {
  }

  CommErrorCode QTcpSocketAdapter::connect(int timeout)
  {
    m_socket.connectToHost(m_server, m_server_port);
    if (m_socket.waitForConnected(timeout))
    {
      return CommErrorCode::Ok;
    }
    else
    {
      qDebug() << m_socket.errorString();
      switch (m_socket.error())
      {
        case QAbstractSocket::SocketError::ConnectionRefusedError:
          return CommErrorCode::connecFail;
          break;
        case QAbstractSocket::SocketError::TemporaryError:
          return CommErrorCode::timeout;
          break;
        default:
          break;
      }
      return CommErrorCode::unknownError;
    }
  }
}  //namespace COMMUNICATION
