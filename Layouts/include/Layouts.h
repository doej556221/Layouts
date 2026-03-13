
/**
 * \file Layouts.h
 * \~english @brief File for project functions
 * \~english @details
 * This file contains general project functions
 * \~russian @brief Файл функций проекта
 * \~russian @details
 * Этот файл содержит общие функции проекта
 */

#ifndef LAYOUTS_HEADER
#define LAYOUTS_HEADER

#ifdef _WINDOWS

#ifdef LAYOUTS_EXPORTS
#define LAYOUTS_API __declspec(dllexport)
#else
#define LAYOUTS_API __declspec(dllimport)
#endif

#else

#ifdef LAYOUTS_EXPORTS
#define LAYOUTS_API __attribute__((visibility("default")))
#else
#define LAYOUTS_API
#endif

#endif

class LAYOUTS_API CLayouts {
public:
	CLayouts(void);
};

extern LAYOUTS_API int nLayoutsVersion;
LAYOUTS_API int LayoutsVersion(void);

namespace Layouts
{
	/*!
		\class LayoutPolicy
		\brief Ориентация размещения
		\details
		Ориентация, с которой размещение упорядочивает свое содержимое
	*/
	enum Orientation
	{
		Horizontal,
		Vertical
	};

	/*!
		\class LayoutPolicy
		\brief Политика размещения
		\details
		Политика, которую размещение требует для размещения своего содержимого
	*/
	enum LayoutPolicy
	{
		Fixed, ///< Фиксированный размер
		Minimal, ///< Минимальный размер
		Preferred, ///< Предпочтительный
		Stretched ///< Растянутый
	};
}

#endif

