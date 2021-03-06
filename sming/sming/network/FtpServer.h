/****
 * Sming Framework Project - Open Source framework for high efficiency native ESP8266 development.
 * Created 2015 by Skurydin Alexey
 * http://github.com/anakod/Sming
 * All files of the Sming Core are provided under the LGPL v3 license.
 ****/

#ifndef _SMING_CORE_FTPSERVER_H_
#define _SMING_CORE_FTPSERVER_H_

#include "TcpServer.h"
#include "../wiring/WHashMap.h"
#include "../wiring/WVector.h"
#include "../wiring/WString.h"

class FTPServerConnection;

class FTPServer: public TcpServer
{
	friend class FTPServerConnection;
public:
	FTPServer();
	virtual ~FTPServer();

	void addUser(String login, String pass);
	bool checkUser(String login, String pass);
	void setFlashDirectory(String reqFlashDirectory);
	String flashDirectory = "";

protected:
	virtual TcpConnection* createClient(tcp_pcb *clientTcp);
	virtual bool onCommand(String cmd, String data, FTPServerConnection& connection);

private:
	HashMap<String, String> users;
};

#endif /* _SMING_CORE_FTPServer_H_ */
