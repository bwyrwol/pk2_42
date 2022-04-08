#ifndef UTILITY_H
#define UTILITY_H

#include <iostream>
#include <ctime>

#define __FILENAME__ (strrchr(__FILE__,'\\')+1)

#ifdef _DEBUG
#define __DEBUG_INFO__(info) do {\
									std::clog << ">>>> file " << __FILENAME__ \
                                                              << ": fun "\
                                                              << __FUNCTION__ \
                                                              << ": line " \
                                                              << __LINE__ \
                                                              << ": " << info << std::endl; \
						        } while(0)
#else
#define __DEBUG_INFO__(info) {}
#endif//_DEBUG

#define __SEPARATOR__(...) UtilitySeparator(__VA_ARGS__)

void UtilityGetTime(tm & time);
void UtilitySeparator(char c, int cnt = 40);


#endif//UTILITY_H