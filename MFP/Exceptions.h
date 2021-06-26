/*
Team Abstract Giraffe All-in-One Printer Model
CSC300
July 2015
*/

#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <stdexcept>

class InvalidOutputDevice : public std::runtime_error
{
public:
	InvalidOutputDevice(std::string reason) : runtime_error(reason) {}
};

class NoDocument : public std::runtime_error
{
public:
	NoDocument(std::string reason) : runtime_error(reason) {}
};

class OutOfPaper : public std::runtime_error
{
public:
	OutOfPaper(std::string reason) :runtime_error(reason) {}
};


#endif //EXCEPTIONS_H