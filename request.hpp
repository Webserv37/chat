#ifndef REQUEST_HPP
#define REQUEST_HPP

#include <vector>
#include <utility>
#include <string>
#include <map>
#include <string>
#include <sstream>
#include <fstream>
#include <iostream>
#include <dirent.h>
#include <unistd.h>
#include <algorithm>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <cstring>
#include <cstdlib> 
#include <netdb.h>
#define PORT "8081"
#define ISVALIDSOCKET(s) ((s) >= 0)
#define CLOSESOCKET(s) close(s)
#define SOCKET int
#define GETSOCKETERRNO() (errno)
#define MAX_REQUEST_SIZE 2047
typedef	std::string	string;
typedef	std::vector<string> stringvect;
typedef	std::map<string, stringvect>	mapvect;
typedef	std::map<string, string>	mapstring;
#include "response/response.hpp"
class response;
class Location;
class Server;

class Request {

	public :
		string	method;
		string	path;
		string		_req;
		std::string	http_version;
		Location	_location;
		Server		_server;
		string		_buffer;
		int			_first;
		size_t		_size_to_write;
		size_t		_amount_written;
		int			_fd;
		int			_buffer_state;
		size_t		_file_size;
		std::string host;
		std::string body;
		mapstring headers;
		int socket;
};

#endif