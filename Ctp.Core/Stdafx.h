
#pragma once

#include "ctp_native/ThostFtdcTraderApi.h"
#include "ctp_native/ThostFtdcMdApi.h"

#pragma comment (lib, "ctp_native/thostmduserapi.lib")
#pragma comment (lib, "ctp_native/thosttraderapi.lib")

#include <codecvt>
#include <string>
#include <msclr/marshal_cppstd.h>
#include <clocale>

namespace Ctp::Core
{
    using namespace System;

	String^ AnsiToClr(const std::string& ansi_native_string);

    String^ U8ToClr(const std::string& u8_native_string);

    String^ U16ToClr(const std::wstring& u16_native_string);

    std::wstring ToNativeU16(String^ clr_string);

    std::string ToNativeU8(String^ clr_string);

    std::wstring utf8_to_w(const std::string& utf8_str);

    std::string w_to_utf8(const std::wstring& w_str);

	std::wstring ansi_to_w(const std::string& ansi_string);


	std::string doubleTostring(double num);

	std::string ToNativeString(String^ clr_string);
}