
#include "stdafx.h"

namespace Ctp::Core
{
	//native to clrstr
    String^ U16ToClr(const std::wstring& u16_native_string)
    {
        return msclr::interop::marshal_as<String^>(u16_native_string);
    }

    System::String^ U8ToClr(const std::string& u8_native_string)
    {
        return U16ToClr(utf8_to_w(u8_native_string));
    }

	System::String^ AnsiToClr(const std::string& ansi_native_string)
	{
		return U16ToClr(ansi_to_w(ansi_native_string));
	}

	//clrstr to native
    std::wstring ToNativeU16(String^ clr_string)
    {
        return msclr::interop::marshal_as<std::wstring>(clr_string);
    }

    std::string ToNativeU8(String^ clr_string)
    {
        return w_to_utf8(ToNativeU16(clr_string));
    }

    std::wstring_convert<std::codecvt_utf8<wchar_t>> wcvt_u8;

    std::wstring utf8_to_w(const std::string& u8_str)
    {
        auto u8_size = u8_str.size();
        size_t u16_size = MultiByteToWideChar(CP_UTF8, 0, u8_str.c_str(), u8_size, NULL, 0);
        wchar_t *u16_buffer = new wchar_t[u16_size + 1];
        *(u16_buffer + u16_size) = 0;
        size_t nRtn = MultiByteToWideChar(CP_UTF8, 0, u8_str.c_str(), u8_size, u16_buffer, u16_size);
        std::wstring ret(u16_buffer);
        delete[] u16_buffer;
        return ret;
    }

    std::string w_to_utf8(const std::wstring& w_str)
    {
        return wcvt_u8.to_bytes(w_str);
	}

	std::wstring ansi_to_w(const std::string& ansi_string)
	{
		std::setlocale(LC_ALL, "chs");
		auto unicode_buff_ptr = std::make_unique<wchar_t[]>(ansi_string.length() + 1);
		std::mbstowcs(unicode_buff_ptr.get(), ansi_string.c_str(), ansi_string.length());
		return unicode_buff_ptr.get();
	}

	 

	std::string doubleTostring(double num)
	{
		auto str = std::to_string(num);
		return str;
	}

	std::string ToNativeString(String^ clr_string)
	{
		return  msclr::interop::marshal_as<std::string>(clr_string);
	}
}