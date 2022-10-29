#ifndef LOGGER_H
#define LOGGER_H

#include <iostream>

#if !defined(OSTREAM)
#define OSTREAM std::cout
#endif // ! OSTREAM

#define LOG_BASE(os, level, msg)                                   \
    do {                                                           \
        os << "[GaryGame][" << level << "]" << msg << std::endl;   \
    } while (0)

#ifdef ENABLE_DEBUG_LOG
#define LOG_D(msg)  LOG_BASE(OSTREAM, "DEBUG", msg)
#else 
#define LOG_D(msg) 
#endif // ENABLE_DEBUG_LOG

#ifdef ENABLE_INFORMATION_LOG
#define LOG_I(msg)  LOG_BASE(OSTREAM, "INFO", msg)
#else 
#define LOG_I(msg) 
#endif // ENABLE_INFORMATION_LOG

#ifdef ENABLE_ERROR_LOG
#define LOG_E(msg)  LOG_BASE(OSTREAM, "ERROR", msg)
#else 
#define LOG_E(msg) 
#endif // ENABLE_ERROR_LOG

#endif // !LOGGER_H